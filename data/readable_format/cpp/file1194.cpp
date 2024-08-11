#include <iostream>
#include <cassert>

// Recursive factorial function
int factorial(int n) {
    if (n < 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Simple test function for the factorial
void testFactorial() {
    assert(factorial(1) == 1);
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    assert(factorial(4) == 24);
    assert(factorial(5) == 120);
    assert(factorial(6) == 720);
    std::cout << "All tests passed." << std::endl;
}

int main() {
    // Run tests
    testFactorial();
    
    // Example usage of the factorial function
    std::cout << "Factorial of 6 is: " << factorial(6) << std::endl;
    return 0;
}