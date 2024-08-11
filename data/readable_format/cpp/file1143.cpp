#include <iostream>
#include <cmath> // For fabs

// Namespace to mimic the module functionality
namespace modE {
    // Simple function to be tested
    double square(double x) {
        return x * x;
    }
}

// Simple manual test function
void testSquareFunction() {
    double input = 2.0;
    double expectedOutput = 4.0;
    double result = modE::square(input);

    if (std::fabs(result - expectedOutput) < 1e-6) { // Using a small tolerance for floating point comparison
        std::cout << "Test passed: Square of " << input << " is " << result << std::endl;
    } else {
        std::cout << "Test failed: Square of " << input << " is " << result << ", expected " << expectedOutput << std::endl;
    }
}

// Main function demonstrating the use and testing of the 'square' function
int main() {
    // You can call your functions here to demonstrate their use
    double value = 3.0;
    std::cout << "The square of " << value << " is " << modE::square(value) << std::endl;

    // Call the manual test function
    testSquareFunction();

    return 0;
}