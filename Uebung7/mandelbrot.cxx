#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <complex>
#include <omp.h>


typedef std::complex<double> Complex;
 
 int MandelbrotCalculate(Complex c, int maxiter)
 {
     Complex z = c;
     int n=0;
     for(; n<maxiter; ++n)
     {
         if( std::abs(z) >= 2.0) break;
         z = z*z + c;
     }
     return n;
 }


using namespace std;



 int main()
 {
     double t_start = omp_get_wtime();

     const int width = 5*20, height = 5*20, num_pixels = width*height;
     
     const Complex center(-.7, 0), span(2.7, -(4/3.0)*2.7*height/width);
     const Complex begin = center-span/2.0, end = center+span/2.0;
     const int maxiter = 100000;
     
     // gnuplot file: define ofstream object
     ofstream gpfile("mandel.dat");
     //

#pragma omp parallel
    {
#pragma omp for ordered
     for(int pix=0; pix<num_pixels; ++pix)
     {
         const int x = pix%width, y = pix/width;
         
         Complex c = begin + Complex(x * span.real() / (width +1.0),
                                     y * span.imag() / (height+1.0));
         
         int n = MandelbrotCalculate(c, maxiter);
         if(n == maxiter) n = 0;
         


         {
	     if(n>10) n=10;

	     // gnuplot output
	     if(pix>0 && x==0) gpfile<<endl;
         #pragma omp critical
	     gpfile <<c.real()<<" "<<c.imag()<<" "<<n<<endl;
	     
	     //std::cout << n << " ";
	     //if(x+1 == width) std::cout << std::endl;
	 }

     }
    }

     gpfile.close();

    double t_end = omp_get_wtime();

     cout << "pixel: " << num_pixels << endl;
     cout << "runtime: "<<t_end - t_start<<endl;
     //     cout << "time: " << t1-t0 << "" << endl;
 }
