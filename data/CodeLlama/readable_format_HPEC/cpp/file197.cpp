#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string for output
using DATA_TYPE = double; // Example type, adjust as necessary
const std::string DATA_PRINTF_MODIFIER = "%.2f "; // Example format string, adjust as necessary

void print_array(int m, DATA_TYPE** symmat) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << symmat[j][i] << DATA_PRINTF_MODIFIER;
            if ((i * m) + j + 1 % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Note: The memory for symmat should be managed outside this function,
// similar to how Fortran handles array arguments.
