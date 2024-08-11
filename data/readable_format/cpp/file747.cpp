#include <iostream>
#include <cmath>
#include <string>

// Function definition
float specific__log10_r4(float parm) {
    return std::log10(parm);
}

// Simplified test function
void test_specific__log10_r4(float input, float expected, float epsilon, const std::string& test_name) {
    float result = specific__log10_r4(input);
    if (std::abs(result - expected) <= epsilon) {
        std::cout << test_name << " passed." << std::endl; // Corrected line
    } else {
        std::cout << test_name << " failed: Expected " << expected << ", got " << result << "." << std::endl; // Corrected line
    }
}

int main() {
    // Test parameters
    const float epsilon = 1e-5f;

    // Test cases
    test_specific__log10_r4(10.0f, 1.0f, epsilon, "Test 1: Log10 of 10");
    test_specific__log10_r4(100.0f, 2.0f, epsilon, "Test 2: Log10 of 100");
    test_specific__log10_r4(1.0f, 0.0f, epsilon, "Test 3: Log10 of 1");

    return 0;
}