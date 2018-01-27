#include <iostream>
#include <cmath>
#include "particle.h"
using namespace std;

int **lc;  // linked cell
int *ll;   // linked list
int nmax[dim]; // Anzahl der Unterteilungen in x und y Richtung
double rc[dim]; //rcut off in die jeweilige Berechnung, da L[] 
                // nicht notwendigerweise ein vielfaches von rcut ist







// (i) initialisiert die cut off parameter in beiden Dimensionen
// (ii) Speicher für das Feld lc und den Veclor lc wird belegt

void init_linked_list(const double L[], const double rcut,const int ntot){
  for(int i=0;i<dim;i++){
    nmax[i]=int(floor(L[i]/rcut));
    rc[i]=L[i]/nmax[i];
  }
    
  cout<<"nmax:"<<nmax[0]<<","<<nmax[1]<<endl;
  cout<<"rcut:"<<rcut<<":"<<rc[0]<<","<<rc[1]<<endl;
    
  ll = new int[ntot]; // für jedes Atom wird ein Eintrag benötigt
  lc = new int*[nmax[0]];
  lc[0]= new int[(nmax[0])*(nmax[1])]; // siehe 2d Feld Initialisierung
  for(int i=1;i<nmax[0];i++) // Pointer Arithmetik
    lc[i]=lc[0]+i*(nmax[1]);
  //
  for(int i=0;i<ntot;i++)
    ll[i]=-1;
  for(int i=0;i<nmax[0];i++)
    for(int j=0;j<nmax[1];j++)
      lc[i][j]=-1;
    
}

// Aufbau der Nachbarschaftlisten
void setup_neighbour_list(const particle *p, const int ntot){
  for(int i=0;i<ntot;i++)
    ll[i]=-1;
  for(int i=0;i<nmax[0];i++)
    for(int j=0;j<nmax[1];j++)
      lc[i][j]=-1;

  {// Aufbau der Listen: 
    int nidx[dim];
    for(int i=0;i<ntot;i++){
      for(int n=0;n<dim;n++){
	nidx[n]=int(floor(p[i].pos[n]/rc[n]));
	nidx[n]=min(nidx[n],nmax[n]-1); // Bereichsprüfung
	nidx[n]=max(nidx[n],0);  
      }
	    
      ll[i] = lc[nidx[0]][nidx[1]];
      lc[nidx[0]][nidx[1]]=i;
    }
	
  }    
}

// zur Information
void print_neighour_list(){
  int n;
  for(int i=0;i<nmax[0];i++){
    for(int j=0;j<nmax[1];j++){
      if(lc[i][j]!=-1){
	n=lc[i][j];
	cout<<"Zelle i,j:"<<i<<","<<j<<endl;
	while(n!=-1){
	  cout<<" "<<n<<endl;
	  n=ll[n];
	}
      }
      else{
	cout<<"keine Atome in Zelle i,j: "<<i<<","<<j<<endl;	
      }
    }
  }
}



// Kräfteberechnung mit Nachbarschaftslisten: offene Ränder

void force_calculation_neighbour(particle *p, const int ntot,
				 void force(particle *p1, particle *p2)){
  // * die Nachbarn der Zelle (i,j) lassen sich mit den Offsets ndx,ndy erreichen
  // * dabei ist zu beachten, dass actio=reactio in die Berechnung eingeht
  int ndx[]={1,1,0,-1};       //      [3](i-1,j+1)-- [2](i,j+1) --[1](i+1,j+1) 
  int ndy[]={0,1,1,1};        //                        (i,j)   --[0](i+1,j)
  int n1,n2,nx,ny;
  // Kraft auf Null setzen:
  for(int i=0;i<ntot;i++)
    for(int n=0;n<dim;n++)
      p[i].f[n]=0;
    
  // neue Kraft berechnen
  for(int i=0;i<nmax[0];i++){
    for(int j=0;j<nmax[1];j++){
      if(lc[i][j]!=-1){
	n1=lc[i][j];
	//	cout<<"Zelle i,j:"<<i<<","<<j<<endl;
	while(n1!=-1){
	  n2=ll[n1];
	  while(n2!=-1){
	    force(&p[n1],&p[n2]);
	    n2=ll[n2];
	  }
		    
	  // Nachbarzellen
	  for(int no=0;no<4;no++){
	    nx=i+ndx[no];
	    ny=j+ndy[no];
		      
	    // Randbedigungen:
	    if(nx<0) continue; // geht ans Ende der Schleife...
	    if(nx>nmax[0]-1) continue;
	    if(ny<0) continue;
	    if(ny>nmax[1]-1) continue;
	    n2=lc[nx][ny];
	    while(n2!=-1){
	      force(&p[n1],&p[n2]);
	      n2=ll[n2];
	    }
	  }
	  n1=ll[n1];
	}
      }
    }
  }
}

