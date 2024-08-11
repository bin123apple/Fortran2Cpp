#include <cmath>
#include <cassert>
#include <iostream>

double dpowint(double xlow, double xhigh, double ylow, double yhigh, double xval, double pow) {
    const double EPSLON = 1.0e-20;

    if (std::abs(xhigh - xlow) < EPSLON) {
        return (yhigh + ylow) / 2.0;
    } else {
        return ylow + (yhigh - ylow) * std::pow((xval - xlow) / (xhigh - xlow), pow);
    }
}

int main() {
    // Allow a small margin of error for floating-point comparisons
    const double epsilon = 1e-6;

    // Test cases
    assert(std::abs(dpowint(1.0, 1.0, 2.0, 3.0, 1.5, 2.0) - 2.5) < epsilon);
    assert(std::abs(dpowint(1.0, 2.0, 2.0, 4.0, 1.5, 1.0) - 3.0) < epsilon);
    assert(std::abs(dpowint(0.0, 10.0, 0.0, 100.0, 5.0, 2.0) - 25.0) < epsilon);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}