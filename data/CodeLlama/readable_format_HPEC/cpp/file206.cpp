#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a type alias for a floating-point type like double
using DATA_TYPE = double;

// Function prototype
void print_array(int n, DATA_TYPE** b);

int main() {
    // Example usage
    int n = 5; // Size of the array
    DATA_TYPE** b = new DATA_TYPE*[n]; // Dynamically allocate 2D array

    // Initialize array b with some values (example initialization)
    for (int i = 0; i < n; ++i) {
        b[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            b[i][j] = i * n + j; // Example initialization
        }
    }

    // Call the function to print the array
    print_array(n, b);

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}

// Function definition
void print_array(int n, DATA_TYPE** b) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << b[j][i] << " ";
            if ((i * n) + j + 1 % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
