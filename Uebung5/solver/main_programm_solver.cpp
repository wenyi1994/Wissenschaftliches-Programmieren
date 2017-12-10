#include <iostream>
#include <fstream>

#include "vector_funcs.h"
#include "matrix_funcs.h"
#include "solver_funcs.h"

using namespace std;


void write_vector_to_file(Vector const &sol,string filename){

  ofstream file(filename.c_str());
  int nsize(sol.size());

  for(int i=0;i<nsize;++i)
    file<<i<<" "<<sol(i)<<endl;

  file.close();
};




int main(int argc, char* argv[]){

    const int dim = 2;


    // ------- define LGS A*x = b -------
    // hier muessen Sie die Matrix A, sowie die Vektoren b und x erstellen
    // Verwenden Sie die Variable dim, um die Konstruktoren aufzurufen
    // ----------------------------------

    Matrix A(dim,dim);
    A(0,0) = 3.;    A(0,1) = 1.;
    A(1,0) = 1.;    A(1,1) = 6.;
    A.print();
    
    Vector b(dim), x(dim);
    b(0) = +2.;
    b(1) = -8.;
    b.print("b");
    
    // ----------------------------------
    // 1. CG solver
    // ----------------------------------
    cout << "=== CG solver: ===" << endl; 
    // definiere Startwert phi0 fuer CG-Iteration
    Vector x0(dim);
    x0(0) = 1.;	x0(1) = 1.;
    // rufe cg_solve auf
    x = cg_solve ( x0, A, b );
    // output: A,b,x
    b.print("b");
    x.print("x:");

    // ueberpruefe die Loesung 

    (A*x).print("[A*x]");

    write_vector_to_file(x,"cg_test.dat");

    // ----------------------------------


    // ----------------------------------
    // 2. LU solver
    // ----------------------------------

    cout << "=== LU solver: ===" << endl;
    
    Matrix A2(A);
    
    Vector x2 = lu_solve(A2,b);
    
    x2.print("x2");
    
    write_vector_to_file(x2,"lu_test.dat");

    
    // ----------------------------------
    // Aufgabe 3: Waermeleitproblem
    // ----------------------------------

    cout << "=== Waermeleitproblem: ===" << endl;


    double T_0, T_L, T_e, k, L;
    // Dirichlet Randbedingungen am Anfang T_0 und Ende T_L des Stabes
    // diese Knoten müssen später besonders behandelt werden

    cout<<"Eingabe der Temperaturen T_0, T_L und T_e: "<<endl;
    cin>>T_0>>T_L>>T_e;

    cout<<"Waermeleitkoeffizient k: "<<endl;
    cin>>k;

    cout<<"Stablaenge L: "<<endl;
    cin>>L;

    int  M; //Anzahl der Stuetzstellen (Diskretisierung)
    cout<<"Anzahl der Stuetzstellen M: "<<endl;
    cin>>M;

    double const h = L/double(M-1); //Schrittweite

    double const c = h*h/k; //h^2/k

    //Aufstellen LGS: A_w*x_w = b_w
    //Anlegen der notwenigen Vektoren und Matrix

    Vector x_w(M);
    Vector b_w(M);
    Matrix A_w(M, M);

    Vector a_w(M); //Hilfsvariable a_w(i) = i^2*h^2/L^2;

    //TODO: Initialisierung a_w
    for(int i = 0; i<M; i++)
    {
      a_w(i) = ((double)i) * ((double)i) * h * h / L / L;
    }

    //TODO: Initialisierung A_w
    A_w = 0;

    //TODO: Kopplungsterme in Matrix schreiben: nur "innere Knoten werden betrachtet
    for(int i = 1; i<M-1; i++)
    {
      A_w(i,i-1) = 1.0;
      A_w(i,i) = a_w(i)*c - 2.0;
      A_w(i,i+1) = 1.0;
    }

    //TODO: Knoten 0 und Knoten M-1 : Randbedingung werden eingebaut
    A_w(0,0) = a_w(0) * T_e * c / T_0;
    A_w(M-1,M-1) = a_w(M-1) * T_e * c / T_L;
    // A_w(0,0) = 1;
    // A_w(M-1,M-1) = 1;
    // A_w(0,1) = ( b_w(0) - T_0 ) / b_w(1);
    // A_w(M-1,M-2) = ( b_w(M-1) - T_L ) / b_w(M-2);

    //TODO: A_w muss symmetrisch sein: Anpassen der Matrix A_w und rechten Seite b_w
    for(int i = 0; i<M; i++)
    {
      b_w(i) = a_w(i) * T_e * c;
    }
    // A_w(0,1) = b_w(0) - T_0

    //TODO: Anfangswerte x_w0 (best guess): z.B. lineare Interpolation
    Vector x_w0(M);
    for(int i = 0; i<M; i++)
    {
      x_w0(i) = T_0 * double(M-1-i) / double(M-1) + T_L * double(i) / double(M-1);
    }

    cout<<"A_w"<<endl;
    x_w0.print("x_w0");
    A_w.print();
    b_w.print("b_w");

    //TODO: Loesung mit CG-Solver:
    cout<<"----Loesung mit CG-Solver:----"<<endl;
    x_w = cg_solve(x_w0, A_w, b_w);
    x_w.print("x_w");
    (A_w*x_w).print("A_w * x_w");

    write_vector_to_file(x_w, "CG_waermeleit.dat");

    //TODO: Loesung mit LU-Solver:
    cout<<"----Loesung mit LU-Solver:----"<<endl;
    x_w = lu_solve(A_w, b_w);
    x_w.print("x_w");
    (A_w*x_w).print("A_w * x_w");

    write_vector_to_file(x_w, "LU_waermeleit.dat");

    return 0;
}
