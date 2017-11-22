#include "functions_game.h"

MatrixXi create_field2d(unsigned int nx,unsigned int ny){
	return MatrixXi::Zero(nx,ny);
}

void init_field2d(MatrixXi &field, const double frac){
	const unsigned int nx=field.rows();
	const unsigned int ny=field.cols();
	double countd=frac*(double)nx*(double)ny;
	int count=(int)countd;
	for(int i=0;i<count;i++)
	{
		const unsigned int index_x=rand()%nx;
		const unsigned int index_y=rand()%ny;
		if(field(index_x,index_y)==1)
		{
			i--;
			continue;
		}
		field(index_x,index_y)=1;
	}
}
void make_step(MatrixXi & field,MatrixXi  & field_tmp){
	const unsigned int nx=field.rows();
	const unsigned int ny=field.cols();
	int sum=0;
	for(int i=0;i<nx;i++)
	{
		for(int j=0;j<ny;j++)
		{
			sum=field((i-1+nx)%nx,(j-1+ny)%ny)+field((i-1+nx)%nx,(j+ny)%ny)+field((i-1+nx)%nx,(j+1+ny)%ny)+
					field((i+nx)%nx,(j-1+ny)%ny)+field((i+nx)%nx,(j+1+ny)%ny)+
					field((i+1+nx)%nx,(j-1+ny)%ny)+field((i+1+nx)%nx,(j+ny)%ny)+field((i+1+nx)%nx,(j+1+ny)%ny);
			if(field(i,j)==0 && sum==3)
			{
				field_tmp(i,j)=1;
			}
			else if(field(i,j)==1)
			{
				switch(sum)
				{
				case 0:
				case 1:
				{
					field_tmp(i,j)=0; break;
				}
				case 2:
				case 3:
				{
					field_tmp(i,j)=1; break;
				}
				default:
				{
					field_tmp(i,j)=0; break;
				}
				}
			}
			else
			{
				field_tmp(i,j)=0;
			}
		}
	}
	field=field_tmp;
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

