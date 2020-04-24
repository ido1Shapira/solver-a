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
        
        const double & geta() const { return a; }
        const double & getb() const { return b; }
        const double & getc() const { return c; }

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

        friend bool operator! (RealVariable x);
        friend string operator+ (RealVariable x, const string str);
        friend string operator+ (const string str , RealVariable x);
    };


    class ComplexVariable {
        complex<double> a;
        complex<double> b;
        complex<double> c;

    public:
        
        ComplexVariable(): a(0), b(0), c(0) {}
        
        ComplexVariable(complex<double> a, complex<double> b, complex<double> c) {
            this->a = complex(a);
            this->b = complex(b);
            this->c = complex(c);
        }
        
        const complex<double> & geta() const { return a; }
        const complex<double> & getb() const { return b; }
        const complex<double> & getc() const { return c; }

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

        friend bool operator! (ComplexVariable x);
        friend string operator+ (ComplexVariable x, const string str);
        friend string operator+ (const string str , ComplexVariable x);

    };

    double solve(RealVariable equation);
    double solve(bool equation);

    complex<double> solve(ComplexVariable equation);

    // string to_string (const complex<double> c);

}