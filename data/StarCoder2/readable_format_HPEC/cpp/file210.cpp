#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double and DATA_PRINTF_MODIFIER is "%.2f" for floating-point numbers
// If DATA_TYPE is of a different type, adjust the type accordingly.
void print_array(int n, double* x) {
    for (int i = 0; i < n; ++i) {
        std::cout << std::fixed << std::setprecision(2) << x[i] << " "; // Adjust precision as needed
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}

// Example usage
int main() {
    const int n = 5; // Example size
    double x[n] = {1.1, 2.2, 3.3, 4.4, 5.5}; // Example array

    print_array(n, x);

    return 0;
}
