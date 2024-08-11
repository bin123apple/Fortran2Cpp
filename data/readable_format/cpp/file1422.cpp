#include <iostream>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int testNumber = 5;
    int expectedResult = 120;
    int result = factorial(testNumber);
    if (result == expectedResult) {
        std::cout << "Test passed: 5! = 120" << std::endl;
    } else {
        std::cout << "Test failed: 5! is not 120, result is " << result << std::endl;
    }
    return 0;
}