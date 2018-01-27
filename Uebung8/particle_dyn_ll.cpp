#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "particle.h"
#include "verlet.h"
#include "linked_list.h"
#include "interaction_lj.h"
using namespace std;

//globale Variablen:

particle *Teilchen;
size_t ntot;

// Deklartationen:
void init_structure(string);
void force_calculation(particle*,const int ntot,void force(particle*const ,particle*const));
void euler_dynamics(particle*, const int ntot,const double dt);
void write_structure(particle *p,const int nmax,const int nstep);
// Hauptprogramm:
//  ! length in units of [sigma]
//  ! energy in units of [eps]
//  ! force in units of [eps/sigma]
//  ! mass in units if [m]
//  ! time in units of [sigma sqrt(m/eps)]
//  ! velocity in units of [sqrt(sigma/m)]

int main(){
    string filename;
    int nchoice;
    int nstep;
    //Zeitintervall:
    double time,time_max,dt;
    // Gr��e der Simulationsbox, Shift und Gitterkosntante:
    double L[dim],XOFF[dim],gitter_konstante;
    // Abschneideradius f�r  LJ 
    double rcut;
    // Eingabe: 
    cout<<"Anfangsbedingungen der Teilchen in Datei: ";
    cin >> filename;
    cout<<"Box: Lx,Ly Einheit[a] (a: Gittekonstante)"<<endl;
    cin>>L[0]>>L[1];
    cout<<"Offset:";
    cin>>XOFF[0]>>XOFF[1];
    cout<<"Gitterkonstante a [sigma]:";
    cin>>gitter_konstante;
    cout<<"Abschneideradius [sigma]:";
    cin>>rcut;
    
    // Einlesen der Anfangsstruktur:
    init_structure(filename);
    
    // Simulationsparameter:
    cout<< "zu simulierende Zeitspanne:";
    cin >> time_max;
    cout<< "Zeitschritt dt:";
    cin >> dt;
    
    // Skalierung der Geometrie mit Gitterkonstanten:
    for(int i=0;i<ntot;i++){
	for(int j=0;j<dim;j++){
	    Teilchen[i].pos[j]+=XOFF[j];
	    Teilchen[i].pos[j]*=gitter_konstante;
	}
    }
    L[0]*=gitter_konstante;
    L[1]*=gitter_konstante;
    
    // Vorbereitung: Nachbarschaftsliste:
    init_linked_list(L,rcut,ntot);
    print_neighour_list();
    setup_neighbour_list(Teilchen,ntot);
    print_neighour_list();
    
    cout<<"1: Euler (1)"<<endl;
    cout<<"2: Verlet/einfach:"<<endl;
    cout<<"3: Verlet/linked list:"<<endl;
    do{
	cin >>nchoice;
    }while(nchoice<1 || nchoice>3);
    
    // Hauptteil:
    
    time=0;
    nstep=0;
    
    if(nchoice==3) {
	// Verlet Verfahren mit Nachbarschaftslisten
	init_verlet(Teilchen,ntot);
	while(time<time_max){
        cout<<"time: "<<time<<"/"<<time_max<<endl;
	    setup_neighbour_list(Teilchen,ntot);
	    time+=dt;
	    update_positions(Teilchen,ntot,dt);
	    force_calculation_neighbour(Teilchen,ntot,force_lj);
	    update_velocities(Teilchen,ntot,dt);
	    write_structure(Teilchen,ntot,nstep);
	    nstep++;
	}
    } // REST f�r andere Verfahren
    else if(nchoice==1) {
	//EULER:
	while(time<time_max){
        cout<<"time: "<<time<<"/"<<time_max<<endl;
	    time+=dt;
	    force_calculation(Teilchen,ntot,force_lj);
	    euler_dynamics(Teilchen,ntot,dt);
	    update_velocities(Teilchen,ntot,dt);
	    write_structure(Teilchen,ntot,nstep);
	    nstep++;
	}
    }
    else if(nchoice==2) {
	//Verlet: Geschwindigkeits-St�rmer-Verlet
	init_verlet(Teilchen,ntot);
	while(time<time_max){
        cout<<"time: "<<time<<"/"<<time_max<<endl;
	    time+=dt;
	    update_positions(Teilchen,ntot,dt);
	    force_calculation(Teilchen,ntot,force_lj);
	    update_velocities(Teilchen,ntot,dt);
	    write_structure(Teilchen,ntot,nstep);
	    nstep++;
	}
    }
    
    return 0;
}

// Definition der Funktionen


//Euler Integration:

void euler_dynamics(particle *p,const int nmax,const double dt){
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


// Kraftberechnung: einfachste Methode Ausf�hren einer Doppelsumme
// unter Ber�cksichtigung von actio=reaktio

void force_calculation(particle *Teilchen,const int nmax,
		       void force_p1p2(particle *const p1,particle *const p2)){
    double f[dim];
    
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
    int n;
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

void write_structure(particle *p,const int nmax,const int nstep){
    char Dateiname[256];
    ofstream Datei;
    
    
    
    sprintf(Dateiname,"lattice%d.dat",nstep);
    // �ffnen der Datei: String in Form f�r open(..) Methode bringen
    Datei.open(Dateiname);
    
    // Teilcheninformationen in Datei schreiben:
    for (int i=0;i<ntot; i++){
	Datei<< 1.<<" "; // Einheitsmasse
	Datei <<p[i].pos[0] <<" "<<p[i].pos[1]<<" "
	      <<p[i].vel[0] <<" "<<p[i].vel[1]<<endl;
    }
    Datei.close(); // Datei schliessen


}







