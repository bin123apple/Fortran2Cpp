#include <iostream>
#include <iomanip>

// Function to print the array
void print_array(int ni, int nl, double** g) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            std::cout << std::setw(12) << g[j][i] << " ";
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
    int ni = 5; // Number of rows
    int nl = 5; // Number of columns

    // Allocate memory for the array
    double** g = new double*[nl];
    for (int i = 0; i < nl; ++i) {
        g[i] = new double[ni];
    }

    // Initialize the array with some values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            g[j][i] = i * nl + j; // Example values
        }
    }

    // Print the array
    print_array(ni, nl, g);

    // Deallocate memory
    for (int i = 0; i < nl; ++i) {
        delete[] g[i];
    }
    delete[] g;

    return 0;
}
