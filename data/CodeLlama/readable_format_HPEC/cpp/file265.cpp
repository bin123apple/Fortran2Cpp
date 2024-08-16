#include <iostream>
#include <iomanip> // For std::setprecision if needed

// Assuming DATA_TYPE is double for this example, adjust as necessary.
using DATA_TYPE = double;
const char* DATA_PRINTF_MODIFIER = "%g"; // Adjust the format specifier as needed.

void print_array(int n, DATA_TYPE** x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Print the element
            std::cout << std::setw(12) << x[j][i] << " ";
            
            // Check if a new line is needed
            if (((i * n) + j) % 20 == 0 && i != 0 && j != 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example usage
    const int n = 4; // Matrix size
    DATA_TYPE** x = new DATA_TYPE*[n];
    for (int i = 0; i < n; ++i) {
        x[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            // Initialize matrix elements with some values
            x[i][j] = static_cast<DATA_TYPE>(i * n + j);
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
