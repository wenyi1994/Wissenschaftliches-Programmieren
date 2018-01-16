#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "particle.h"
#include "verlet.h"
using namespace std;

//globale Variablen:

particle *Teilchen;
size_t ntot;

// Deklarationen:

void init_structure(string);
void force_calculation(particle*const,const int ntot);
void euler_dynamics(particle*const , const int ntot,const double dt);
void ergebnis(const particle*const , const int ntot,const double time,ofstream &);
// Energie berechnen
void energy(const particle*const, const int ntot, const double time, ofstream &);

// Hauptprogramm:

int main(){
    string filename;
    string ergfile;
    ofstream ergebnisdatei,energydatei;
    int nchoice;
    double time,time_max,dt;
    // Eingabe:
    cout<<"Anfangsbedingungen der Teilchen in Datei: ";
    cin >> filename;
    cout<<"Name fuer Ergebnisdatei: ";
    // f�r Ausgabe:
    cin >> ergfile;
    string enfile = "en_"+ergfile;
    ergebnisdatei.open(ergfile.c_str(),ios::out);
    energydatei.open(enfile.c_str(),ios::out);
    
    // Einlesen der Anfangsstruktur:
    init_structure(filename);
 
    // Simulationsparameter:
    cout<< "zu simulierende Zeitspanne:";
    cin >> time_max;
    cout<< "Zeitschritt dt:";
    cin >> dt;
    
    cout<<"Euler (1) oder Verlet (2) Integration: ";
    do{
	cin >>nchoice;
    }while(nchoice<1 || nchoice>2);
    
    
    time=0;
    if(nchoice==1) {
	//EULER:
	while(time<time_max){
	    time+=dt;
	    force_calculation(Teilchen,ntot);
	    euler_dynamics(Teilchen,ntot,dt);
	    ergebnis(Teilchen,ntot,time,ergebnisdatei);
        energy(Teilchen,ntot,time,energydatei);
	}
    }
    else if(nchoice==2) {
	//Verlet: Geschwindigkeits-St�rmer-Verlet
	init_verlet(Teilchen,ntot);
	while(time<time_max){
	    time+=dt;
	    update_positions(Teilchen,ntot,dt);
	    force_calculation(Teilchen,ntot);
	    update_velocities(Teilchen,ntot,dt);
	    ergebnis(Teilchen,ntot,time,ergebnisdatei);
        energy(Teilchen,ntot,time,energydatei);
	}
    }
    
    ergebnisdatei.close();
    energydatei.close();
    return 0;
}

// Definition der Funktionen


//Euler Integration:

void euler_dynamics(particle *const p,const int nmax,const double dt){
    for(int i=0;i<nmax;i++){
	// Position:
	for(int n=0;n<dim;n++){
	    p[i].pos[n]+=p[i].vel[n]*dt;
	}
	// Geschwindigkeit:
	for(int n=0;n<dim;n++){
	    p[i].vel[n]+=p[i].f[n]/p[i].m*dt;
	}
    }   
}

// Kraftberechnung zwischen zwei Teilchen: actio-reactio ber�cksichtigen
// Potenzial: -m1*m2*r_i/r3
void force_p1p2(particle *const p1, particle *const p2){
    double r[dim],f[dim];
    double r2;
    double fs;
    
    for(int i=0;i<dim;i++)
	r[i]=p2->pos[i]-p1->pos[i];
    //Abstandsquadrat:
    r2=0.;
    for(int i=0;i<dim;i++)
	r2+=r[i]*r[i];
    //force: skalarer Anteil:
    fs=p1->m*p2->m/(sqrt(r2)*r2);
    //Vektorieller Anteil
    for(int i=0;i<dim;i++){
	f[i]=fs*r[i];
	p1->f[i]+=f[i];
	p2->f[i]-=f[i];
    }
} 

// Kraftberechnung: einfachste Methode Ausf�hren einer Doppelsumme
// unter Ber�cksichtigung von actio=reaktio

void force_calculation(particle *const Teilchen,const int nmax){
    
    // setze alle Kr�fte auf Null:
    for(int i=0;i<nmax;i++)
	for(int n=0;n<dim;n++)
	    Teilchen[i].f[n]=0.;
    
    for(int i=0;i<nmax-1;i++){
	for(int j=i+1; j<nmax;j++){
	    // actio=reactio miteingebaut: 
            // d.h. nur die H�lfte der Indexpaare (i,j)
	    // muss ber�cksichtihgt werden.
	    force_p1p2(&Teilchen[i],&Teilchen[j]);
	}
    }
}

// Einlesen der Startstruktur mit Anfangsbedingungen 
// (Geschwindigkeit)

void init_structure(string filename){
    size_t n;
    ifstream Datei;
    
    Datei.open(filename.c_str(),ios::in);
    
    if(Datei) {
	n=0;
	Datei >> ntot;
	cout<<ntot<<endl;
	Teilchen = new particle[ntot];
	while(n<ntot){
	    // Struktur einlesen: f�r dim=2 geschrieben 
	    // (Verallgemeinerung: �bung)
	    Datei >>Teilchen[n].m >> Teilchen[n].pos[0]
		  >>Teilchen[n].pos[1]>>Teilchen[n].vel[0]
		  >>Teilchen[n].vel[1];
	    n++;
	}
    }
    Datei.close();
    
}



// OUTPUT Datei:

void ergebnis(const particle *const p,const int nmax,const double time,
	      ofstream &OUT){
    
    OUT<<time<<" ";
    for(int i=0;i<nmax;i++){
	for(int n=0;n<dim;n++)
	    OUT<<p[i].pos[n]<<" ";
	for(int n=0;n<dim;n++)
	    OUT<<p[i].vel[n]<<" ";
    }
    OUT<<endl;
}

void energy(const particle * const p, const int nmax, const double time, ofstream & file)
{
    file<<time<<" ";
    double e=0.;
    
    for(int i=0;i<nmax;i++)
    {
        double e_kinetic = 0.;
        double e_potenzial = 0.;
        double v2 = 0.;
        double r2 = 0.;
        for(int n=0;n<dim;n++)
        {
            v2 += p[i].vel[n]*p[i].vel[n];
        }
        e_kinetic = 0.5*p[i].m*v2;
        for(int j=0;j<nmax;j++)
        {
            if(j==i) continue;
            r2 = 0.;
            for(int n=0;n<dim;n++)
            {
                r2 += (p[i].pos[n]-p[j].pos[n])*(p[i].pos[n]-p[j].pos[n]);
            }
            e_potenzial -= p[i].m*p[j].m/sqrt(r2);
        }
        file<<i<<" "<<e_kinetic<<" "<<e_potenzial<<" "<<e;
    }
    file<<endl;
}





