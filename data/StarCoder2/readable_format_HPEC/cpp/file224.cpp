#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a type like int or double, and DATA_PRINTF_MODIFIER is a format specifier for output
// For example, if DATA_TYPE is int and DATA_PRINTF_MODIFIER is "%d", the function signature would be:
void print_array(int n, int** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(DATA_PRINTF_MODIFIER) << a[j][i] << " ";
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Note: The actual usage of std::setw and the format specifier (DATA_PRINTF_MODIFIER)
// might need adjustments based on the specific requirements of your application.
