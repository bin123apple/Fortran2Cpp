#include <vector>
#include <iostream>

// Assuming DATA_TYPE is a predefined type, e.g., float or double
using DATA_TYPE = float;

void kernel_floyd_warshall(int n, std::vector<std::vector<DATA_TYPE>>& path) {
    // OpenACC directives for parallelism
    #pragma acc scop
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (path[j][i] >= path[k][i] + path[j][k]) {
                    path[j][i] = path[k][i] + path[j][k];
                }
            }
        }
    }
    #pragma acc endscop
}

int main() {
    // Example usage
    int n = 5; // Size of the matrix
    std::vector<std::vector<DATA_TYPE>> path(n, std::vector<DATA_TYPE>(n));

    // Initialize path matrix with some values
    // For simplicity, let's fill it with 1.0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            path[i][j] = 1.0;
        }
    }

    // Call the function
    kernel_floyd_warshall(n, path);

    // Print the result
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << path[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
