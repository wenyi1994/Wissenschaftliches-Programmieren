/*
 * vector_funcs.cpp
 *
 *
 *
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstddef>
#include <cassert>

#include "vector_funcs.h"

using namespace std;

//Constructor
Vector::Vector ( const std::size_t dim ){

  this->N = dim;
  this->dataPtr = new double[dim];
};

//Copy-Constructor
Vector::Vector( const Vector & c ){

  this->N = c.N;
  this->dataPtr = new double[ this->N ];
  //kopiere komponentenweise den Vektor c
  for (std::size_t nx=0; nx<c.N; ++nx)
    this->dataPtr[ nx ] = c.dataPtr[ nx ];
};

//Destructor
Vector::~Vector (){

  delete [] this->dataPtr;

};

//Return size of Vector
const std::size_t Vector::size() const{

  return this->N;
};

//Ausgabe aller Einträge
void Vector::print(const string title, const int w) const{

  for(std::size_t nx=0; nx<this->N; nx++)

    cout << title<< "(" << nx << ")=" << setw(w) << this->dataPtr[nx] << " " << endl;

  cout << endl;

};

//Copy Operator
Vector & Vector::operator= ( const Vector & c ){

  
  if(this->N != c.N){
    
      delete[] this->dataPtr;
      // try to allocate memory and catch an exception
      this->N = c.N;
      this->dataPtr = new double[ c.N ];
  }

  // do the copying
  for (std::size_t nx=0; nx<c.N; nx++)
    this->dataPtr[ nx ] = c.dataPtr[ nx ];

  return *this;
  
};

//Initialisierung mit Skalar
Vector & Vector::operator=(const double value){

  for(std::size_t i=0;i<this->N;++i)
    this->dataPtr[i]=value;

  return *this;

};

//Index Operator Reading
const double  Vector::operator() ( std::size_t n ) const{
  // index check with assert: index check takes time 
  assert(n<this->N) ;

  return this->dataPtr[n];
};

//Index Operator Writing
double & Vector::operator() ( std::size_t n ){
  // index check with assert: index check takes time 
  assert(n<this->N) ;
  
  return this->dataPtr[n];
};

//Vektor-Addition
const Vector Vector::operator+ ( const Vector & c2) const{

  std::size_t size = this->N;
  // should be done with assert! run time checks not needed once the code is debugged
  if ( size!=c2.N ) { // run time check
    cerr << "Different dimensions for addition of 2 Vector instances!" << endl;
    exit(1);
  }
  
  Vector tmp( size );
  for (std::size_t nx=0; nx<size; nx++)
    tmp.dataPtr[nx] = this->dataPtr[nx] + c2.dataPtr[nx];
  
  return tmp;

};


//Vektor-Subtraktion
const Vector Vector::operator- ( const Vector & c2) const{
  
  std::size_t size = this->N;
  assert(size==c2.N);
  
  /*  if ( size!=c2.N ) {
    cerr << "Different dimensions for addition of 2 Vector instances!" << endl;
    exit(1);
    }*/

  Vector tmp( size );
  for (std::size_t nx=0; nx<size; nx++)
    tmp.dataPtr[nx] = this->dataPtr[nx] - c2.dataPtr[nx];

  return tmp;
  
};

//Skalarprodukt
const double Vector::operator* ( const Vector & c2) const{

  std::size_t size = this->N;
  
  assert(this->N==c2.N);

  double tmp = 0.;

  for (std::size_t nx=0; nx<size; nx++)
    tmp += this->dataPtr[nx]*c2.dataPtr[nx];

  return tmp;

};

//Multiplikation mit Skalar
const Vector Vector::operator* ( const double & lambda) const{

  std::size_t size = this->N;
  Vector tmp( size );

  for (std::size_t nx=0; nx<size; nx++) {
    tmp(nx) = lambda*this->dataPtr[nx];
  }
  
  return tmp;
};
