#pragma once

#include <complex>

// Id of collaborators 208825539 207950577

using namespace std;

namespace solver {


    class RealVariable {
        double a;
        double b;
        double c;
    
    public:
        RealVariable(): a(0), b(0), c(0) {}

        RealVariable(double a, double b, double c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        // RealVariable operator* (const double n);
        // RealVariable operator+ (const double n);
        // RealVariable operator- (const double n);
        // RealVariable operator^ (const double n);
        // RealVariable operator/ (const double n);

        // double operator== (RealVariable right);
        friend RealVariable operator* (RealVariable x, const double n);
        friend RealVariable operator* (const double n , RealVariable x);
        friend RealVariable operator* (RealVariable left, RealVariable right);

        friend RealVariable operator+ (RealVariable x, const double n);
        friend RealVariable operator+ (const double n , RealVariable x);
        friend RealVariable operator+ (RealVariable left, RealVariable right);

        friend RealVariable operator- (RealVariable x, const double n);
        friend RealVariable operator- (const double n , RealVariable x);
        friend RealVariable operator- (RealVariable left, RealVariable right);

        friend RealVariable operator^ (RealVariable x, const double n);

        friend RealVariable operator/ (RealVariable x, const double n);

        friend RealVariable operator== (RealVariable left, RealVariable right);
        friend RealVariable operator== (const double n, RealVariable right);
        friend RealVariable operator== (RealVariable left, const double n);
    };


    class ComplexVariable {
        complex<double> a;
        complex<double> b;
        complex<double> c;

    public:
        
        ComplexVariable(): a(0), b(0), c(0) {}
        
        // ComplexVariable operator* (complex<double> n);
        // ComplexVariable operator+ (complex<double> n);
        // ComplexVariable operator- (complex<double> n);
        // ComplexVariable operator^ (complex<double> n);
        // ComplexVariable operator/ (complex<double> n);

        // complex<double> operator== (RealVariable right);

    friend ComplexVariable operator* (ComplexVariable x, const complex<double> n);
    friend ComplexVariable operator* (const complex<double> n , ComplexVariable x);
    friend ComplexVariable operator* (ComplexVariable left, ComplexVariable right);

    friend ComplexVariable operator+ (ComplexVariable x, const complex<double> n);
    friend ComplexVariable operator+ (const complex<double> n , ComplexVariable x);
    friend ComplexVariable operator+ (ComplexVariable left, ComplexVariable right);

    friend ComplexVariable operator- (ComplexVariable x, const complex<double> n);
    friend ComplexVariable operator- (const complex<double> n , ComplexVariable x);
    friend ComplexVariable operator- (ComplexVariable left, ComplexVariable right);

    friend ComplexVariable operator^ (ComplexVariable x, const complex<double> n);

    friend ComplexVariable operator/ (ComplexVariable x, const complex<double> n);

    friend ComplexVariable operator== (ComplexVariable left, ComplexVariable right);
    friend ComplexVariable operator== (const complex<double> n, ComplexVariable right);
    friend ComplexVariable operator== (ComplexVariable left, const complex<double> n);
    
    
    };



    double solve(RealVariable equation);
    complex<double> solve(ComplexVariable equation);

}