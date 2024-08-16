#include <iostream>
#include <cmath>

void init_array(int n, double alpha, double beta, double** a, double* u1, double* u2, double* v1, double* v2, double* w, double* x, double* y, double* z) {
    // Declare variables
    for (int i = 0; i < n; i++) {
        u1[i] = static_cast<double>(i - 1);
        u2[i] = static_cast<double>(i / static_cast<double>(n)) / 2.0;
        v1[i] = static_cast<double>(i / static_cast<double>(n)) / 4.0;
        v2[i] = static_cast<double>(i / static_cast<double>(n)) / 6.0;
        y[i] = static_cast<double>(i / static_cast<double>(n)) / 8.0;
        z[i] = static_cast<double>(i / static_cast<double>(n)) / 9.0;
        x[i] = 0.0;
        w[i] = 0.0;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            a[j][i] = (static_cast<double>(i - 1) * static_cast<double>(j - 1)) / static_cast<double>(n);
        }
    }

    alpha = 43532.0;
    beta = 12313.0;
}
