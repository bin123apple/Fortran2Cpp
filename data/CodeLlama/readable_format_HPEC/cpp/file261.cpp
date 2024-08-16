#include <cmath>

void kernel_cholesky(int n, double* p, double** a) {
    double x;

    // Loop equivalent to the Fortran DO loop
    for (int i = 0; i < n; ++i) {
        x = a[i][i];
        for (int j = 0; j < i; ++j) {
            x -= a[j][i] * a[j][i];
        }
        p[i] = 1.0 / sqrt(x);
        for (int j = i + 1; j < n; ++j) {
            x = a[j][i];
            for (int k = 0; k < i; ++k) {
                x -= a[k][j] * a[k][i];
            }
            a[i][j] = x * p[i];
        }
    }
}

int main() {
    // Example usage
    const int n = 3;
    double p[n];
    double** a = new double*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double[n];
        // Initialize matrix a with some values
        for (int j = 0; j < n; ++j) {
            a[i][j] = 1.0; // Example initialization
        }
    }

    kernel_cholesky(n, p, a);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
