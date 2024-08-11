#include <iostream>
#include <vector>
#include <cmath>

void schmib(std::vector<std::vector<double>>& u, int n, int ndim) {
    const double zero = 0.0, small = 0.01, one = 1.0;
    int n1, ii, k, k1, npass, j;
    double dot, scale;

    n1 = n + 1;
    ii = 0;
    for (k = 1; k <= n; ++k) {
        k1 = k - 1;
        dot = zero;
        for (int i = 0; i < n; ++i) {
            dot += u[i][n1 - k - 1] * u[i][n1 - k - 1];
        }
        if (std::abs(dot) < 1e-20) {
            ii += 1;
            if (ii <= ndim) u[ii - 1][n1 - k - 1] = one;
            continue;
        }
        scale = one / std::sqrt(dot);
        for (int i = 0; i < n; ++i) {
            u[i][n1 - k - 1] *= scale;
        }
        if (k1 == 0) continue;
        for (npass = 0; npass < 3; ++npass) {
            for (j = 1; j <= k1; ++j) {
                dot = zero;
                for (int i = 0; i < n; ++i) {
                    dot += u[i][n1 - j - 1] * u[i][n1 - k - 1];
                }
                for (int i = 0; i < n; ++i) {
                    u[i][n1 - k - 1] -= dot * u[i][n1 - j - 1];
                }
            }
            dot = zero;
            for (int i = 0; i < n; ++i) {
                dot += u[i][n1 - k - 1] * u[i][n1 - k - 1];
            }
            if (std::abs(dot) < 1e-20) break;
            if (dot < small && npass > 2) break;
            scale = one / std::sqrt(dot);
            for (int i = 0; i < n; ++i) {
                u[i][n1 - k - 1] *= scale;
            }
        }
        ii += 1;
        if (ii <= ndim) u[ii - 1][n1 - k - 1] = one;
    }
}

int main() {
    int n = 3, ndim = 3;
    std::vector<std::vector<double>> u = {
        {1.0, 2.0, 3.0},
        {2.0, 5.0, 6.0},
        {3.0, 6.0, 14.0}
    };

    // Call the function.
    schmib(u, n, ndim);

    // Print the resulting matrix.
    std::cout << "Resulting matrix U:" << std::endl;
    for (int i = 0; i < ndim; ++i) {
        for (int j = 0; j < ndim; ++j) {
            std::cout << u[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}