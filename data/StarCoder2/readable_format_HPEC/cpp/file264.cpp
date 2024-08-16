#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a floating-point type like double
// and DATA_PRINTF_MODIFIER is a format specifier for output, e.g., "%.2f"
void print_array(int n, double* x) {
    // Set precision for floating-point output if necessary
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n + 1; ++i) {
        std::cout << x[i] << " ";
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    // Example usage
    int n = 5; // Size of the array
    double x[] = {1.1, 2.2, 3.3, 4.4, 5.5}; // Example array

    print_array(n, x);

    return 0;
}
