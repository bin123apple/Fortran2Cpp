#include <iostream>
#include <cmath>
#include <limits>

// Function definition directly in this file
float f(float x) {
    return std::sin(x);
}

int main() {
    float input = 1.0;
    float expected = std::sin(input); // Expected result for sin(1)
    float result = f(input);
    float tolerance = std::numeric_limits<float>::epsilon() * 100; // Adjust tolerance for floating point comparison

    std::cout << "Testing f(1.0)..." << std::endl;

    if (std::abs(result - expected) < tolerance) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Got: " << result << std::endl;
    }

    return 0;
}