#include <complex>

// Function to conjugate a complex array
void zlacgv(int n, std::complex<double>* x, int incx) {
    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            x[i] = std::conj(x[i]);
        }
    } else {
        int ioff = 0;
        if (incx < 0) {
            ioff = (1 - (n - 1) * incx) - 1; // Adjust for zero-based indexing
        }
        for (int i = 0; i < n; ++i) {
            x[ioff] = std::conj(x[ioff]);
            ioff += incx;
        }
    }
}