#include <iostream>
#include <cmath> // For std::abs

// Declaration of the QuadraticParameters class
class QuadraticParameters {
public:
    double a, b, c; // Parameters a, b, c

    // Constructor to initialize parameters with default values
    QuadraticParameters() : a(0.0), b(0.0), c(0.0) {}

    // Method to set parameters a, b, c
    void set(double new_a, double new_b, double new_c) {
        a = new_a;
        b = new_b;
        c = new_c;
    }

    // Method to calculate the quadratic value
    double quadratic(double x) {
        return a * x * x + b * x + c;
    }
};

int main() {
    // Create an instance of the QuadraticParameters class
    QuadraticParameters qp;
    
    // Set the parameters: a=1, b=-3, c=2 (roots are x=1 and x=2)
    qp.set(1.0, -3.0, 2.0);
    
    // Test value
    double x = 1.0;
    
    // Calculate the result
    double result = qp.quadratic(x);
    
    // Check the result (allowing for a small numerical error margin)
    const double epsilon = 1e-7;
    if (std::abs(result - 0.0) < epsilon) {
        std::cout << "Test passed: quadratic(1) = 0" << std::endl;
    } else {
        std::cout << "Test failed: quadratic(1) != 0, result = " << result << std::endl;
    }

    return 0;
}