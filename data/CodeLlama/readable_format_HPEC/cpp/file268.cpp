#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a floating-point type like double, change if necessary
using DATA_TYPE = double;

// Function prototype
void print_array(int n, const std::vector<DATA_TYPE>& x);

int main() {
    // Example usage
    int n = 100; // Example size
    std::vector<DATA_TYPE> x(n + 1); // Create a vector with n + 1 elements
    
    // Initialize the vector with some values (example initialization)
    for (int i = 0; i < n + 1; ++i) {
        x[i] = static_cast<DATA_TYPE>(i); // Example initialization
    }

    // Call the function
    print_array(n, x);

    return 0;
}

// Function definition
void print_array(int n, const std::vector<DATA_TYPE>& x) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < n + 1; ++i) {
        std::cout << x[i] << " ";
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}
