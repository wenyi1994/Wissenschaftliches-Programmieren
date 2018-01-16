#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include "vector_funcs.h"
#include "matrix_funcs.h"
#include "solver_funcs.h"

using namespace std;


void _ludcmp(  Matrix &a, Vec_I &indx, double &d)
{
    const double TINY=1.0e-20;
    int i,imax,j,k;
    i=0;  // to get rid of the warning
    imax=0;  // to get rid of the warning
    double big,dum,sum,temp;
    
    //int n=a.size();
    int n=a.rows();
    Vector vv(n);
    d=1.0;
    for (i=0;i<n;i++) {
		big=0.0;
		for (j=0;j<n;j++)
	    	if ((temp=fabs(a(i,j))) > big) big=temp;
		if (big == 0.0) {
	    	cerr << "Singular matrix in routine ludcmp" << endl;
	    	exit(1);
		}
		vv(i)=1.0/big;
    }
    for (j=0;j<n;j++) {
		for (i=0;i<j;i++) {
	    	sum=a(i,j);
	    	for (k=0;k<i;k++) sum -= a(i,k)*a(k,j);
	    	a(i,j)=sum;
		}
		big=0.0;
		for (i=j;i<n;i++) {
	    	sum=a(i,j);
	    	for (k=0;k<j;k++) sum -= a(i,k)*a(k,j);
	    	a(i,j)=sum;
	    	if ((dum=vv(i)*fabs(sum)) >= big) {
				big=dum;
				imax=i;
	    	}
		}
		if (j != imax) {
	    	for (k=0;k<n;k++) {
				dum=a(imax,k);
				a(imax,k)=a(j,k);
				a(j,k)=dum;
	    	}
	    	d = -d;
	    	vv(imax)=vv(j);
		}
		indx[j]=imax;
		if (a(j,j) == 0.0) a(j,j)=TINY;
		if (j != n-1) {
	    	dum=1.0/(a(j,j));
	    	for (i=j+1;i<n;i++) a(i,j) *= dum;
		}
    }
}



void _lubksb( Matrix &a, Vec_I &indx, Vector &b)
{
	int i,ii=0,ip,j;
	double sum;

	int n=a.rows();
	for (i=0;i<n;i++) {
	    ip=indx[i];
	    sum=b(ip);
	    b(ip)=b(i);
	    if (ii != 0)
			for (j=ii-1;j<i;j++) sum -= a(i,j)*b(j);
	    else if (sum != 0.0)
			ii=i+1;
	    b(i)=sum;
	}
	for (i=n-1;i>=0;i--) {
	    sum=b(i);
	    for (j=i+1;j<n;j++) sum -= a(i,j)*b(j);
	    b(i)=sum/a(i,i);
	}
}






Vector lu_solve(  Matrix & A,   const Vector &  b )
{
    assert(A.cols()==b.size());
    assert(A.rows()==A.cols());
    const int N=A.rows();
    Vector x=b;

    double d;
    Vec_I indx( N );  // for premutations of rows according to Gauss algorithm
    _ludcmp( A, indx, d );
    _lubksb( A, indx, x );

    return x;
}

Vector ch_solve( const Matrix & A, const Vector & b)
{
	const int mat_size = b.size();
	Matrix R(mat_size,mat_size);
	Vector r(mat_size);
	R = 0;
	r = 0;
	double temp = 0.;
	double temp2 = 0.;
	for(int i=0;i<mat_size;i++)
	{
		for(int j=0;j<i;j++)
		{
			temp = 0.;
			for(int k=0;k<j;k++)
			{
				temp += R(i,k)*R(j,k);
			}
			R(i,j) = 1./R(j,j)*(A(i,j)-temp);
		}
		temp = 0.; temp2 = 0.;
		for(int k=0;k<i;k++)
		{
			temp += R(i,k)*R(i,k);
			temp2 += R(i,k)*r(k);
		}
		R(i,i) = sqrt(A(i,i)-temp);
		r(i) = 1./R(i,i)*(b(i)-temp2);
	}

	Vector x = b;
	for(int i=mat_size-1;i>-1;i--)
	{
		temp = 0.;
		for(int k=i+1;k<mat_size;k++)
		{
			temp += R(k,i)*x(k);
		}
		x(i) = 1./R(i,i)*(r(i)-temp);
	}

	return x;
}






Vector cg_solve( const Vector & phi0, const Matrix & A, const Vector & b )
{
    const int max_iter = b.size();
    const double tol = 1.e-5; //relative Fehlertoleranz
    
    Vector phi = phi0;
    Vector r = b - A*phi;
    Vector d = r;
    //cout<< "tol" << tol*tol *  (b*b) << endl;

    for ( int n=0; n<max_iter; ++n )
    	{
    	    const double c = 1./( d * (A*d) );
    	    const double alpha = c * (d*r);
    	    phi   = phi + d*alpha;
    	    r     = b   - A*phi;
    	    d     = r - d*c*(r * (A*d));
	
    	    if ( r*r<=tol*tol *  (b*b)) return phi; //Fehlerquadrat muss kleiner als geg. Toleranz sein
	}
    cout<<" end of cg: not converged: ";
    cout<< "r*r " <<r*r << endl;
    return phi;
}

Vector gs_solve(const Vector & phi0, Matrix & A, const Vector & b)
{
	const int max_iter = b.size();
	const int mat_size = max_iter;
	const double tol = 1.e-5; //Fehlertoleranz

	Vector phi = phi0;
	double E = 0.;
	double F = 0.;
	Vector r = A*phi-b;
	double tol_b = tol*tol*(b*b);

	while(r*r>tol_b)
	{
		for (int m=0; m<mat_size; m++)
		{
			E = 0.;
			F = 0.;
			for(int i = 0;i<m;i++)
			{
				E += A(m,i)*phi(i);
			}
			for(int i = m+1;i<mat_size;i++)
			{
				F += A(m,i)*phi(i);
			}
			phi(m) = 1./A(m,m)*(b(m)-E-F);
		}
		r = A*phi-b;
	}
	return phi;
}