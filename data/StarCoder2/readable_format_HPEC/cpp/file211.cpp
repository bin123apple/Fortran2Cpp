#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double for this example
void print_array(int n, double* y) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        std::cout << y[i] << " ";
        if ((i + 1) % 20 == 0) { // Adjusted for zero-based indexing
            std::cout << std::endl;
        }
    }
}

// Example usage
int main() {
    const int n = 5;
    double y[n] = {1.1, 2.2, 3.3, 4.4, 5.5};
    print_array(n, y);
    return 0;
}
