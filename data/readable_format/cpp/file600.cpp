#include <iostream>
#include <cmath>
#include <algorithm>

// DLAPY3 function definition
double DLAPY3(double X, double Y, double Z) {
    const double ZERO = 0.0;
    double W, XABS, YABS, ZABS;

    XABS = std::abs(X);
    YABS = std::abs(Y);
    ZABS = std::abs(Z);

    W = std::max({XABS, YABS, ZABS});

    if (W == ZERO) {
        return ZERO;
    } else {
        return W * std::sqrt(std::pow((XABS / W), 2) + std::pow((YABS / W), 2) + std::pow((ZABS / W), 2));
    }
}

// Main function with unit tests
int main() {
    const double error = 1e-10;

    // Test 1
    if (std::abs(DLAPY3(1.0, 2.0, 2.0) - 3.0) > error) {
        std::cout << "Test 1 Failed" << std::endl;
    } else {
        std::cout << "Test 1 Passed" << std::endl;
    }

    // Test 2
    if (std::abs(DLAPY3(0.0, 0.0, 0.0) - 0.0) > error) {
        std::cout << "Test 2 Failed" << std::endl;
    } else {
        std::cout << "Test 2 Passed" << std::endl;
    }

    // Test 3
    if (std::abs(DLAPY3(-3.0, 4.0, 0.0) - 5.0) > error) {
        std::cout << "Test 3 Failed" << std::endl;
    } else {
        std::cout << "Test 3 Passed" << std::endl;
    }

    return 0;
}