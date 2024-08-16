#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int and DATA_PRINTF_MODIFIER is "%d"
void print_array(int n, int** b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(4) << b[j][i] << " "; // Adjust width as needed
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int n = 4;
    int** b = new int*[n];
    for (int i = 0; i < n; ++i) {
        b[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            b[i][j] = i * n + j; // Example initialization
        }
    }

    print_array(n, b);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
