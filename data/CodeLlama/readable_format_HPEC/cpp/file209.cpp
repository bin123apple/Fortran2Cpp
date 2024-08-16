#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string for output
using DATA_TYPE = double; // Example data type
const std::string DATA_PRINTF_MODIFIER = "%.2f "; // Example format string

void print_array(int ni, int nj, DATA_TYPE** c) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            // Output the data with the specified format
            std::cout << DATA_PRINTF_MODIFIER << c[j][i];

            // Check if we need to insert a newline after every 20 elements
            if ((i * ni + j) % 20 == 0 && i != 0 && j != 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl; // Newline after the array
}

// Note: The memory management (allocation/deallocation) for the 2D array 'c' is not shown here.
// In a real application, you would need to ensure that 'c' is properly allocated and deallocated.
