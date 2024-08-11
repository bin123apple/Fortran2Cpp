#include <iostream>
#include <cassert>

// Function declaration (optional if the definition is before any call to the function)
int FIBONACCIRECURSIVO(int A);

int main() {
    // Test cases
    assert(FIBONACCIRECURSIVO(0) == 0);
    std::cout << "Test passed for input 0" << std::endl;

    assert(FIBONACCIRECURSIVO(1) == 1);
    std::cout << "Test passed for input 1" << std::endl;

    assert(FIBONACCIRECURSIVO(5) == 5);
    std::cout << "Test passed for input 5" << std::endl;

    assert(FIBONACCIRECURSIVO(10) == 55);
    std::cout << "Test passed for input 10" << std::endl;

    // More tests can be added here

    return 0;
}

// Function definition
int FIBONACCIRECURSIVO(int A) {
    if (A <= 1) {
        return A;
    } else {
        return FIBONACCIRECURSIVO(A-1) + FIBONACCIRECURSIVO(A-2);
    }
}