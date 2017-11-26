#include "functions_game.h"

MatrixXi create_field2d(unsigned int nx,unsigned int ny){

  MatrixXi field=MatrixXi::Zero(nx,ny);
  return field;
}

void init_field2d(MatrixXi &field, const double frac){

  srand(time(NULL));

  int count = 0;
  int todo_fill;
  int rand_x, rand_y;
  
  const unsigned int nx = field.rows();
  const unsigned int ny = field.cols();
  
  todo_fill = int(nx*ny*frac); //Anzahl der zu fuellenden Felder
  
  while(count < todo_fill){
    
    rand_x = rand()%nx;
    rand_y = rand()%ny;
    if(field(rand_x,rand_y) != 1){
      
      field(rand_x,rand_y) = 1;
      count++;
    }
  }
}
void make_step(MatrixXi & field,MatrixXi  & field_tmp){
  
  int n_neigh;
  
  const unsigned int nx = field.rows();
  const unsigned int ny = field.cols();
  
  for(int i = 0; i<nx; i++){
    for(int j = 0; j<ny; j++){
      
      //alle 8 Nachbarn checken:
      n_neigh =   int(field((i-1+nx)%nx,j))+
	int(field((i+1)%nx,j))+
	int(field(i,(j-1+ny)%ny))+
	int(field(i,(j+1)%ny))+
	int(field((i-1+nx)%nx,(j-1+ny)%ny))+
	int(field((i-1+nx)%nx,(j+1)%ny))+
	int(field((i+1)%nx,(j-1+ny)%ny))+
	int(field((i+1)%nx,(j+1)%ny));
      
      if(field(i,j) == 1){
	
	
	switch(n_neigh){
	case(2): break;
	case(3): break;
	default: field_tmp(i,j) = 0;
	}
      }
      else{
	if(n_neigh == 3){
	  
	  field_tmp(i,j)= 1;
	}
      }
    }
  }
  
  field = field_tmp;
}

void plot_field(MatrixXi const & field, const unsigned int nstep){
  char Dateiname[256];
  ofstream Datei;
  
  const unsigned int nx = field.rows();
  const unsigned int ny = field.cols();
  
  
  sprintf(Dateiname,"field%d.dat",nstep);
  Datei.open(Dateiname);
  for(int i = 0;i<nx;i++){
    for(int j=0;j<ny;j++){
      Datei<<i<<" "<<j<<" "<<field(i,j)<<endl;
    }
    Datei<<endl;
  }
  Datei.close();
}

