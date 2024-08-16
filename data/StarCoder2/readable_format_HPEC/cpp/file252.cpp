#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int and DATA_PRINTF_MODIFIER is "%d" for simplicity
void print_array(int ni, int nl, int** g) {
    // Set output formatting
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            std::cout << std::setw(5) << g[j][i] << " "; // Adjust width as needed
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
    int ni = 3, nl = 2;

    // Dynamically allocate 2D array
    int** g = new int*[nl];
    for (int i = 0; i < nl; ++i) {
        g[i] = new int[ni];
    }

    // Fill the array with some values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            g[j][i] = i * ni + j + 1; // Example values
        }
    }

    // Call the function
    print_array(ni, nl, g);

    // Clean up
    for (int i = 0; i < nl; ++i) {
        delete[] g[i];
    }
    delete[] g;

    return 0;
}
