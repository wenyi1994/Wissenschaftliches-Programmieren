#include "complex.h"
#include <iostream>
#include <fstream>

using namespace std;

int IsConvergency(MyComplex z0, int exp, MyComplex c, double rc, int N_max)
{
    MyComplex z_temp = z0;
    for (int i = 0; i < N_max; i++)
    {
        z_temp = (z_temp ^ exp) + c;
        if (z_temp.norm()>=rc) return i;
    }
    return N_max;
}

void calcu(int Iter_num, double value_l_real, double value_l_imag, double value_r_real, double value_r_imag, 
            int Nxmax, int Nymax, int exp, int N_max, double rc, char filename[], double c_real, double c_imag)
{
    char file[256];
    sprintf(file,"%s",filename);
    ofstream calc_output;

    double dx = (value_r_real - value_l_real) / Nxmax;
    double dy = (value_r_imag - value_l_imag) / Nymax;

    calc_output.open(file);

    switch(Iter_num)
    {
        case 1:
        {
            MyComplex c(c_real, c_imag);
            for(int i = 0; i<=Nxmax; i++)
            {
                for(int j = 0; j<=Nymax; j++)
                {
                    MyComplex z0(double(i)*dx + value_l_real, double(j)*dy + value_l_imag);
                    calc_output<<i<<" "<<j<<" "<<IsConvergency(z0, exp, c, rc, N_max)<<endl;
                }
                calc_output<<endl;
            }
            break;
        }
        case 2:
        case 3:
        {
            MyComplex z0(c_real, c_imag);
            for(int i = 0; i<=Nxmax; i++)
            {
                for(int j = 0; j<=Nymax; j++)
                {
                    MyComplex c(double(i)*dx + value_l_real, double(j)*dy + value_l_imag);
                    calc_output<<i<<" "<<j<<" "<<IsConvergency(z0, exp, c, rc, N_max)<<endl;
                }
                calc_output<<endl;
            }
            break;
        }
    }
    calc_output.close();
}

int main()
{
    int Iter_num;
    double value_l_real, value_l_imag, value_r_real, value_r_imag;
    int Nxmax, Nymax, exp, N_max;
    double rc;
    char filename[256];
    double c_real, c_imag;

    cout<<"input number of iteration process"<<endl;
    cin>>Iter_num;
    cout<<"input start value and end value of complex"<<endl;
    cin>>value_l_real>>value_l_imag>>value_r_real>>value_r_imag;
    cout<<"input Nxmax and Nymax"<<endl;
    cin>>Nxmax>>Nymax;
    cout<<"input exponent"<<endl;
    cin>>exp;
    cout<<"input Nmax"<<endl;
    cin>>N_max;
    cout<<"input convergency radius"<<endl;
    cin>>rc;
    cout<<"input output filename"<<endl;
    cin>>filename;
    cout<<"input start value of c / z"<<endl;
    cin>>c_real>>c_imag;

    calcu(Iter_num, value_l_real, value_l_imag, value_r_real, value_r_imag, Nxmax, Nymax, exp, N_max, rc, filename, c_real, c_imag);

    return 0;
}