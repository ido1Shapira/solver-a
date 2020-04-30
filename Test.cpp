#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

// Id of collaborators 208825539 207950577


TEST_CASE("RealVarivale , linear equations") {
    RealVariable x;

    CHECK(solve(2 == 2) == 0);
    CHECK(solve(2*x-4 == 10) == 7);
    CHECK(solve(x*2-4 == 10) == 7);
    CHECK(solve(-4+2*x == 10) == 7);
    CHECK(solve(2*x-2-2 == 10) == 7);
    CHECK(solve((1+1)*x-4 == 10) == 7);
    CHECK(solve(2*x-4 == 5+5) == 7);
    CHECK(solve(2*x-4 == 2*5) == 7);
    CHECK(solve(2*x-4 == pow(2,2)+6) == 7);
    CHECK(solve(2*x-4 == 14-4) == 7);
    CHECK(solve(x+x-4 == 10) == 7);
    CHECK(solve(3*x-x-4 == 10) == 7);
    CHECK(solve(4*x-2*x-4 == 10) == 7);
    CHECK(solve(2*x-4 == 10) == 7);
    CHECK(solve(1*x + 2*x - x -4 == 10) == 7);
    CHECK(solve(10 == 2*x - 4) == 7);
    CHECK(solve(3*x -4 == 10+x) == 7);
    CHECK(solve(2*x/2-4 == 10-x) == 7);
    CHECK(solve((2 + 2*x)/2 -5 == 10) == 14);
    CHECK(solve(4*x-2 == 10 + 2*x -2) == 5);
    CHECK(solve(2*x-4.0 == 10.0) == 7);
    CHECK(solve(2.0*x-4.0 == 10) == 7);
    CHECK(solve(-2*x-4.0 == 10.0) == -7);

    CHECK(solve(-x-4.0 == 10.0) == -14);
    CHECK(solve(x == 1) == 1);
    CHECK(solve(x+3 == 3) == 0);
    CHECK(solve(x-4.0 == 10.0) == 14);
    CHECK(solve(x+x == 2*x) == 0);
    CHECK(solve(2*x - x == 2) == 2);
    CHECK(solve(3*x - 2*x == 0) == 0);
    CHECK(solve(2*x == x*3) == 0);

}

TEST_CASE("RealVariable , polinomial equations") {
    RealVariable x;
    
    CHECK(((solve((x^2) == 16) == 4) || (solve((x^2) == 16) == -4)));
    CHECK(((solve((x^2) + 2 == 18) == 4) || (solve((x^2) + 2 == 18) == -4)));
    CHECK(((solve(2*(x^2) == 32) == 4) || (solve(2*(x^2) == 32) == -4)));
    CHECK(((solve((x^2)*2 == 32) == 4) || (solve((x^2)*2 == 32) == -4)));
    CHECK(((solve(2*(x^2) + 2 == 34) == 4) || (solve(2*(x^2) +2 == 34) == -4)));
    CHECK(((solve((x^2) + x/x == 17) == 4) || (solve((x^2) + x/x == 17) == -4)));
    CHECK(((solve((x^2) + 2*x/2 == 16 + x) == 4) || (solve((x^2) + 2*x/2 == 16 + x) == -4)));
    CHECK(((solve(x*x == 16) == 4) || (solve(x*x == 16) == -4)));
    CHECK(((solve(x*x + (x+x)/2 == 16 +x) == 4) || (solve(x*x + (x+x)/2 == 16 + x) == -4)));
    CHECK(((solve((x+1)*(x+1) == 16 + x*2 + 1) == 4) || (solve((x+1)*(x+1) == 16 + x*2 +1) == -4)));
    CHECK(((solve((x^2) == 16.0) == 4) || (solve((x^2) == 16.0) == -4)));
    CHECK(((solve((x^2) + 0*x == 16) == 4) || (solve((x^2) + 0*x == 16) == -4)));
    CHECK(((solve(0*(x^2) + (x^2) == 16) == 4) || (solve(0*(x^2) + (x^2) == 16) == -4)));
    CHECK(((solve((x^2)/x + (x^2) == 16 + x) == 4) || (solve((x^2)/x + (x^2) == 16 + x) == -4)));
    CHECK(((solve((x^2)*2/2 == 16) == 4) || (solve((x^2)*2/2 == 16) == -4)));
    CHECK(((solve(2*(x^2)/2 == 16) == 4) || (solve(2*(x^2)/2 == 16) == -4)));
    CHECK(((solve(0*(x^2)/3 + (x^2) == 16) == 4) || (0*solve((x^2)/3 + (x^2) == 16) == -4)));
    CHECK(((solve(2*(x^2) + x+x +1 == 17 + (x^2) + 2*x) == 4) || (solve((x^2) + x+x +1 == 17 +(x^2) +2*x) == -4)));
    CHECK(((solve((x^2) - 16 == 0) == 4) || (solve((x^2) - 16 == 0) == -4)));
    CHECK(((solve(0 == (x^2) - 16) == 4) || (solve(0 == (x^2) - 16) == -4)));
    CHECK(((solve((x^2) == 16) == 4) || (solve((x^2) == 16) == -4)));
    CHECK(((solve((x^1)*x == 16) == 4) || (solve((x^1)*x == 16) == -4)));
    CHECK(((solve((x^0) + (x^2) == 16) == 4) || (solve(((x^0) + (x^2) == 16) == -4))));
    CHECK(((solve((x^0) * (x^2) == 16) == 4) || (solve(((x^0) * (x^2) == 16) == -4))));
    CHECK(((solve((x^1) * (x^1) == 16) == 4) || (solve((x^1) *(x^1) == 16) == -4)));
    CHECK(((solve((x^2) -x == 16 - x) == 4) || (solve((x^2) -x == 16-x) == -4)));
    CHECK((solve((x^2) == 0) == 0));
    CHECK(solve((x^2)/x == 1) == 1);

}

TEST_CASE("edge-cases checks throws for real numbers"){
    RealVariable x;

    CHECK_THROWS(solve((x^2)/0 == 16));
    CHECK_THROWS(solve((x^2)/(x-x) == 16));
    CHECK_THROWS(solve((x^2)*x == 0));
    CHECK_THROWS(solve((x^1)/x == 0));
    CHECK_THROWS(solve((x^3) == 0));
    CHECK_THROWS(solve((x^2)*x == 0));
    CHECK_THROWS(solve((x^-1) == 0));
    CHECK_THROWS(solve((x^2)*(x^1) == 0));
    CHECK_THROWS(solve(2 == 3));

    CHECK_THROWS(solve(x-x == 2));
    CHECK_THROWS(solve(x/x == 2));
    CHECK_THROWS(solve(x/(x-1) == 1));
    CHECK_THROWS(solve(x-x == 2));
    CHECK_THROWS(solve(2*x + 2 == 3 + 2*x));
    CHECK_THROWS(solve(2*x/0 == 2));
    CHECK_THROWS(solve(2*x/(2-2) == 2));
    CHECK_THROWS(solve((x+1)*(x^2) == 2));

    // RealVariable y;
    // CHECK_THROWS(solve( x + y == 2));

}


TEST_CASE("linear complex equation for complex numbers"){
    ComplexVariable y;
  
    CHECK(solve(y+y-2 == 10) == complex(6.0,0.0));
    CHECK(solve(4*y-8 == 10*y+complex(4.0, -12.0)) == complex(-2.0,2.0));
    CHECK(solve(3*y*7+21 == complex(0.0, -21.0)) == complex(-1.0,-1.0));
    CHECK(solve(7+5-4*3*y == 18) == complex(-0.5,0.0));
    CHECK(solve(y+13 == 7) == complex(-6.0,0.0));
    CHECK(solve(2*y-y*3 == 15) == complex(-15.0,0.0));
    CHECK(solve(y+2-y-2 == y) == complex(0.0,0.0));
    CHECK(solve(56*y+8 == complex(8.0, -56.0)) == complex(0.0,-1.0));
    CHECK(solve(5*y == 6*y) == complex(0.0,0.0));
    CHECK(solve(4*y+12 == 0) == complex(-3.0,0.0));
  
}

TEST_CASE("polinomial complex equation"){
    ComplexVariable z;
    CHECK((solve((z^2)*2-8*z== complex(10.0,-20.0)+complex(0.0,12.0)*z) == complex(3.0, 4.0) || 
            solve((z^2)*2-8*z== complex(10.0,-20.0)+complex(0.0,12.0)*z) == complex(1.0, 2.0)) );
    CHECK((solve((z^2) +2*z +1== 1) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    CHECK((solve(5*(z^2) -8*z +5 == 0) == complex(0.8,0.6) || solve(5*(z^2) -8*z +5 == 0) == complex(0.8,-0.6)));
    CHECK((solve((z^2) +9 == 0) == complex(0.0,3.0) || solve((z^2) +9 == 0) == complex(0.0,-3.0)));
    CHECK((solve((z^2) +4*z +7 == 0) == complex(-2.0,-sqrt(3)) || solve((z^2) +4*z +7 == 0) == complex(-2.0,sqrt(3))));
    CHECK((solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,sqrt(6)/5) || solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,-sqrt(6)/5)));
    CHECK((solve(0*(z^2) +3*z +27 == 0) == complex(-9.0,0.0) ));
    CHECK((solve((z^2)/2 +z +14 == 0) == complex(-1.0,3*sqrt(3)) || solve((z^2)/2 +z +14 == 0) == complex(-1.0,-3*sqrt(3))));
    CHECK((solve((z^2)*8 +56*z +16 == 0) == complex(-(7+sqrt(41))/2,0.0) || solve((z^2)*8 +56*z +16 == 0) == complex((-7+sqrt(41))/2,0.0)));
    CHECK((solve(2*(z^2) +4*z +9== 8+2/2) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    CHECK((solve(6*(z^2)/2 +2*z*3 +90== 90) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    CHECK((solve((z^2)*2-(z^2) +2*z*8- 14*z +1== 1) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));

}
TEST_CASE("edge-cases checks throws for complex numbers"){
    ComplexVariable w;
    CHECK_THROWS(solve(4*w/0+12 == 0));
    CHECK_THROWS(solve(4*w-4*w+12 == 0));
    CHECK_THROWS(solve(4*(w^6)+12 == 0));
    CHECK_THROWS(solve(4*w*9+(w^3)+12==9));
    CHECK_THROWS(solve(4*w+w/0+12.0 == 0));
    CHECK_THROWS(solve(4*w+12 == w*4));
    CHECK_THROWS(solve(4*(w^2)+12 == 8*(w^2)/2));
    CHECK_THROWS(solve(4*w+0.0 == 4*w+9));
    CHECK_THROWS(solve(4*(w^4)*7+12 == 28*(w^2)));
    CHECK_THROWS(solve(4*w-3*w/0 == 0));

}

TEST_CASE("demo tests") {
    RealVariable x;

    CHECK(solve(2*x-4 == 10) == 7);
    CHECK(((solve((x^2) == 16) == 4) || (solve((x^2) == 16) == -4)));
    CHECK_THROWS(solve((x^2) == -16));
    CHECK(((solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) == 4) || (solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) == -4)));
    CHECK(solve(2*x-4.0 == 10.0) == 7);

    ComplexVariable y;
    CHECK(solve(2*y-4 == 10) == complex(7.0,0.0));
    CHECK(((solve((y^2) == 16) == complex(4.0,0.0)) || (solve((y^2) == 16) == complex(-4.0,0.0))));
    CHECK(((solve((y^2) == -16) == complex(0.0,4.0)) || (solve((y^2) == -16) == complex(0.0,-4.0))));
    CHECK(((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) == complex(4.0,0.0)) || (solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) == complex(-4.0,0.0))));
    CHECK(solve(y+5i == 2*y+3i) == complex(0.0,2.0));
    
}