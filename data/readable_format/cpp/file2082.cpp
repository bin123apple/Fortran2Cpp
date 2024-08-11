#include <iostream>
#include <cmath> // For fabs()

// Function to be tested
double square(double x) {
    return x * x;
}

// A simple test function
void testSquare() {
    double x = 4.0;
    double expected = 16.0;
    double result = square(x);

    if (fabs(result - expected) < 1e-6) {
        std::cout << "Test passed: square(" << x << ") = " << result << std::endl;
    } else {
        std::cerr << "Test failed: square(" << x << ") = " << result
                  << " (expected " << expected << ")" << std::endl;
    }
}

int main() {
    // Run the test
    testSquare();

    // Any other main code goes here

    return 0;
}