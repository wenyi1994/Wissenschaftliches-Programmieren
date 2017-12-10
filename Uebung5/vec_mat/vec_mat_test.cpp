/*
 * vec_mat_test.cpp
 *
 *
 *
 */

#include <iostream>
#include <cstdio>

#include "vector_funcs.h"
#include "matrix_funcs.h"


int main(){

  Matrix A(3,5);
  A = 5.;

  const Matrix B = A;

  Vector v1(5);

  v1 = 2.;

  v1.print();

  Vector v2 = B*v1;

  v2.print();

  cout << "Matrix A: " << endl;
  A.print();
  cout << "Matrix B: " << endl;
  B.print();

  A(2,2) = 3;
  cout << "Matrix A: " << endl;
  A.print();

  cout << "Matrix A(2,2): " << A(2,2) << endl;

}
