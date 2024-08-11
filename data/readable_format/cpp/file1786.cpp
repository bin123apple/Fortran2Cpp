#include <iostream>

// Function declaration
int factorial(int n);

// Test function declaration
void test_factorial();

int main() {
    // Call the test function
    test_factorial();
    
    return 0;
}

// Factorial function definition
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// A simple function to test the factorial function
void test_factorial() {
    bool all_tests_passed = true;
    
    // Test 1: Factorial of 5
    if(factorial(5) != 120) {
        std::cout << "Test 1 Failed: Factorial of 5 is not 120" << std::endl;
        all_tests_passed = false;
    } else {
        std::cout << "Test 1 Passed" << std::endl;
    }
    
    // Test 2: Factorial of 0 (Edge Case)
    if(factorial(0) != 1) {
        std::cout << "Test 2 Failed: Factorial of 0 is not 1" << std::endl;
        all_tests_passed = false;
    } else {
        std::cout << "Test 2 Passed" << std::endl;
    }
    
    // Overall test results
    if(all_tests_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}