#include <iostream>
#include <cstdio>
#include <vector>
#include "polymorph_funcs.h" 



using namespace std;



/**
 * Referenz auf Basisklasse
 * @param b
 */
void irgendeine_andere_funktion ( BaseClass & b ) 
{
    b.some_function();
}




int main(int argc, char* argv[]){

    // Man kann kein Objekt vom Typen BaseClass erzeugen,
    // weil die Klasse 'purely virtual' Funktionen enthaelt!

    cout << "1) =====================" << endl;
    Derived_A A;
    irgendeine_andere_funktion ( A );

    cout<<endl;
    cout << "2) =====================" << endl;

    Derived_B B;
    irgendeine_andere_funktion ( B );

    cout<<endl;
    cout << "3) =====================" << endl;


    A.just_a_function();
    B.just_a_function();

    cout<<endl;
    cout << "4) =====================" << endl;



    /* ... man kann also in der BaseClass eine Form vorgeben
       (= jede konkret abgeleitete Klasse MUSS die purely virtual function
          implementieren). 
       Alle Implementierungsdetails können später gemacht werden.
       Polymorphism ist, dass obwohl oben der Argumenttyp die BaseClass ist,
       wird jeweils die richtige 'some_function()' aufgerufen - je nach
       übergebenen Objekt (A oder B)! 

       Das ist ein sehr nützliches, leider etwas kompliziertes C++ Feature...
    */

    vector< BaseClass* > vec;

    cout<<"====================CTR BLOCK==============================="<<endl;
    vec.push_back(new Derived_A);
    vec.push_back(new Derived_B);
    vec.push_back(new Derived_A);
    vec.push_back(new Derived_B);
    cout<<endl;
    cout<<"=================Aufruf mit Ptr============================="<<endl;
    for(int i=0;i<vec.size();++i){
        vec[i]->some_function();
        cout<<endl;
        cout<<"==================="<<endl;
    }
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    for(int i=0;i<vec.size();++i){
            vec[i]->another_function();
            cout<<endl;
            cout<<"+++++++++++++++++++"<<endl;
        }
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    for(int i=0;i<vec.size();++i){
            vec[i]->just_a_function();
            cout<<endl;
            cout<<"-------------------"<<endl;
        }




    cout<<"end of program:***************************************!!!!"<<endl;
    // Ausgabe auf Konsole betrachten:
    // wieso gibt es hier noch weitere Ausgaben??


    return 0;
}
