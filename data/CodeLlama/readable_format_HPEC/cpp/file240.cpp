#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double, int).
// We'll use double for the example.
// DATA_PRINTF_MODIFIER is also a placeholder for the format specifier in Fortran.
// For C++, we'll use std::setprecision for floating-point numbers and fixed for integers.

void print_array(int n, double* x1, double* x2) {
    // Set precision for floating-point numbers to 6 digits after the decimal point
    std::cout << std::fixed << std::setprecision(6);
    
    for (int i = 0; i < n; ++i) {
        std::cout << x1[i] << " " << x2[i] << std::endl;
        if (i % 20 == 0 && i != 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int n = 100; // Example size
    double x1[n], x2[n];
    
    // Initialize arrays with some values
    for (int i = 0; i < n; ++i) {
        x1[i] = i * 1.0; // Example initialization
        x2[i] = i * 2.0; // Example initialization
    }
    
    print_array(n, x1, x2);
    
    return 0;
}
