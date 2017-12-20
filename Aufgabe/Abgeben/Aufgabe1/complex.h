/*
 *
 * complex.h
 * 
 */

#ifndef COMPLEX_H
#define COMPLEX_H

class MyComplex{

private:
    double m_Real;
    double m_Image;


public:
    // con-/destructor
    MyComplex();
    MyComplex(const double re, const double im );
    MyComplex(const MyComplex & cplx);
    ~MyComplex();

    // copy operator = 
    MyComplex & operator=(const MyComplex & cplx);

    // overload operator +-*/ (with complex number, real number on the left and on the right)
    const MyComplex operator+(const MyComplex & cplx) const;
    const MyComplex operator+(const double & real_number) const;
    // use friend to define out of class
    friend const MyComplex operator+(const double & real_number, const MyComplex & cplx);
    const MyComplex operator-(const MyComplex & cplx) const;
    const MyComplex operator-(const double & real_number) const;
    friend const MyComplex operator-(const double & real_number, const MyComplex & cplx);
    const MyComplex operator*(const MyComplex & cplx) const;
    const MyComplex operator*(const double & real_number) const;
    friend const MyComplex operator*(const double & real_number, const MyComplex & cplx);
    const MyComplex operator/(const MyComplex & cplx) const;
    const MyComplex operator/(const double & real_number) const;
    friend const MyComplex operator/(const double & real_number, const MyComplex & cplx);

    // overload operator ^
    const MyComplex operator^(const int & exp) const;

    const double real() const;
    const double imag() const;
    const double norm() const;

};

#endif /* COMPLEX_H */ 