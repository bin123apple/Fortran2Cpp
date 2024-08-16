#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string for std::cout
using DATA_TYPE = double; // Example type, adjust according to your needs
const std::string DATA_PRINTF_MODIFIER = "%.2f "; // Example format string, adjust according to your needs

void print_array(int ni, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << std::setprecision(2) << c[j][i] << " "; // Adjusted for 0-based indexing
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 4; // Example size, adjust according to your needs
    DATA_TYPE** c = new DATA_TYPE*[ni]; // Dynamically allocate 2D array
    for (int i = 0; i < ni; ++i) {
        c[i] = new DATA_TYPE[ni]; // Allocate each row
        for (int j = 0; j < ni; ++j) {
            c[i][j] = i * ni + j; // Example initialization, adjust according to your needs
        }
    }

    print_array(ni, c);

    // Clean up dynamically allocated memory
    for (int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
