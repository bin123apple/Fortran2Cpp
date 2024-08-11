#include <iostream>
#include <cmath> // For fabs (floating-point absolute value)

// Define the function great_rsd to perform some operation; here it sums two numbers.
double great_rsd(double a, double b) {
    return a + b;
}

// A simple function to test the great_rsd function with expected outcomes.
void test_great_rsd(double a, double b, double expected) {
    double result = great_rsd(a, b);
    if (fabs(result - expected) < 1e-6) { // Using floating-point comparison with a tolerance
        std::cout << "Test passed: great_rsd(" << a << ", " << b << ") == " << expected << std::endl;
    } else {
        std::cout << "Test failed: great_rsd(" << a << ", " << b << ") != " << expected << "; got " << result << std::endl;
    }
}

int main() {
    // Test cases for the great_rsd function
    test_great_rsd(1.0, 2.0, 3.0);
    test_great_rsd(-1.0, -2.0, -3.0);
    test_great_rsd(-1.0, 2.0, 1.0);
    test_great_rsd(0.0, 0.0, 0.0);
    test_great_rsd(123.456, 654.321, 777.777);

    return 0;
}