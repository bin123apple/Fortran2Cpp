#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <limits>
#include <cctype>

double DLAMC3(double A, double B) {
    return A + B;
}

double DLAMCH(char CMACH) {
    double ONE = 1.0, ZERO = 0.0;

    double EPS = std::numeric_limits<double>::epsilon();
    double SFMIN = std::numeric_limits<double>::min();
    double SMALL = ONE / std::numeric_limits<double>::max();
    double RMACH = ZERO;

    switch (std::toupper(CMACH)) {
    case 'E':
        RMACH = EPS;
        break;
    case 'S':
        RMACH = SFMIN;
        break;
    case 'B':
        RMACH = FLT_RADIX;
        break;
    case 'P':
        RMACH = EPS * FLT_RADIX;
        break;
    case 'N':
        RMACH = std::numeric_limits<double>::digits;
        break;
    case 'R':
        RMACH = ONE; // Assuming rounding mode to nearest as Fortran RND variable is not explicitly defined
        break;
    case 'M':
        RMACH = std::numeric_limits<double>::min_exponent;
        break;
    case 'U':
        RMACH = SFMIN;
        break;
    case 'L':
        RMACH = std::numeric_limits<double>::max_exponent;
        break;
    case 'O':
        RMACH = std::numeric_limits<double>::max();
        break;
    default:
        RMACH = ZERO;
        break;
    }

    return RMACH;
}

int main() {
    std::cout << "Testing DLAMC3(1.0, 2.0)... Result: " << DLAMC3(1.0, 2.0) << std::endl;

    const char test_chars[] = {'E', 'S', 'B', 'P', 'N', 'R', 'M', 'U', 'L', 'O', 'X', '\0'};
    for (const char* ch = test_chars; *ch != '\0'; ++ch) {
        std::cout << "Testing DLAMCH(" << *ch << ")... Result: " << std::setprecision(10) << DLAMCH(*ch) << std::endl;
    }

    return 0;
}