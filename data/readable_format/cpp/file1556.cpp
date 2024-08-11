#include <iostream>
#include <vector>
#include <cmath>

void bratu2d(int m, int n, double alpha, const std::vector<std::vector<double>>& x, std::vector<std::vector<double>>& f) {
    double hx = 1.0 / (m - 1);
    double hy = 1.0 / (n - 1);
    f = x;

    for(int i = 1; i < m - 1; ++i) {
        for(int j = 1; j < n - 1; ++j) {
            double u = x[i][j];
            double uN = x[i-1][j];
            double uS = x[i+1][j];
            double uE = x[i][j+1];
            double uW = x[i][j-1];
            f[i][j] = (2 * u - uE - uW) * (hy / hx) + (2 * u - uN - uS) * (hx / hy) - alpha * exp(u) * (hx * hy);
        }
    }
}

int main() {
    int m = 5, n = 5;
    double alpha = 1.0;
    std::vector<std::vector<double>> x(m, std::vector<double>(n));
    std::vector<std::vector<double>> f(m, std::vector<double>(n));

    // Initialize x with some simple values for testing
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            x[i][j] = sin((i + 1) * (j + 1));
        }
    }

    // Call the function
    bratu2d(m, n, alpha, x, f);

    // Output the results for manual verification
    std::cout << "Results for f:" << std::endl;
    for(const auto& row : f) {
        for(double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}