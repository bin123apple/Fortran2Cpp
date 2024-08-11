#include <iostream>
#include <cmath> // For std::fabs

// The function to be tested
float cvmgz(float trueVal, float falseVal, float test) {
    return (test == 0.0f) ? trueVal : falseVal;
}

// A simple test function
void testCvmgz(float trueVal, float falseVal, float test, float expected, const std::string& testName) {
    float result = cvmgz(trueVal, falseVal, test);
    if (std::fabs(result - expected) < 1e-6) { // Comparing floating-point numbers
        std::cout << "PASSED: " << testName << std::endl;
    } else {
        std::cout << "FAILED: " << testName << " - Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    // Running test cases
    testCvmgz(1.0f, 2.0f, 0.0f, 1.0f, "Test 1: test == 0.0");
    testCvmgz(1.0f, 2.0f, 1.0f, 2.0f, "Test 2: test != 0.0");
    
    return 0;
}