#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string for output
using DATA_TYPE = double; // Example type, adjust according to your needs
const std::string DATA_PRINTF_MODIFIER = "%.2f "; // Example format string, adjust according to your needs

void print_array(int n, DATA_TYPE** a) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Print the element in the specified format
            std::cout << DATA_PRINTF_MODIFIER << a[j][i] << " ";

            // Check if we need to insert a newline (every 20 elements)
            if ((i * n) + j + 1 % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
}

// Note: The memory management (allocation and deallocation) for the 2D array 'a' is not shown here.
// In a real application, you would need to allocate and deallocate memory for 'a' using new and delete[] respectively.
