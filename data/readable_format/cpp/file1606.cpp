#include <iostream>
#include <cmath> // For std::abs

// Function declaration
float square(float x);

// Simple test function to demonstrate the concept without an external testing framework
void testSquare() {
    float inputValue = 4.0;
    float expectedValue = 16.0;
    float result = square(inputValue);
    
    if (std::abs(result - expectedValue) < 0.001) {
        std::cout << "Test passed: Square of " << inputValue << " is " << result << std::endl;
    } else {
        std::cout << "Test failed: Square of " << inputValue << " is " << result << "; Expected: " << expectedValue << std::endl;
    }
}

// Main function
int main() {
    testSquare();
    return 0;
}

// Function definition
float square(float x) {
    return x * x;
}