#ifndef __SOLVER_FUNCS_H__
#define __SOLVER_FUNCS_H__

#include <vector>


#ifndef VEC_I
#define VEC_I
typedef std::vector<int> Vec_I;  // vector of ints
#endif // VEC_I


#include "vector_funcs.h"
#include "matrix_funcs.h"


/* Solves a system of linear equations  A*x=b for x by LU decomposition
 * Verwendung: x = lu_solve(A,b) 
 * Achuntg: A wird beim Lösen des LGS geändert!!! */
Vector lu_solve(  Matrix & A,  const  Vector &  b );


// phi0 ist der 'initial guess' (=startwert).
/* Verwendung: x = cg_solve_LGS ( phi0, A, b); */
Vector cg_solve( const Vector & phi0, const Matrix & A, const Vector & b );





// Hilfsfunktionen fuer die LU-Dekomposition 
// (in Anlehnung an: Numerical Recipes in C++)
void _ludcmp(  Matrix &a, Vec_I &indx, double &d);   // LU-Dekomposition

void _lubksb(  Matrix &a, Vec_I &indx, Vector &b); // Zurueck-Substitution




#endif 
