#include <iostream>
#include <cassert>

// Declaration of the fibonacci function to ensure it's recognized
int fibonacci(int a) {
    if (a <= 1) {
        return a;
    } else {
        return fibonacci(a - 1) + fibonacci(a - 2);
    }
}

void testFibonacci() {
    // Test case 1: Fibonacci of 0
    assert(fibonacci(0) == 0);
    std::cout << "Test case 1 passed: Fibonacci of 0 is 0" << std::endl;

    // Test case 2: Fibonacci of 1
    assert(fibonacci(1) == 1);
    std::cout << "Test case 2 passed: Fibonacci of 1 is 1" << std::endl;

    // Test case 3: Fibonacci of 10
    assert(fibonacci(10) == 55);
    std::cout << "Test case 3 passed: Fibonacci of 10 is 55" << std::endl;

    // Add more test cases as needed
}

int main() {
    testFibonacci();
    return 0;
}