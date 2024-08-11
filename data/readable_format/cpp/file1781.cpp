#include <iostream>
#include <cmath>
#include <iomanip>

// Define the function directly in this file
double specific__tanh_r8(double parm) {
    return tanh(parm);
}

// Test function declaration
void test_specific__tanh_r8(double input, double expected) {
    double result = specific__tanh_r8(input);
    std::cout << "Input: " << input 
              << " Expected: " << expected 
              << " Result: " << result
              << " Test " << (fabs(result - expected) < 1e-6 ? "PASSED" : "FAILED") 
              << std::endl;
}

int main() {
    // Set the precision for better output readability
    std::cout << std::fixed << std::setprecision(6);

    // Test Cases
    test_specific__tanh_r8(0.0, 0.0); // Expected pass
    test_specific__tanh_r8(1.0, tanh(1.0)); // Expected pass
    test_specific__tanh_r8(-1.0, tanh(-1.0)); // Expected pass

    // Add more test cases as needed

    return 0;
}