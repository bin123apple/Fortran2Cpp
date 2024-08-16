#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a floating-point type like double
// and DATA_PRINTF_MODIFIER is a format specifier for output
// For example, if DATA_TYPE is double and DATA_PRINTF_MODIFIER is "%.2f",
// then we would use std::fixed and std::setprecision(2) for formatting.

void print_array(int m, double** symmat) {
    // Assuming symmat is a dynamically allocated 2D array of size m x m
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::fixed << std::setprecision(2) << symmat[j][i] << " ";
            if ((i * m + j + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int m = 4; // Example size
    double** symmat = new double*[m];
    for (int i = 0; i < m; ++i) {
        symmat[i] = new double[m];
        // Initialize symmat with some values for demonstration
        for (int j = 0; j < m; ++j) {
            symmat[i][j] = i * m + j + 1; // Example values
        }
    }

    print_array(m, symmat);

    // Clean up
    for (int i = 0; i < m; ++i) {
        delete[] symmat[i];
    }
    delete[] symmat;

    return 0;
}
