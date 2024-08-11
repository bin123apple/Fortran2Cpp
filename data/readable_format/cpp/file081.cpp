#include <iostream>
#include <cmath> // For std::asin

// Function declaration and definition
float specific__asin_r4(float parm) {
    return std::asin(parm); // Use std::asin to compute the arc sine
}

int main() {
    // Test 1: asin(0.0) = 0.0
    float input = 0.0f;
    float expected = 0.0f;
    float output = specific__asin_r4(input);
    if (std::abs(output - expected) < 1e-7f) {
        std::cout << "Test 1 Passed" << std::endl;
    } else {
        std::cout << "Test 1 Failed" << std::endl;
    }

    // Test 2: asin(0.5) = π/6
    input = 0.5f;
    expected = M_PI / 6; // Approximately π/6
    output = specific__asin_r4(input);
    if (std::abs(output - expected) < 1e-7f) {
        std::cout << "Test 2 Passed" << std::endl;
    } else {
        std::cout << "Test 2 Failed" << std::endl;
    }

    return 0;
}