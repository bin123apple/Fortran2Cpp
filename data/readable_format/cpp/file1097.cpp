#include <iostream>
#include <cmath> // For std::abs

// The psi function definition
double psi(double x, double y) {
    return x * x + y * y;
}

// Simple function to test the psi function
void testPsi(double x, double y, double expected) {
    double result = psi(x, y);
    if (std::abs(result - expected) < 1e-6) { // Simple floating point comparison
        std::cout << "PASS: Test with inputs " << x << ", " << y << " expected " << expected << " and got " << result << "." << std::endl;
    } else {
        std::cout << "FAIL: Test with inputs " << x << ", " << y << " expected " << expected << " but got " << result << "." << std::endl;
    }
}

int main() {
    // Test cases
    testPsi(3.0, 4.0, 25.0);
    testPsi(0.0, 0.0, 0.0);
    testPsi(-5.0, 2.0, 29.0);

    return 0;
}