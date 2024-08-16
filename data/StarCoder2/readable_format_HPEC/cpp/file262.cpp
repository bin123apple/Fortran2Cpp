#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int and DATA_PRINTF_MODIFIER is a format string for output
using DATA_TYPE = int;
const char* DATA_PRINTF_MODIFIER = "%d ";

void print_array(int ni, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << std::setw(3) << c[j][i] << " "; // Adjusting output formatting
            if ((i * ni + j + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int ni = 4; // Example size
    DATA_TYPE** c = new DATA_TYPE*[ni];
    for (int i = 0; i < ni; ++i) {
        c[i] = new DATA_TYPE[ni];
        for (int j = 0; j < ni; ++j) {
            c[i][j] = i * ni + j + 1; // Example initialization
        }
    }

    print_array(ni, c);

    // Clean up
    for (int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
