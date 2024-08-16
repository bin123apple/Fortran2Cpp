#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int and DATA_PRINTF_MODIFIER is "%d"
void print_array(int n, int** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(4) << a[j][i] << " "; // Adjusting width for better output formatting
            if ((i * n + j + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int n = 4; // Example size
    int** a = new int*[n]; // Dynamically allocate 2D array
    
    // Initialize array with some values
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = i * n + j + 1; // Example values
        }
    }
    
    print_array(n, a); // Print the array
    
    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}
