#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double, int).
// Replace DATA_TYPE with the appropriate type.
template<typename DATA_TYPE>
void print_array(int ni, int nj, DATA_TYPE** a, DATA_TYPE** r, DATA_TYPE** q) {
    // Assuming DATA_PRINTF_MODIFIER is a format string for output.
    // In C++, we typically use stream manipulators for formatting.
    // Replace DATA_PRINTF_MODIFIER with the appropriate manipulators.
    std::cout << std::fixed << std::setprecision(6); // Example precision setting

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << a[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << r[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << q[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

// Note: The memory management (allocation and deallocation) for the 2D arrays a, r, and q
// is not shown here. In a real application, you would need to manage the memory appropriately.
