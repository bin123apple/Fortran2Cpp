#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string for std::cout
using DATA_TYPE = double; // Example type, adjust according to your needs
const std::string DATA_PRINTF_MODIFIER = "%.2f "; // Example format string, adjust according to your needs

void print_array(int n, DATA_TYPE** path) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << DATA_PRINTF_MODIFIER << path[j][i];

            if ((i * n) + j + 1 % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n = 5; // Size of the array
    DATA_TYPE** path = new DATA_TYPE*[n]; // Dynamically allocate 2D array

    // Initialize the array with some values (example initialization)
    for (int i = 0; i < n; ++i) {
        path[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            path[i][j] = static_cast<DATA_TYPE>(i * n + j); // Example initialization
        }
    }

    print_array(n, path);

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] path[i];
    }
    delete[] path;

    return 0;
}
