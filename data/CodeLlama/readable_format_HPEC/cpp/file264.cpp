#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double and DATA_PRINTF_MODIFIER is a format string for output
void print_array(int nx, int ny, double* s, double* q) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    // Printing array s
    for (int i = 0; i < ny; ++i) {
        std::cout << s[i];
        if ((i + 1) % 80 == 0) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    // Printing array q
    for (int i = 0; i < nx; ++i) {
        std::cout << q[i];
        if ((i + 1) % 80 == 0) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int nx = 10; // Example size for array q
    int ny = 5;  // Example size for array s
    double s[] = {1.1, 2.2, 3.3, 4.4, 5.5}; // Example array s
    double q[] = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.10}; // Example array q

    print_array(nx, ny, s, q);

    return 0;
}
