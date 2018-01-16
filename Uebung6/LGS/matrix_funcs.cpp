/*
 * matrix_funcs.cpp
 *
 *
 *
 */

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <iomanip>

#include "matrix_funcs.h"

//Constructor TODO: Selber machen
Matrix::Matrix ( std::size_t const rows, const std::size_t cols ){

this->_rows = rows;
this->_cols = cols;
this->dataPtr = new double*[rows];
this->dataPtr[0] = new double[rows*cols];
for(auto i = 1; i<this->_rows; i++)
{
  this->dataPtr[i] = this->dataPtr[0] + i*this->_cols;
}

}
//Copy Constructor TODO: Selber machen
Matrix::Matrix (const Matrix & m){

this->_rows = m._rows;
this->_cols = m._cols;
this->dataPtr = new double*[m._rows];
this->dataPtr[0] = new double[m._rows*m._cols];
for(auto i = 1; i<this->_rows; i++)
{
  this->dataPtr[i] = this->dataPtr[0] + i*this->_cols;
}

for(std::size_t i=0; i<this->_rows; ++i)
    for(std::size_t j=0; j<this->_cols; ++j)
      this->dataPtr[i][j] = m.dataPtr[i][j];

}

//Destructor TODO: Selber machen
Matrix::~Matrix ()
{

delete[] this->dataPtr[0];
delete[] this->dataPtr;

}
//Copy Operator
Matrix & Matrix::operator= (const Matrix & m){
  // der Test auf Selbszuweisung kann auch entfallen: normalerweise kommt er nicht vor und wenn dann wird halt kopiert
  //if (this == &m ) return *this;  //!!!Untersuchung auf Gleichheit!!! Selbstzuweisung unnoetig: mache nichts
  
  // Loeschen/Neuanlegen nur nötig, wenn Format nicht passt
  // auch das ist Luxus....
  if(this->_rows != m._rows  ||  this->_cols != m._cols) {
    
    delete[] this->dataPtr[0];
    delete[] this->dataPtr;

    this->dataPtr    = new double*[m._rows];
    this->dataPtr[0] = new double [m._rows*m._cols];
    for (auto i=1; i<this->_rows; i++)
      this->dataPtr[i] = this->dataPtr[0]+i*this->_cols;
  }
  
  for(std::size_t i=0; i<this->_rows; ++i)
    for(std::size_t j=0; j<this->_cols; ++j)
      this->dataPtr[i][j] = m.dataPtr[i][j];
  
  return *this;
}

Matrix & Matrix::operator= (const double val){

  for(auto  i=0; i<this->_rows; ++i)
    for(auto j=0; j<this->_cols; ++j)
      this->dataPtr[i][j] = val;

  return *this;

}

//Index Operator Reading
const double Matrix::operator() ( const std::size_t nx, const std::size_t ny ) const{

  assert(nx<this->_rows && ny<this->_cols); //this-> ist für Aufruf von Klassenvariablen nicht zwingend notwendig
  return this->dataPtr[nx][ny];
}

//Index Operator Writing
double & Matrix::operator() ( const std::size_t nx, const std::size_t ny ){

  assert(nx<this->_rows && ny<this->_cols); //this-> ist für Aufruf von Klassenvariablen nicht zwingend notwendig
  return this->dataPtr[nx][ny];

}

//Matrix-Vector Produkt
const Vector Matrix::operator* ( const Vector & b ) const{

  auto nmax = b.size();
  assert( this->_cols==nmax );

  Vector tmp( this->_rows ); // Ergebnisvektor erg(n) = A(n,m)*b(m)


  for (auto i=0; i<this->_rows; i++) {
    tmp(i)=0.;
    for (auto j=0; j<this->_cols; j++)
      tmp(i) += this->dataPtr[i][j]*b(j);
  }
  return tmp;

}

//Matrix Addition TODO: Selber machen
const Matrix Matrix::operator+ ( const Matrix & A) const{

  std::size_t nx = this->_rows;
  std::size_t ny = this->_cols;
  assert(nx == A._rows && ny == A._cols);
  Matrix tmp(nx,ny);

  for(std::size_t i=0; i<nx; ++i)
    for(std::size_t j=0; j<ny; ++j)
      tmp.dataPtr[i][j] = this->dataPtr[i][j] + A.dataPtr[i][j];

  return tmp;
}


const std::size_t Matrix::rows() const { return this->_rows; }
const std::size_t Matrix::cols() const { return this->_cols; }

//Ausgabe Matrix
void Matrix::print(const int w) const
{
  for(auto i=0; i<this->_rows; ++i)
    {
      for(auto j=0; j<this->_cols; ++j)
	      cout << setw(w) << this->dataPtr[i][j] << "  ";
      cout << endl;
    }
}

const Matrix Matrix::transpose() const
{
  Matrix temp = *this;
  std::size_t nx = this->_rows;
  std::size_t ny = this->_cols;
  assert(nx == ny);
  for(auto i=0;i<nx;i++)
  {
    for(auto j=i+1;j<ny;j++)
    {
      temp(i,j) = this->dataPtr[j][i];
      temp(j,i) = this->dataPtr[i][j];
    }
  }
  return temp;
}
