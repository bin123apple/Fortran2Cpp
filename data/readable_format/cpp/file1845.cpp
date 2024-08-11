#include <iostream>

// Function declaration
int factorial(int n);

int main() {
    // Simple manual test for the factorial function
    int testValue = 5;
    int expectedValue = 120; // 5! = 120
    int result = factorial(testValue);

    if (result == expectedValue) {
        std::cout << "Test passed! " << testValue << "! = " << result << std::endl;
    } else {
        std::cout << "Test failed! Expected " << expectedValue << ", got " << result << std::endl;
    }

    return 0;
}

// Function definition
int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}