#include <iostream>
#include <cassert> // For assert to do basic testing

// Function declaration
int factorial(int n);

// Simple test function declaration
void testFactorial();

int main() {
    // Run tests
    testFactorial();
    
    // Main program logic
    int number;
    std::cout << "Enter a number to calculate factorial: ";
    std::cin >> number;
    std::cout << "The factorial of " << number << " is " << factorial(number) << std::endl;
    
    return 0;
}

// Function definition
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Simple test function definition
void testFactorial() {
    assert(factorial(0) == 1); // Test case for factorial of 0
    assert(factorial(1) == 1); // Test case for factorial of 1
    assert(factorial(5) == 120); // Test case for factorial of 5
    
    std::cout << "All tests passed." << std::endl;
}