#include <iostream>
#include <string>
// header file for own complex number class
#include "complex.h"

using namespace std;

void output_my_cplx(const MyComplex &c,const std::string txt){
    cout<<txt<<": ("<<c.real()<<", "<<c.imag()<<")"<<endl;
}

int main(){
    MyComplex z1 {2.,7.};
    MyComplex z2 {42.,-9};
    MyComplex z3 {-11.,19.};
    MyComplex z4,z5,z6,z7,z8;

    output_my_cplx(z1,"z1 ");
    output_my_cplx(z2,"z2 ");
    output_my_cplx(z3,"z3 ");

    z4=z1*z2;
    output_my_cplx(z4,"z4=z1*z2 =");
    z5=(z1+z2);
    output_my_cplx(z5,"z5=(z1+z2) =");
    z6=(z1+z2)*2.;
    output_my_cplx(z6,"z6=(z1+z2)*2. = ");
    z7=(z2+z3)*z1;
    output_my_cplx(z7,"z7=(z2+z3)*z1 = ");
    z8=z1+5.;
    output_my_cplx(z8,"z8=z1+5. = ");

    z8=z8*10.;
    output_my_cplx(z8,"z8=z8*10. = ");

    return 0;
}
