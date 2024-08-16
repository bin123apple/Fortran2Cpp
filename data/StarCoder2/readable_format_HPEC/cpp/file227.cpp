#include <iostream>

// Assuming DATA_TYPE is a placeholder for float or double
using DATA_TYPE = double;

void kernel_gemm(int ni, int nj, int nk, DATA_TYPE alpha, DATA_TYPE beta, DATA_TYPE** c, DATA_TYPE** a, DATA_TYPE** b) {
    // Assuming _PB_NI, _PB_NJ, and _PB_NK are preprocessor definitions for ni, nj, and nk respectively
    // These should be defined in the C++ code as well, for example, using #define

    // Loop over i, j, k as in the Fortran code
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] *= beta;
            for (int k = 0; k < nk; ++k) {
                c[j][i] += alpha * a[k][i] * b[j][k];
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 100, nj = 100, nk = 100;
    DATA_TYPE alpha = 1.0, beta = 0.5;

    // Allocate memory for a, b, and c
    DATA_TYPE** a = new DATA_TYPE*[nk];
    DATA_TYPE** b = new DATA_TYPE*[nk];
    DATA_TYPE** c = new DATA_TYPE*[nj];

    for (int i = 0; i < nk; ++i) {
        a[i] = new DATA_TYPE[ni];
        b[i] = new DATA_TYPE[nk];
    }
    for (int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }

    // Initialize arrays a and b with some values
    // For simplicity, let's just fill them with 1.0
    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < ni; ++j) {
            a[i][j] = 1.0;
        }
        for (int j = 0; j < nk; ++j) {
            b[i][j] = 1.0;
        }
    }

    // Call the kernel function
    kernel_gemm(ni, nj, nk, alpha, beta, c, a, b);

    // Clean up
    for (int i = 0; i < nk; ++i) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
