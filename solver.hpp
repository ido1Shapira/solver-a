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

        friend RealVariable operator* (const RealVariable x, const double n);
        friend RealVariable operator* (const double n ,const RealVariable x);
        friend RealVariable operator* (const RealVariable left,const RealVariable right);

        friend RealVariable operator+ (const RealVariable x, const double n);
        friend RealVariable operator+ (const double n ,const RealVariable x);
        friend RealVariable operator+ (const RealVariable left,const RealVariable right);

        friend RealVariable operator- (const RealVariable x, const double n);
        friend RealVariable operator- (const double n ,const RealVariable x);
        friend RealVariable operator- (const RealVariable left,const RealVariable right);

        friend RealVariable operator^ (const RealVariable x, const double n);

        friend RealVariable operator/ (const RealVariable x, const double n);

        friend RealVariable operator== (const RealVariable left,const RealVariable right);
        friend RealVariable operator== (const double n,const RealVariable right);
        friend RealVariable operator== (const RealVariable left, const double n);

        friend bool operator! (const RealVariable x);
        friend string operator+ (const RealVariable x, const string str);
        friend string operator+ (const string str ,const RealVariable x);
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

        friend ComplexVariable operator* (const ComplexVariable x, const complex<double> n);
        friend ComplexVariable operator* (const complex<double> n ,const ComplexVariable x);
        friend ComplexVariable operator* (const ComplexVariable left,const ComplexVariable right);

        friend ComplexVariable operator+ (const ComplexVariable x, const complex<double> n);
        friend ComplexVariable operator+ (const complex<double> n ,const ComplexVariable x);
        friend ComplexVariable operator+ (const ComplexVariable left,const ComplexVariable right);

        friend ComplexVariable operator- (const ComplexVariable x, const complex<double> n);
        friend ComplexVariable operator- (const complex<double> n ,const ComplexVariable x);
        friend ComplexVariable operator- (const ComplexVariable left,const ComplexVariable right);

        friend ComplexVariable operator^ (const ComplexVariable x, const complex<double> n);

        friend ComplexVariable operator/ (const ComplexVariable x, const complex<double> n);

        friend ComplexVariable operator== (const ComplexVariable left,const ComplexVariable right);
        friend ComplexVariable operator== (const complex<double> n,const ComplexVariable right);
        friend ComplexVariable operator== (const ComplexVariable left, const complex<double> n);

        friend bool operator! (const ComplexVariable x);
        friend string operator+ (const ComplexVariable x, const string str);
        friend string operator+ (const string str ,const ComplexVariable x);

    };

    double solve(const RealVariable equation);
    double solve(const bool equation);

    complex<double> solve(const ComplexVariable equation);

    string to_string_complex (const complex<double> c);

}