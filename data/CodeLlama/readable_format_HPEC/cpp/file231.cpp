#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double).
// Replace DATA_TYPE with the appropriate data type (e.g., float, double).
using DATA_TYPE = double;

void kernel_gemm(int ni, int nj, int nk, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b) {
    // Resize the 2D vector 'c' to match the dimensions nj x ni
    c.resize(nj);
    for (int j = 0; j < nj; ++j) {
        c[j].resize(ni);
    }

    // Apply beta to each element of c
    for (int j = 0; j < nj; ++j) {
        for (int i = 0; i < ni; ++i) {
            c[j][i] *= beta;
        }
    }

    // Perform the matrix multiplication and accumulation
    for (int k = 0; k < nk; ++k) {
        for (int j = 0; j < nj; ++j) {
            for (int i = 0; i < ni; ++i) {
                c[j][i] += (alpha * a[k][i] * b[j][k]);
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 4, nj = 4, nk = 4;
    DATA_TYPE alpha = 1.0, beta = 1.0;
    std::vector<std::vector<DATA_TYPE>> a(nk, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> b(nj, std::vector<DATA_TYPE>(nk, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> c(nj, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization

    kernel_gemm(ni, nj, nk, alpha, beta, c, a, b);

    // Print the result for demonstration
    for (int j = 0; j < nj; ++j) {
        for (int i = 0; i < ni; ++i) {
            std::cout << c[j][i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
