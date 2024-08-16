#include <vector>
#include <cmath>
#include <algorithm>

const double EPS = 0.1;

void kernel_correlation(int m, int n, double float_n, std::vector<std::vector<double>>& dat, std::vector<std::vector<double>>& symmat, std::vector<double>& stddev, std::vector<double>& mean) {
    // Initialize mean and standard deviation vectors
    for (int j = 0; j < m; ++j) {
        mean[j] = 0.0;
        stddev[j] = 0.0;
    }

    // Calculate mean of column vectors
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Calculate standard deviations of column vectors
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            stddev[j] += (dat[j][i] - mean[j]) * (dat[j][i] - mean[j]);
        }
        stddev[j] /= float_n;
        stddev[j] = std::sqrt(stddev[j]);
        if (stddev[j] <= EPS) {
            stddev[j] = 1.0;
        }
    }

    // Center and reduce the column vectors
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dat[j][i] -= mean[j];
            dat[j][i] /= (std::sqrt(float_n) * stddev[j]);
        }
    }

    // Calculate the m * m correlation matrix
    for (int j1 = 0; j1 < m - 1; ++j1) {
        symmat[j1][j1] = 1.0;
        for (int j2 = j1 + 1; j2 < m; ++j2) {
            symmat[j2][j1] = 0.0;
            for (int i = 0; i < n; ++i) {
                symmat[j2][j1] += (dat[j1][i] * dat[j2][i]);
            }
            symmat[j1][j2] = symmat[j2][j1];
        }
    }
    symmat[m - 1][m - 1] = 1.0;
}

int main() {
    // Example usage
    int m = 3; // Number of rows
    int n = 4; // Number of columns
    double float_n = static_cast<double>(n);
    std::vector<std::vector<double>> dat = {{1.0, 2.0, 3.0, 4.0}, {5.0, 6.0, 7.0, 8.0}, {9.0, 10.0, 11.0, 12.0}};
    std::vector<std::vector<double>> symmat(m, std::vector<double>(m));
    std::vector<double> stddev(m);
    std::vector<double> mean(m);

    kernel_correlation(m, n, float_n, dat, symmat, stddev, mean);

    // Print the results
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << symmat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
