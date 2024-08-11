// factorial_with_test.cpp
#include <iostream>

// Function Declaration
int factorial(int n);

// Main Function - Also includes a simple manual test for the factorial function
int main() {
    int testValue = 5;
    int expectedFactorial = 120; // We know 5! = 120
    int calculatedFactorial = factorial(testValue);

    std::cout << "Testing factorial(" << testValue << "): expected result = " << expectedFactorial
              << ", calculated result = " << calculatedFactorial << std::endl;

    if (calculatedFactorial == expectedFactorial) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }

    return 0;
}

// Function Definition
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}