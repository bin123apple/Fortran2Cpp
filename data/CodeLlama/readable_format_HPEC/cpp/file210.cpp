#include <iostream>
#include <iomanip> // For std::setprecision

void print_array(int n, double** a) {
    // Assuming the array is square and n is its dimension
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[j][i] << " ";
            if ((i * n) + j + 1 % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int n = 4; // Size of the square array
    double** a = new double*[n]; // Dynamically allocate 2D array
    
    // Initialize array with some values (example)
    for (int i = 0; i < n; ++i) {
        a[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = i * n + j; // Example initialization
        }
    }
    
    print_array(n, a);
    
    // Clean up dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}
