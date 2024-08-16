#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int n = 100;
    int m = 100;

    // Dynamically allocate 2D array b with dimensions nxm
    std::vector<std::vector<float>> b(n, std::vector<float>(m));

    // Initialize the array (optional, for demonstration purposes)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = 0.0f; // Example initialization
        }
    }

    // Parallel region
    #pragma omp parallel for collapse(2)
    for (int j = 1; j < n; ++j) { // Note: j starts from 1 to match Fortran's 2:n
        for (int i = 0; i < m; ++i) {
            b[i][j] = b[i][j - 1];
        }
    }

    // Print the value of b(50,50)
    std::cout << "b(50,50) = " << b[49][49] << std::endl; // Note: C++ uses 0-based indexing

    return 0;
}
