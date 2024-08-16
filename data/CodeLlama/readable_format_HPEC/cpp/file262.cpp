#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string
using DATA_TYPE = double; // Example type
const std::string DATA_PRINTF_MODIFIER = "%.6f "; // Example format string

void print_array(int nx, int ny, DATA_TYPE** ex, DATA_TYPE** ey, DATA_TYPE** hz) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            std::cout << ex[j][i] << ey[j][i] << hz[j][i];
            if ((i * nx + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Note: The memory for the 2D arrays ex, ey, and hz should be allocated and deallocated outside this function.
