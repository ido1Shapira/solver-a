#include "solver.hpp"
#include <iostream>

// Id of collaborators 208825539 207950577

using namespace std;
// using namespace solver;
namespace solver {

    RealVariable operator* (RealVariable x, const double n) {
        return x;
    }

    RealVariable operator* (const double n , RealVariable x) {
        return x;

    }

    RealVariable operator* (RealVariable left, RealVariable right) {
        return left;

    }

    RealVariable operator+ (RealVariable x, const double n) {
        return x;

    }

    RealVariable operator+ (const double n , RealVariable x) {
        return x;

    }

    RealVariable operator+ (RealVariable left, RealVariable right) {
        return left;

    }

    RealVariable operator- (RealVariable x, const double n) {
        return x;

    }

    RealVariable operator- (const double n , RealVariable x) {
        return x;

    }

    RealVariable operator- (RealVariable left, RealVariable right) {
        return left;

    }

    RealVariable operator^ (RealVariable x, const double n) {
        return x;

    }

    RealVariable operator/ (RealVariable x, const double n) {
        return x;

    }

    RealVariable operator== (RealVariable left, RealVariable right) {
        return left;

    }

    RealVariable operator== (const double n, RealVariable right) {
        return right;

    }
    
    RealVariable operator== (RealVariable left, const double n) {
        return left;

    }



    ComplexVariable operator* (ComplexVariable x, const complex<double> n) {
        return x;

    }

    ComplexVariable operator* (const complex<double> n , ComplexVariable x) {
        return x;

    }

    ComplexVariable operator* (ComplexVariable left, ComplexVariable right) {
        return left;

    }   

    ComplexVariable operator+ (ComplexVariable x, const complex<double> n) {
        return x;

    }
    
    ComplexVariable operator+ (const complex<double> n , ComplexVariable x) {
        return x;

    }

    ComplexVariable operator+ (ComplexVariable left, ComplexVariable right) {
        return left;

    }

    ComplexVariable operator- (ComplexVariable x, const complex<double> n) {
        return x;

    }
    
    ComplexVariable operator- (const complex<double> n , ComplexVariable x) {
        return x;

    }
    
    ComplexVariable operator- (ComplexVariable left, ComplexVariable right) {
        return left;

    }

    ComplexVariable operator^ (ComplexVariable x, const complex<double> n) {
        return x;

    }

    ComplexVariable operator/ (ComplexVariable x, const complex<double> n) {
        return x;

    }

    ComplexVariable operator== (ComplexVariable left, ComplexVariable right) {
        return left;

    }

    ComplexVariable operator== (const complex<double> n, ComplexVariable right) {
        return right;

    }
    
    ComplexVariable operator== (ComplexVariable left, const complex<double> n) {
        return left;

    }



    double solve(RealVariable equation) {
        return 0;
    }

    complex<double> solve(ComplexVariable equation) {
        return complex<double>(0);

    }
}