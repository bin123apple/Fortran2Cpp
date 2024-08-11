// factorial_with_test.cpp
#include <iostream>

// Function declaration
int factorial(int n);

// Main function for testing
int main() {
    int result = factorial(5);

    // Test the factorial function with a known input and output
    if (result == 120) {
        std::cout << "C++ Test Passed: Factorial of 5 is 120." << std::endl;
    } else {
        std::cout << "C++ Test Failed." << std::endl;
    }

    return 0;
}

// Function definition
int factorial(int n) {
    if (n == 0) return 1; // Adding base case for n=0
    int fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}