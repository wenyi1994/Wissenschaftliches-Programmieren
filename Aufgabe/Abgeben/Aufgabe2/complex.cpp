/*
 *
 * complex.cpp
 * 
 */

#include <iostream>
#include <cmath>

#include "complex.h"

using namespace std;

MyComplex::MyComplex(const double re, const double im ){ // constructor
    this->m_Real = re;
    this->m_Image = im;
}

MyComplex::MyComplex(const MyComplex & cplx){ // copy constructor
    this->m_Real = cplx.m_Real;
    this->m_Image = cplx.m_Image;
}

MyComplex::MyComplex(){this->m_Real = 0; this->m_Image = 0;} // default constructor
MyComplex::~MyComplex(){} // default destructor

MyComplex & MyComplex::operator=(const MyComplex & cplx){ // overload = operator
    this->m_Real = cplx.m_Real;
    this->m_Image = cplx.m_Image;
}

const MyComplex MyComplex::operator+(const MyComplex & cplx) const{ // overload + operator (complex number)
    MyComplex temp;
    temp.m_Real = this->m_Real + cplx.m_Real;
    temp.m_Image = this->m_Image + cplx.m_Image;
    return temp;
}

const MyComplex MyComplex::operator+(const double & real_number) const{ // overload + operator (real number)
    MyComplex temp;
    temp.m_Real = this->m_Real + real_number;
    temp.m_Image = this->m_Image;
    return temp;
}

const MyComplex operator+(const double & real_number, const MyComplex & cplx){ // overload + operator (real number, static, left +)
    MyComplex temp;
    temp = cplx + real_number;
    return temp;
}

const MyComplex MyComplex::operator-(const MyComplex & cplx) const{ // overload - operator (complex number)
    MyComplex temp;
    temp.m_Real = this->m_Real - cplx.m_Real;
    temp.m_Image = this->m_Image - cplx.m_Image;
    return temp;
}

const MyComplex MyComplex::operator-(const double & real_number) const{ // overload - operator (real number)
    MyComplex temp;
    temp.m_Real = this->m_Real - real_number;
    temp.m_Image = this->m_Image;
    return temp;
}

const MyComplex operator-(const double & real_number, const MyComplex & cplx){ // overload - operator (real number, static, left -)
    MyComplex temp(real_number,0.);
    return temp - cplx;
}

const MyComplex MyComplex::operator*(const MyComplex & cplx) const{ // overload * operator (complex number)
    MyComplex temp;
    temp.m_Real = this->m_Real * cplx.m_Real - this->m_Image * cplx.m_Image;
    temp.m_Image = this->m_Image * cplx.m_Real + this->m_Real * cplx.m_Image;
    return temp;
}

const MyComplex MyComplex::operator*(const double & real_number) const{ // overload * operator (real number)
    MyComplex temp;
    temp.m_Real = this->m_Real * real_number;
    temp.m_Image = this->m_Image * real_number;
    return temp;
}

const MyComplex operator*(const double & real_number, const MyComplex & cplx){ // overload * operator (real number, static, left *)
    MyComplex temp;
    temp = cplx * real_number;
    return temp;
}

const MyComplex MyComplex::operator/(const MyComplex & cplx) const{ // overload / operator (complex number)
    MyComplex temp;
    temp.m_Real = (this->m_Real * cplx.m_Real + this->m_Image * cplx.m_Image) / (cplx.m_Real * cplx.m_Real + cplx.m_Image * cplx.m_Image);
    temp.m_Image = (this->m_Image * cplx.m_Real - this->m_Real * cplx.m_Image) / (cplx.m_Real * cplx.m_Real + cplx.m_Image * cplx.m_Image);
    return temp;
}

const MyComplex MyComplex::operator/(const double & real_number) const{ // overload / operator (real number)
    MyComplex temp;
    temp.m_Real = this->m_Real / real_number;
    temp.m_Image = this->m_Image / real_number;
    return temp;
}

const MyComplex operator/(const double & real_number, const MyComplex & cplx){ // overload / operator (real number, static, left /)
    MyComplex temp(real_number,0);
    return temp / cplx;
}

const MyComplex MyComplex::operator^(const int & exp) const{ // overload ^ operator
    MyComplex temp(0,0);
    if(this->m_Real * this->m_Image == 0) return temp;
    else
    {
        temp.m_Real = 1;
        if(exp > 0)
        {
            for (int i = 0; i<exp; i++)
            {
                temp = temp * *this;
            }
        }
        else if(exp < 0)
        {
            for (int i = 0; i>exp; i--)
            {
                temp = temp / *this;
            }
        }
    }
    return temp;
}

const double MyComplex::real() const{
    return this->m_Real;
}

const double MyComplex::imag() const{
    return this->m_Image;
}

const double MyComplex::norm() const{
    return sqrt(this->m_Real * this->m_Real + this->m_Image * this->m_Image);
}