#include <iostream>
#include <cmath>

namespace constants {
    // Directly define the constant in the same file
    constexpr double PI = 3.1415926535898;
}

int main() {
    double expected_pi = 3.1415926535898;
    // Simple test to check the value of PI
    if (std::abs(constants::PI - expected_pi) > 1.0E-12) {
        std::cerr << "Test Failed: PI does not match the expected value." << std::endl;
        return 1; // Return a non-zero value to indicate failure
    } else {
        std::cout << "Test Passed: PI matches the expected value." << std::endl;
    }

    // The rest of your program can go here

    return 0; // Indicate success
}