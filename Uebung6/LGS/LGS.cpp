#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>

#include "vector_funcs.h"
#include "matrix_funcs.h"
#include "solver_funcs.h"

using namespace std;

void eingeben(int n_gitter, double k_ausser, string filename, Vector p_liegt, int n_solver)
{
    string usename = filename + "Eingabe.dat";
    ofstream file(usename.c_str());

    file<<"==========Eingabe=========="<<endl;
    file<<"Groesse des Gitters: "<<n_gitter<<endl;
    file<<"Externe kraft:       "<<k_ausser<<endl;
    file<<"Solver:       ";
    switch(n_solver)
    {
        case 1:
        file<<"LU-Solver"<<endl; break;
        case 2:
        file<<"CG-Solver"<<endl; break;
        case 3:
        file<<"GS-Solver"<<endl; break;
        case 4:
        file<<"CH-Solver"<<endl; break;
    }
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
    int n_solver;
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
    cout<<"-----------------Solver waehlen----------------"<<endl;
    cout<<"            1. LU-Dekomposition-Solver         "<<endl;
    cout<<"            2. CG-Verfahren-Solver             "<<endl;
    cout<<"            3. Gauss-Seidel-Solver             "<<endl;
    cout<<"            4. Cholesky-Dekomposition-Solver   "<<endl;
    cin>>n_solver;
    eingeben(n_gitter,kraft,runtime,p,n_solver);
    Vector u(n_gitter*n_gitter);
    Vector u0(n_gitter*n_gitter);
    u0 = 0;
    switch(n_solver)
    {
    case 1:
        u = lu_solve(M_backup,f);
        break;
    case 2:
        u = cg_solve(u0,M_backup,f);
        break;
    case 3:
        u = gs_solve(u0,M_backup,f);
        break;
    case 4:
        u = ch_solve(M_backup,f);
        break;
    }
    ausgeben(n_gitter,u,runtime);
    // Matrix M(3,3);
    // M(0,0)=1; M(0,1)=2; M(0,2)=3;
    // M(1,0)=4; M(1,1)=5; M(1,2)=6;
    // M(2,0)=7; M(2,1)=8; M(2,2)=9;
    // M.print();
    // M.transpose().print();
    return 0;
}