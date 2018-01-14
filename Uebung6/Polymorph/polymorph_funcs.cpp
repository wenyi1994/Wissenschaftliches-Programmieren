#include <iostream>
#include "polymorph_funcs.h"



using namespace std;


BaseClass::BaseClass()
{
    cout << "in BaseClass: Constructor" << endl;
}



BaseClass::~BaseClass()
{
    cout << "in BaseClass: Destructor" << endl;
}

void BaseClass::another_function(){
    cout<<"in BaseClass: another function"<<endl;
}

void BaseClass::just_a_function(){
    cout<<"in BaseClass: just a function called"<<endl;
}
// --------------------------------------------------



Derived_A::Derived_A()
    : BaseClass()  // <-- das ist eine "Initialisierungsliste"
                   // bei Vererbung muss der CTOR der Basisklasse
                   // so aufgerufen werden!
{
        cout << "... in Derived_A: Constructor" << endl;
}



Derived_A::~Derived_A()
{
    cout << "... in Derived_A: Destructor" << endl;
}



void Derived_A::some_function()
{
    cout << "... in Derived_A: some_function" << endl;
}

void Derived_A::another_function(){
    cout <<" ... in Derived_A: another_function"<<endl;
}


void Derived_A::just_a_function(){
    cout<<".... in Derived_A: just_a_function"<<endl;
}


// --------------------------------------------------
Derived_B::Derived_B()
    : BaseClass() 
{
        cout << "... in Derived_B: Constructor" << endl;
}



Derived_B::~Derived_B()
{
    cout << "... in Derived_B: Destructor" << endl;
}



void Derived_B::some_function()
{
    cout << "... in Derived_B: some_function" << endl;
}
