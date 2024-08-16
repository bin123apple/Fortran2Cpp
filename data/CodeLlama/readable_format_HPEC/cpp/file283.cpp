#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int n = 100;
    const int m = 100;
    std::vector<std::vector<float>> b(n, std::vector<float>(m));

    // Initialize the first row
    for (int i = 0; i < m; ++i) {
        b[0][i] = 0; // Assuming an initial value, as the original Fortran code does not specify
    }

    // Parallel loop to fill the array
    #pragma omp parallel for collapse(2)
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            b[j][i] = b[j-1][i];
        }
    }

    // Print the value of b(50,50)
    std::cout << "b(50,50)=" << b[49][49] << std::endl; // C++ uses 0-based indexing

    return 0;
}
