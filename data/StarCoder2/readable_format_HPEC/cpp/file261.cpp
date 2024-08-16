#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double and DATA_PRINTF_MODIFIER is "%.2f" for simplicity
void print_array(int n, double** x) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << x[j][i] << " "; // Adjusted for 0-based indexing
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    int n = 4; // Example size
    double** x = new double*[n]; // Dynamic allocation of 2D array
    
    // Initialize the array with some values
    for (int i = 0; i < n; ++i) {
        x[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            x[i][j] = i * n + j; // Example values
        }
    }
    
    print_array(n, x);
    
    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] x[i];
    }
    delete[] x;
    
    return 0;
}
