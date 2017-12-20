/*
 *
 * complex.cpp
 * 
 */

#include <iostream>
#include <cmath>

#include "complex.h"

using namespace std;

// constructor
MyComplex::MyComplex(const double re, const double im ){
    this->m_Real = re;
    this->m_Image = im;
}

// copy constructor
MyComplex::MyComplex(const MyComplex & cplx){
    this->m_Real = cplx.m_Real;
    this->m_Image = cplx.m_Image;
}

// default constructor and default destructor
MyComplex::MyComplex(){this->m_Real = 0; this->m_Image = 0;}
MyComplex::~MyComplex(){} 

// overload = operator
MyComplex & MyComplex::operator=(const MyComplex & cplx){
    this->m_Real = cplx.m_Real;
    this->m_Image = cplx.m_Image;
    return *this;
}

// overload + operator (complex number)
const MyComplex MyComplex::operator+(const MyComplex & cplx) const{
    MyComplex temp;
    temp.m_Real = this->m_Real + cplx.m_Real;
    temp.m_Image = this->m_Image + cplx.m_Image;
    return temp;
}

// overload + operator (real number)
const MyComplex MyComplex::operator+(const double & real_number) const{
    MyComplex temp;
    temp.m_Real = this->m_Real + real_number;
    temp.m_Image = this->m_Image;
    return temp;
}

// overload + operator (real number, static, left +)
const MyComplex operator+(const double & real_number, const MyComplex & cplx){
    MyComplex temp;
    temp = cplx + real_number;
    return temp;
}

// overload - operator (complex number)
const MyComplex MyComplex::operator-(const MyComplex & cplx) const{
    MyComplex temp;
    temp.m_Real = this->m_Real - cplx.m_Real;
    temp.m_Image = this->m_Image - cplx.m_Image;
    return temp;
}

// overload - operator (real number)
const MyComplex MyComplex::operator-(const double & real_number) const{
    MyComplex temp;
    temp.m_Real = this->m_Real - real_number;
    temp.m_Image = this->m_Image;
    return temp;
}

// overload - operator (real number, static, left -)
const MyComplex operator-(const double & real_number, const MyComplex & cplx){
    MyComplex temp(real_number,0.);
    return temp - cplx;
}

// overload * operator (complex number)
const MyComplex MyComplex::operator*(const MyComplex & cplx) const{
    MyComplex temp;
    temp.m_Real = this->m_Real * cplx.m_Real - this->m_Image * cplx.m_Image;
    temp.m_Image = this->m_Image * cplx.m_Real + this->m_Real * cplx.m_Image;
    return temp;
}

// overload * operator (real number)
const MyComplex MyComplex::operator*(const double & real_number) const{
    MyComplex temp;
    temp.m_Real = this->m_Real * real_number;
    temp.m_Image = this->m_Image * real_number;
    return temp;
}

// overload * operator (real number, static, left *)
const MyComplex operator*(const double & real_number, const MyComplex & cplx){
    MyComplex temp;
    temp = cplx * real_number;
    return temp;
}

// overload / operator (complex number)
const MyComplex MyComplex::operator/(const MyComplex & cplx) const{
    MyComplex temp;
    temp.m_Real = (this->m_Real * cplx.m_Real + this->m_Image * cplx.m_Image) / (cplx.m_Real * cplx.m_Real + cplx.m_Image * cplx.m_Image);
    temp.m_Image = (this->m_Image * cplx.m_Real - this->m_Real * cplx.m_Image) / (cplx.m_Real * cplx.m_Real + cplx.m_Image * cplx.m_Image);
    return temp;
}

// overload / operator (real number)
const MyComplex MyComplex::operator/(const double & real_number) const{
    MyComplex temp;
    temp.m_Real = this->m_Real / real_number;
    temp.m_Image = this->m_Image / real_number;
    return temp;
}

// overload / operator (real number, static, left /)
const MyComplex operator/(const double & real_number, const MyComplex & cplx){
    MyComplex temp(real_number,0);
    return temp / cplx;
}

// overload ^ operator
const MyComplex MyComplex::operator^(const int & exp) const{
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