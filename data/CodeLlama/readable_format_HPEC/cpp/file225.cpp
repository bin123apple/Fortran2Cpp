#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for the data type, e.g., float or double.
// Adjust the type accordingly.
using DATA_TYPE = double;

void kernel_syr2k(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b) {
    // Resize the matrix c to match the dimensions ni x ni
    c.resize(ni, std::vector<DATA_TYPE>(ni));

    // Apply beta scaling to matrix c
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] *= beta;
        }
    }

    // Perform the actual SYR2K operation
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < ni; ++k) {
                c[j][i] += (alpha * a[k][i] * b[k][j]);
                c[j][i] += (alpha * b[k][i] * a[k][j]);
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 4; // Example size
    int nj = 4; // Example size
    DATA_TYPE alpha = 1.0; // Example value
    DATA_TYPE beta = 0.5; // Example value

    // Initialize matrices a and b with some values
    std::vector<std::vector<DATA_TYPE>> a(ni, std::vector<DATA_TYPE>(nj, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> b(ni, std::vector<DATA_TYPE>(nj, 1.0)); // Example initialization

    // Matrix c will be resized inside the function
    std::vector<std::vector<DATA_TYPE>> c;

    // Call the kernel function
    kernel_syr2k(ni, nj, alpha, beta, c, a, b);

    // Optionally, print the result for verification
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
