/*
 * main_game.cpp

 *
 *  Created on: Nov 17, 2015
 *      Author: andreast
 */
#include <iostream>
#include "functions_game.h"


using namespace std;


int main(){
  
  unsigned int nZeile,nSpalte,nstep,nplot;
  double frac;
  
  
  cout<<" Einlesen der Systemgroesse nZeile,nSpalte: ";
  cin >>nZeile>>nSpalte;
  
  cout<<"Anteil besetzt :";
  cin >> frac;
  
  cout<<"Wieviele Zeitschritte: ";
  cin >> nstep;
  
  cout<<"Ausgabe jedes n ten Schrittes: n= ";
  cin >> nplot;
  
  
  // 2d Matrix erzeugen
  
  MatrixXi field2d, field2d_tmp;
  
  field2d = create_field2d(nZeile,nSpalte);
  
  field2d_tmp = create_field2d(nZeile,nSpalte);
  
  // 2d Feld initialisieren
  
  init_field2d(field2d,frac);
  
  
  field2d_tmp = field2d;
  plot_field(field2d,0);
  
  // führe nstep Zeitschritte durch:
  int count = 0;
  for(unsigned int i = 0;i < nstep; i++){
    //cout<<" nstep: "<<i<<" (max nstep: "<<nstep<<")"<<endl;
    
    make_step(field2d, field2d_tmp);
    
    
    if ( i%nplot==0){
      count ++;
      plot_field(field2d,count);
    }
  };
  
  return(0);
}

