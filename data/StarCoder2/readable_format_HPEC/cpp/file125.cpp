#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int n = 100;
    int m = 100;

    std::vector<std::vector<float>> b(n, std::vector<float>(m));

    // Initialize the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = (i + 1) * (j + 1);
        }
    }

    // Compute the rest of the matrix
    for (int i = 1; i < n; ++i) {
        #pragma omp parallel for
        for (int j = 1; j < m; ++j) {
            b[i][j] = b[i - 1][j - 1];
        }
    }

    // Optional: Print the matrix to verify the results
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         std::cout << b[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
