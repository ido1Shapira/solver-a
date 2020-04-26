#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

// Id of collaborators 208825539 207950577

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