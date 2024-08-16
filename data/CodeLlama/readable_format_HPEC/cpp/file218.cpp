#include <vector>
#include <iostream>

void kernel_covariance(int m, int n, double float_n, std::vector<std::vector<double>>& dat, std::vector<std::vector<double>>& symmat, std::vector<double>& mean) {
    // Determine mean of column vectors of input data matrix
    for (int j = 0; j < m; ++j) {
        mean[j] = 0.0;
        for (int i = 0; i < n; ++i) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Center the column vectors.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dat[j][i] -= mean[j];
        }
    }

    // Calculate the m * m covariance matrix.
    for (int j1 = 0; j1 < m; ++j1) {
        for (int j2 = j1; j2 < m; ++j2) {
            symmat[j2][j1] = 0.0;
            for (int i = 0; i < n; ++i) {
                symmat[j2][j1] += (dat[j1][i] * dat[j2][i]);
            }
            symmat[j1][j2] = symmat[j2][j1];
        }
    }
}

int main() {
    // Example usage
    int m = 3; // Number of rows
    int n = 4; // Number of columns
    double float_n = 5.0; // Example value for float_n

    std::vector<std::vector<double>> dat(m, std::vector<double>(n, 1.0)); // Example data matrix
    std::vector<std::vector<double>> symmat(m, std::vector<double>(m, 0.0)); // Symmetrical matrix for output
    std::vector<double> mean(m, 0.0); // Vector for mean values

    kernel_covariance(m, n, float_n, dat, symmat, mean);

    // Print the result
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << symmat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
