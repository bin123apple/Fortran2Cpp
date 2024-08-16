#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double and DATA_PRINTF_MODIFIER is "%.2f" for simplicity
void print_array(double** d, int ni, int nl) {
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            std::cout << d[j][i] << " ";

            // Check if we need to insert a newline character
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    // Example dimensions
    int ni = 4, nl = 3;

    // Dynamically allocate the 2D array
    double** d = new double*[nl];
    for (int i = 0; i < nl; ++i) {
        d[i] = new double[ni];
    }

    // Initialize the array with some values (example)
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] = i * ni + j + 1.0; // Just an example
        }
    }

    // Call the function
    print_array(d, ni, nl);

    // Clean up
    for (int i = 0; i < nl; ++i) {
        delete[] d[i];
    }
    delete[] d;

    return 0;
}
