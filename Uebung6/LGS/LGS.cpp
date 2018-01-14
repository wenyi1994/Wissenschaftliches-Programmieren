#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>

#include "vector_funcs.h"
#include "matrix_funcs.h"
#include "solver_funcs.h"

using namespace std;

void eingeben(int n_gitter, double k_ausser, string filename, Vector p_liegt)
{
    string usename = filename + "Eingabe.dat";
    ofstream file(usename.c_str());

    file<<"==========Eingabe=========="<<endl;
    file<<"Groesse des Gitters: "<<n_gitter<<endl;
    file<<"Externe kraft:       "<<k_ausser<<endl;
    file<<"Liegt auf Knoten:    "<<endl;
    for(int i=0;i<n_gitter;i++)
    {
        for(int j=0;j<n_gitter;j++)
        {
            if(p_liegt(i*n_gitter+j)>0) file<<setw(4)<<"◼";
            else file<<setw(4)<<"◻";
        }
        file<<endl;
    }

    file.close();
}
void ausgeben(int n_gitter, Vector u, string filename)
{
    string usename = filename + "Ausgabe.dat";
    ofstream file(usename.c_str());

    file<<setw(12)<<"# i"<<setw(12)<<"j"<<setw(12)<<"u"<<endl;

    for(int i=0;i<n_gitter;i++)
    {
        for(int j=0;j<n_gitter;j++)
        {
            file<<setw(12)<<i<<setw(12)<<j<<setw(12)<<u(i*n_gitter+j)<<endl;
        }
    }

    file.close();
}

Vector kraft_auf_knoten(int n_gitter)
{
    cout<<"-----Externe Kraft auf welcher Knoten liegt----"<<endl;
    for(int i=0;i<n_gitter;i++)
    {
        for(int j=0;j<n_gitter;j++)
        {
            cout<<setw(5)<<i*n_gitter+j;
        }
        cout<<endl;
    }
    cout<<"         (Nummer des Knotens eingeben)"<<endl;
    cout<<"    (\"-1\" fuer alle Knoten, \"-2\" zu beenden)"<<endl;
    // int *p = new int[n_gitter*n_gitter];
    Vector p(n_gitter*n_gitter);
    p = 0;
    int temp=0;
    for(int i=0;i<n_gitter*n_gitter;i++)
    {
        cin>>temp;
        if(temp == -1)
        {
            p = 1;
            break;
        }
        if(temp == -2) break;
        p(temp) = 1;
    }
    for(int i=0;i<n_gitter;i++)
    {
        for(int j=0;j<n_gitter;j++)
        {
            if(p(i*n_gitter+j)>0) cout<<setw(4)<<"◼";
            else cout<<setw(4)<<"◻";
        }
        cout<<endl;
    }
    return p;
}

string gettime()
{
    time_t nowtime;
    nowtime=time(0);
    char tmp[80];
    strftime(tmp,sizeof(tmp),"%Y%m%d_%H%M%S_",localtime(&nowtime));
    string str_tmp = tmp;
    return str_tmp;
}

Matrix alloMat(Matrix &M,Vector p_liegt)
{   
    Matrix tempM(M.rows()*M.rows(),M.cols()*M.cols());
    int c_p = p_liegt.size();
    tempM = 0;
    for(int i=0;i<c_p;i++)
    {
        if(p_liegt(i)<1) continue;
        int temp_x = i/M.cols();
        int temp_y = i%M.cols();
        tempM(i,i) = 4;
        if(temp_x>0) tempM(i,i-M.cols()) = -1;
        if(temp_x<M.rows()-1) tempM(i,i+M.cols()) = -1;
        if(temp_y>0) tempM(i,i-1) = -1;
        if(temp_y<M.cols()-1) tempM(i,i+1) = -1;
    }
    return tempM;
}

int main()
{
    string runtime=gettime();
    int n_gitter;
    double kraft;
    cout<<"----------Groesse des Gitters eingeben----------"<<endl;
    cin>>n_gitter;
    Matrix M(n_gitter,n_gitter);
    M = 0; // initialization
    cout<<"-------------Externe Kraft eingeben------------"<<endl;
    cin>>kraft;
    Vector f(n_gitter*n_gitter);
    f = kraft;
    Vector p = kraft_auf_knoten(n_gitter);
    Matrix M_Symmetrisch = alloMat(M,p);
    Matrix M_backup = M_Symmetrisch;
    eingeben(n_gitter,kraft,runtime,p);
    // Vector u0(n_gitter*n_gitter);
    // u0 = 0;
    Vector u = lu_solve(M_backup,f);
    // Vector u = cg_solve(u0,M_backup,f);
    ausgeben(n_gitter,u,runtime);
    return 0;
}