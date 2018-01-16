/*
 * matrix_funcs.h
 *
 *
 *
 */

#ifndef MATRIX_FUNCS_H_
#define MATRIX_FUNCS_H_

#include <cstddef>
#include "vector_funcs.h"

using namespace std;


// Declarations


class Matrix {


 public:

  //Constructor TODO: Selber machen
  Matrix (std::size_t const rows, std::size_t const cols);
  //Copy-Constructor TODO: Selber machen
  Matrix (const Matrix & m);
  //Destructor: TODO: Selber machen
  ~Matrix ();

  //Copy Operator
  Matrix & operator= ( const Matrix & m );
  //Fill with same Value
  Matrix & operator= ( const double val );

  //Index Operator Reading
  const double operator() ( const std::size_t nx, const std::size_t ny ) const;
  //Index Operator Writing TODO: Selber machen
  double & operator() ( const std::size_t nx, const std::size_t ny );
  //Matrix-Vector Produkt
  const Vector operator* ( const Vector & b ) const;
  //Matrix Addition TODO: Selber machen
  const Matrix operator+ ( const Matrix & A) const;



  const std::size_t rows() const;
  const std::size_t cols() const;
  
  //Ausgabe Matrix
  void print(const int w=8) const; //const int w=8 default Wert für Abstand. Übergabe bei Aufruf optional
  const Matrix transpose() const;


 private:

  //Default Constructor: Hier PRIVATE um des Ausführen Default Constructor zu unterbinden
  Matrix ();

  double ** dataPtr;
  int _rows, _cols;

};




#endif /* MATRIX_FUNCS_H_ */
