// John Goulden
// Comnplex Numbers Demo Program
// 1998 - 2020

// ComplexNumbers.h

// this is the "old school" way of preventing a header file
// from being included more than once in a project
// note that the "if" statement closes as the very last line of this file
//
// you can also say      #pragma once
//
// this is not yet part of the C++ standard
// but most compilers accept it

#ifndef COMPLEXNUMBER
#define COMPLEXNUMBER

#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{

public:
    // the only two data items we need for a complex number
    // are the "real" and "imaginary" components

    double real;
    double imaginary;

    // the default constructor will set both values to zero

    ComplexNumber()
    {
        real = 0;
        imaginary = 0;
    }

    // the constructor with two parameters will create
    // a complex number   a + i b

    ComplexNumber(double a, double b)
    {
        real = a;
        imaginary = b;
    }

    // the constructor with one parameter will create
    // a complex number with only a "real" component

    ComplexNumber(double a)
    {
        real = a;
        imaginary = 0;
    }

    // overload the assignment operator
    // note that since our class doesn't allocate memory dynamically this actually works for free but we'll write it anyway

    ComplexNumber &operator=(const ComplexNumber &rhs)
    {
        real = rhs.real;
        imaginary = rhs.imaginary;
        return *this;
    }

    // these two functions allow us to type-cast complex numbers
    // into integers and doubles

    operator int()
    {
        return (int)real;
    }

    operator double()
    {
        return real;
    }

    // We overload += first and build + from that
    // note the return type is a reference to a ComplexNumber
    // and that the parameter is a reference to a ComplexNumber
    // that is locked down with const, as we will not change it

    ComplexNumber &operator+=(const ComplexNumber &rhs)
    {
        real += rhs.real;
        imaginary += rhs.imaginary;
        return *this;
    }
    ComplexNumber &operator-=(const ComplexNumber &rhs)
    {
        real -= rhs.real;
        imaginary -= rhs.imaginary;
        return *this;
    }
    ComplexNumber &operator*=(const ComplexNumber &rhs)
    {
        *this = ComplexNumber(this->real * rhs.real - rhs.imaginary * this->imaginary, this->real * rhs.imaginary + this->imaginary * rhs.real);
        return *this;
    }
    double magnitude()
    {
        return real * real + imaginary * imaginary;
    }
    ComplexNumber &operator/=(const ComplexNumber &rhs)
    {
        *this = *this / rhs;
        return *this;
    }
    // Now we overload + but use the code we wrote for +=
    // Note that *this makes use of the default constructor
    // and gives us a ComplexNumber with zero in both fields

    ComplexNumber operator+(const ComplexNumber &rhs)
    {
        ComplexNumber result = *this;
        result += rhs;
        return result;
    }
    ComplexNumber operator-(const ComplexNumber &rhs)
    {
        ComplexNumber result = *this;
        ComplexNumber result2(-rhs.real, -rhs.imaginary);
        result += result2;
        return result;
    }
    ComplexNumber operator*(const ComplexNumber &rhs)
    {
        return ComplexNumber(this->real * rhs.real - rhs.imaginary * this->imaginary, this->real * rhs.imaginary + this->imaginary * rhs.real);
    }
    ComplexNumber operator/(const ComplexNumber &rhs)
    {
        ComplexNumber x(rhs.real, -rhs.imaginary);
        double ma = x.magnitude();
        // cout << x << endl;
        x *= *this;
        x.real /= ma;
        x.imaginary /= ma;

        return x;
    }
    bool operator>(const ComplexNumber &rhs) const
    {
        ComplexNumber c = *this;
        ComplexNumber d = rhs;
        bool result = c.magnitude() > d.magnitude();
        return result;
    }
    bool operator<(const ComplexNumber &rhs) const
    {
        ComplexNumber c = *this;
        ComplexNumber d = rhs;
        bool result = c.magnitude() < d.magnitude();
        return result;
    }
    bool operator>=(const ComplexNumber &rhs) const
    {
        ComplexNumber c = *this;
        ComplexNumber d = rhs;
        bool result = (c.magnitude() > d.magnitude() || c == d) ? true : false;
        return result;
    }
    bool operator<=(const ComplexNumber &rhs) const
    {
        ComplexNumber c = *this;
        ComplexNumber d = rhs;
        bool result = (c.magnitude() < d.magnitude() || c == d) ? true : false;
        return result;
    }
    // unary negation is easy

    ComplexNumber operator-()
    {
        return ComplexNumber(-real, -imaginary);
    }

    // so is unary plus
    // it works for the basic data types (but is ignored) so we should include it as well

    ComplexNumber operator+()
    {
        return ComplexNumber(real, imaginary);
    }

    // Overloading the comparison operator is easy...
    // the trailing "const" is a promise that operator== doesn't alter the state of either "this" or the rhs

    bool operator==(const ComplexNumber &rhs) const
    {
        ComplexNumber c = *this;
        bool result = (c.real == rhs.real) && (c.imaginary == rhs.imaginary);
        return result;
    }

    // ... and we overload != by calling the code we just wrote.

    bool operator!=(const ComplexNumber &rhs) const
    {
        bool result = !(*this == rhs);
        return result;
    }

    // for input we just take the next two numbers and build a ComplexNumber from them

    friend istream &operator>>(istream &in, ComplexNumber &c)
    {
        in >> c.real >> c.imaginary;
        return in;
    }

    // for output we want to say "+" if the imaginary part is positive, and "-" if it is negative
    // and we will display the absolute value of the imaginary part

    friend ostream &operator<<(ostream &out, const ComplexNumber &c)
    {
        out << "(" << c.real << (c.imaginary >= 0 ? " + " : " - ") << abs(c.imaginary) << " i)";
        return out;
    }
};

#endif