#include <iostream>
#include <cmath>
#include <cstdlib> // For std::abs

// Assuming the custom type and constants are defined directly in this file
using wp = double; // Custom real type
constexpr wp pi = 4.0 * std::atan(1.0);
constexpr wp f_actual = -9.02462E-6;

// Definitions of functions f1, f2, and f directly in this file
namespace functions {

wp f1(wp x) {
    return std::sin(x) / (1.0 + 2.0 * std::exp(2.0 * x));
}

wp f2(wp x) {
    return (x * x - 3.0 * x) / ((x * x + 1.0) * (x * x + 2.0));
}

wp f(wp x, wp y) {
    return f2(x) * f1(y);
}

} // namespace functions

// A simple function for comparison within a tolerance
bool nearlyEqual(wp a, wp b, wp tolerance = 1e-6) {
    return std::abs(a - b) <= tolerance;
}

// Main function to perform tests
int main() {
    bool all_tests_passed = true;

    // Test f1
    {
        wp x = 0.5;
        wp expected = std::sin(x) / (1.0 + 2.0 * std::exp(2.0 * x));
        if (!nearlyEqual(functions::f1(x), expected)) {
            std::cerr << "Test f1 FAILED." << std::endl;
            all_tests_passed = false;
        } else {
            std::cout << "Test f1 PASSED." << std::endl;
        }
    }

    // Test f2
    {
        wp x = 0.5;
        wp expected = (x * x - 3.0 * x) / ((x * x + 1.0) * (x * x + 2.0));
        if (!nearlyEqual(functions::f2(x), expected)) {
            std::cerr << "Test f2 FAILED." << std::endl;
            all_tests_passed = false;
        } else {
            std::cout << "Test f2 PASSED." << std::endl;
        }
    }

    // Test f
    {
        wp x = 0.5;
        wp y = 0.7;
        wp expected = functions::f2(x) * functions::f1(y);
        if (!nearlyEqual(functions::f(x, y), expected)) {
            std::cerr << "Test f FAILED." << std::endl;
            all_tests_passed = false;
        } else {
            std::cout << "Test f PASSED." << std::endl;
        }
    }

    if (all_tests_passed) {
        std::cout << "All tests PASSED." << std::endl;
    } else {
        std::cerr << "Some tests FAILED." << std::endl;
    }

    return all_tests_passed ? 0 : 1;
}