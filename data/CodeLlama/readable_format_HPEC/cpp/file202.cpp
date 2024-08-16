#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double).
// Replace DATA_TYPE with the appropriate type, e.g., float, double.
using DATA_TYPE = double;

void kernel_syrk(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a) {
    // Initialize c with beta
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] *= beta;
        }
    }

    // Perform the computation
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < nj; ++k) {
                c[j][i] += (alpha * a[k][i] * a[k][j]);
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 5; // Example value for ni
    int nj = 5; // Example value for nj
    DATA_TYPE alpha = 1.0; // Example value for alpha
    DATA_TYPE beta = 2.0; // Example value for beta

    // Initialize a and c with some values
    std::vector<std::vector<DATA_TYPE>> a(ni, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> c(ni, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization

    // Call the function
    kernel_syrk(ni, nj, alpha, beta, c, a);

    // Optionally, print the result to verify
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << "c(" << i << "," << j << ") = " << c[i][j] << std::endl;
        }
    }

    return 0;
}
