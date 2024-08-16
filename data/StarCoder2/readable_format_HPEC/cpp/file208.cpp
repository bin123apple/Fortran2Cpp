#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int for this example
void print_array(int ni, int nj, int** c) {
    // Set output formatting
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << std::setw(8) << c[j][i] << " ";
            if ((i * ni + j + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 3; // Number of columns
    const int nj = 4; // Number of rows
    int** c = new int*[nj]; // Dynamically allocate 2D array

    // Initialize array elements
    for (int i = 0; i < nj; ++i) {
        c[i] = new int[ni];
        for (int j = 0; j < ni; ++j) {
            c[i][j] = i * ni + j + 1; // Example initialization
        }
    }

    // Call the function
    print_array(ni, nj, c);

    // Clean up
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
