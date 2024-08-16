#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a type alias for a floating-point type, e.g., double.
// Adjust the type if necessary.
using DATA_TYPE = double;

void print_array(int ni, int nj, DATA_TYPE** c) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << c[j][i] << " ";
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
    int ni = 5, nj = 10;
    DATA_TYPE** c = new DATA_TYPE*[nj];
    for (int j = 0; j < nj; ++j) {
        c[j] = new DATA_TYPE[ni];
        for (int i = 0; i < ni; ++i) {
            c[j][i] = static_cast<DATA_TYPE>(i * nj + j); // Example initialization
        }
    }

    print_array(ni, nj, c);

    // Clean up
    for (int j = 0; j < nj; ++j) {
        delete[] c[j];
    }
    delete[] c;

    return 0;
}
