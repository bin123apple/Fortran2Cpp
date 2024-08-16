#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string for output
using DATA_TYPE = double; // Example type, adjust according to your needs
const std::string DATA_PRINTF_MODIFIER = "%6.2f "; // Example format string, adjust according to your needs

void print_array(int ni, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << std::setw(6) << c[j][i] << " "; // Adjusted for 0-based indexing and row-major order
            if (((i * ni) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 5; // Example size, adjust according to your needs
    DATA_TYPE** c = new DATA_TYPE*[ni];
    for (int i = 0; i < ni; ++i) {
        c[i] = new DATA_TYPE[ni];
        for (int j = 0; j < ni; ++j) {
            c[i][j] = i + j; // Example initialization, adjust according to your needs
        }
    }

    print_array(ni, c);

    // Cleanup
    for (int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
