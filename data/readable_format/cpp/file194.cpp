#include <iostream>
#include <cmath>
#include <limits>
#include <string>

// Function to truncate the floating-point number
float specific_aint_r4(float parm) {
    return std::trunc(parm);
}

// Simple test function to compare the function output with the expected output
void test_specific_aint_r4(float input, float expected, const std::string& test_name) {
    float result = specific_aint_r4(input);
    if (std::abs(result - expected) < std::numeric_limits<float>::epsilon()) {
        std::cout << test_name << ": Passed" << std::endl;
    } else {
        std::cout << test_name << ": Failed - Expected: " << expected << ", Got: " << result << std::endl;
    }
}

int main() {
    // Running tests
    std::cout << "Starting tests..." << std::endl;
    test_specific_aint_r4(123.456f, 123.0f, "Test positive value");
    test_specific_aint_r4(-123.456f, -123.0f, "Test negative value");
    test_specific_aint_r4(0.0f, 0.0f, "Test zero");
    test_specific_aint_r4(0.0001f, 0.0f, "Test very small positive value");
    test_specific_aint_r4(-0.0001f, 0.0f, "Test very small negative value");

    std::cout << "Testing completed." << std::endl;
    return 0;
}