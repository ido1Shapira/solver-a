#include "solver.hpp"
#include <iostream>
#include <string>

// Id of collaborators 208825539 207950577

using namespace std;
namespace solver {

    RealVariable operator* (const RealVariable& x, const double n) {
        return RealVariable(x.a*n, x.b*n, x.c*n);
    
    }

    RealVariable operator* (const double n ,const RealVariable& x) {
        return RealVariable(x.a*n, x.b*n, x.c*n);
    
    }

    RealVariable operator* (const RealVariable& left, const RealVariable& right) {
        if(left.a != 0 && right.a != 0) throw invalid_argument("power is too big");
        if(left.a != 0 && right.b != 0) throw invalid_argument("power is too big");
        if(left.b != 0 && right.a != 0) throw invalid_argument("power is too big");

        return RealVariable(left.a * right.c + right.a * left.c + left.b * right.b ,
                                 left.b * right.c + right.b * left.c,
                                     left.c * right.c);

    }

    RealVariable operator+ (const RealVariable& x, const double n) {
        return RealVariable(x.a, x.b , x.c+n);

    }

    RealVariable operator+ (const double n ,const RealVariable& x) {
        return RealVariable(x.a, x.b , x.c+n);

    }

    RealVariable operator+ (const RealVariable& left, const RealVariable& right) {
        return RealVariable(left.a + right.a , left.b + right.b , left.c + right.c);

    }

    RealVariable operator- (const RealVariable& x, const double n) {
        return RealVariable(x.a, x.b , x.c-n);

    }

    RealVariable operator- (const double n ,const RealVariable& x) {
        return RealVariable(-x.a, -x.b , -x.c+n);

    }

    RealVariable operator- (const RealVariable& left, const RealVariable& right) {
        return RealVariable(left.a - right.a , left.b - right.b , left.c - right.c);

    }

    RealVariable RealVariable::operator- () const {
        return -1 * *this;
    }

    RealVariable operator^ (const RealVariable& x, const double n) {
        if(n == 2) {
            return x*x;
        }
        if (n == 1) {
            return x;
        }
        if (n == 0) {
            return RealVariable(0,0,1);
        }
        throw invalid_argument("power is not vaild: ");

    }

    RealVariable operator/ (const RealVariable& x, const double n) {
        if(n == 0) throw invalid_argument("Division by zero is not valid");

        return RealVariable(x.a/n, x.b/n, x.c/n);

    }

    RealVariable operator/ (const RealVariable& left, const RealVariable& right) {
        RealVariable x;

        if(!right) throw invalid_argument("Division by zero is not valid");

        if(!(left - right)) return RealVariable(0,0,1);
        if(!(left - (x^2)) && !(right - x)) return RealVariable(0,1,0);
        if(right.a == 0 && right.b == 0) return left/right.c;

        throw invalid_argument("divison is out of our assignment's scope");

    }

    RealVariable operator== (const RealVariable& left, const RealVariable& right) {
        return left - right;

    }

    RealVariable operator== (const double n, const RealVariable& right) {
        return right - n;

    }
    
    RealVariable operator== (const RealVariable& left, const double n) {
        return left - n;

    }

    bool RealVariable::operator! () const {
        return this->a == 0 && this->b == 0 && this->c == 0;
    }

    string operator+ (const RealVariable& x, const string str) {
        return to_string((int)x.a) + "x^2 +" + to_string((int)x.b) + "x +"+ to_string((int)x.c) + str;
    }
    
    string operator+ (const string str , const RealVariable& x) {
        return str + to_string((int)x.a) + "x^2 +" + to_string((int)x.b) + "x +"+ to_string((int)x.c);
    }

/////////////////////////////////////////ComplexVariable functions//////////////////////////////////////////////


    ComplexVariable operator* (const ComplexVariable& x, const complex<double> n) {
        return ComplexVariable(x.a*n, x.b*n, x.c*n);

    }

    ComplexVariable operator* (const complex<double> n , const ComplexVariable& x) {
        return ComplexVariable(x.a*n, x.b*n, x.c*n);

    }

    ComplexVariable operator* (const ComplexVariable& left, const ComplexVariable& right) {
        if(left.a != complex(0.0,0.0) && right.a != complex(0.0,0.0)) throw invalid_argument("power is too big");
        if(left.a != complex(0.0,0.0) && right.b != complex(0.0,0.0)) throw invalid_argument("power is too big");
        if(left.b != complex(0.0,0.0) && right.a != complex(0.0,0.0)) throw invalid_argument("power is too big");

        return ComplexVariable(left.a * right.c + right.a * left.c + left.b * right.b ,
                                 left.b * right.c + right.b * left.c,
                                     left.c * right.c);

    }   

    ComplexVariable operator+ (const ComplexVariable& x, const complex<double> n) {
        return ComplexVariable(x.a, x.b , x.c+n);

    }
    
    ComplexVariable operator+ (const complex<double> n , const ComplexVariable& x) {
        return ComplexVariable(x.a, x.b , x.c+n);
    }

    ComplexVariable operator+ (const ComplexVariable& left, const ComplexVariable& right) {
        return ComplexVariable(left.a + right.a , left.b + right.b , left.c + right.c);
    
    }

    ComplexVariable operator- (const ComplexVariable& x, const complex<double> n) {
        return ComplexVariable(x.a, x.b , x.c-n);
        
    }
    
    ComplexVariable operator- (const complex<double> n , const ComplexVariable& x) {
        return ComplexVariable(-x.a, -x.b , -x.c+n);
        
    }

    ComplexVariable operator- (const ComplexVariable& left, const ComplexVariable& right) {
        return ComplexVariable(left.a - right.a , left.b - right.b , left.c - right.c);

    }

    ComplexVariable operator^ (const ComplexVariable& x, const complex<double> n) {
        if(n.imag() != 0) throw invalid_argument("complex power is not valid");

        if(n.real() == 2) {
            return x*x;
        }
        if (n.real() == 1) {
            return x;
        }
        if (n.real() == 0) {
            return ComplexVariable(complex(0.0,0.0),complex(0.0,0.0),complex(1.0,0.0));
        }
        throw invalid_argument("power is not vaild: ");

    }

    ComplexVariable operator/ (const ComplexVariable& x, const complex<double> n) {
        if(n == complex(0.0,0.0)) throw invalid_argument("Division by zero is not valid");

        return ComplexVariable(x.a/n, x.b/n, x.c/n);

    }
    
    ComplexVariable operator/ (const ComplexVariable& left, const ComplexVariable& right) {
        ComplexVariable x;

        if(!right) throw invalid_argument("Division by zero is not valid");

        if(!(left - right)) return ComplexVariable(0,0,complex(1.0,0.0));
        if(!(left - (x^2)) && !(right - x)) return ComplexVariable(0,complex(1.0,0.0),0);
        if(right.a == complex(0.0,0.0) && right.b == complex(0.0,0.0)) return left/right.c;

        throw invalid_argument("divison is out of our assignment's scope");
    }


    ComplexVariable operator== (const ComplexVariable& left, const ComplexVariable& right) {
        return left - right;

    }

    ComplexVariable operator== (const complex<double> n, const ComplexVariable& right) {
        return right - n;

    }
    
    ComplexVariable operator== (const ComplexVariable& left, const complex<double> n) {
        return left - n;

    }

    bool ComplexVariable::operator! () const {
        return (this->a.real() == 0.0) && (this->a.imag() == 0.0) && 
                (this->b.real() == 0.0) && (this->b.imag() == 0.0) &&
                (this->c.real() == 0.0) && (this->c.imag() == 0.0);
    }

    string operator+ (const ComplexVariable& x, const string str) {
        return "("+ to_string(x.a.real()) + "+" + to_string(x.a.imag())  + "i)*x^2 +" + "("+ to_string(x.b.real()) + "+" + to_string(x.b.imag())  + "i)*x +("+ to_string(x.c.real()) + "+" + to_string(x.c.imag())  + "i)" + str;
    }
    
    string operator+ (const string str , const ComplexVariable& x) {
        return str + "("+ to_string(x.a.real()) + "+" + to_string(x.a.imag())  + "i)*x^2 +" + "("+ to_string(x.b.real()) + "+" + to_string(x.b.imag())  + "i)*x +("+ to_string(x.c.real()) + "+" + to_string(x.c.imag())  + "i)";

    }


    // https://www.programiz.com/cpp-programming/examples/quadratic-roots

    double solve(const RealVariable& equation) {
        // cout << "a: " << equation.get_a() << " b: " << equation.get_b() << " c: " << equation.get_c() << endl;

        double a = equation.get_a(), b = equation.get_b(), c = equation.get_c();
        
        if(!equation) return 0;

        if(a == 0) { // The equation is linear
            if ((b == 0) && (c =! 0)) throw runtime_error("There is no solution for this equation");
            else return -c/b;
        }
        
        double x1, discriminant;

        discriminant = b*b - 4*a*c;
    
        if (discriminant >= 0) {
            x1 = (-b + sqrt(discriminant)) / (2*a);
            return x1;
        }
        throw invalid_argument("This equation does not have roots in real numbers:" + equation);
    }

    complex<double> solve(const ComplexVariable& equation) {

        complex<double> a = equation.get_a(), b = equation.get_b(), c = equation.get_c();

        if(!equation) return 0;

        if(a == complex(0.0,0.0)) { // The equation is linear
            if ((b == complex(0.0,0.0)) && (c != complex(0.0,0.0))) throw runtime_error("There is no solution for this equation");
            else return -c/b;
        }
        
        complex<double> x1, discriminant;

        discriminant = b*b - complex(4.0,0.0)*a*c;
    
        x1 = (-b + sqrt(discriminant)) / (complex(2.0,0.0)*a);

        return x1;

    }

    double solve(const bool equation) {
        if(!equation) {
            throw invalid_argument("mathematical error, false phrase");
        }
        else {
            return 0;
        }
    }

    string to_string_complex (const complex<double> c){
        return to_string(c.real()) + "+" + to_string(c.imag())  + "i";
    }
}
