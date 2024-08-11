#include <iostream>
#include <cmath> // Include to use math functions like acos, cos, sqrt, exp, and log

int main() {
    double pi, x, y; // In C++, 'real' type in Fortran is mostly equivalent to 'double' in C++

    pi = acos(-1.0); // Calculate pi using acos

    x = cos(pi); // Calculate cosine of pi
    y = pow(sqrt(exp(log(pi))), 2); // Calculate square of the square root of (e raised to the power of log pi)

    std::cout << "pi = " << pi << std::endl; // Print pi
    std::cout << "x = " << x << std::endl; // Print x
    std::cout << "y = " << y << std::endl; // Print y

    return 0;
}