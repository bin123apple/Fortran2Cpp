#include <iostream>
#include <cassert>
#include <cmath>

double fprati(double p1, double f1, double p2, double f2, double p3, double f3) {
    double h1, h2, h3, p;
    
    if (p3 > 0.0) {
        h1 = f1 * (f2 - f3);
        h2 = f2 * (f3 - f1);
        h3 = f3 * (f1 - f2);
        p = -(p1 * p2 * h3 + p2 * p3 * h1 + p3 * p1 * h2) / (p1 * h1 + p2 * h2 + p3 * h3);
    } else {
        p = (p1 * (f1 - f3) * f2 - p2 * (f2 - f3) * f1) / ((f1 - f2) * f3);
    }
    
    return p;
}

int main() {
    double p1 = 1.0, f1 = 2.0, p2 = 3.0, f2 = 4.0, p3 = 5.0, f3 = 6.0;
    double expected = -1.0; // Updated based on the Fortran output
    double result = fprati(p1, f1, p2, f2, p3, f3);

    std::cout << "C++ Test Result: " << result << std::endl;

    // Assertion to ensure the result matches the expected value
    assert(std::fabs(result - expected) < 1e-6);

    return 0;
}