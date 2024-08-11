#include <iostream>
#include <complex>

void ZLACGV(int N, std::complex<double>* X, int INCX);

int main() {
    const int N = 5;
    std::complex<double> X[N];

    // Test case 1: INCX = 1
    int INCX = 1;
    std::cout << "Test case 1: INCX = 1" << std::endl;
    for (int i = 0; i < N; ++i) {
        X[i] = std::complex<double>(i+1, i+1); // Initialize X
    }
    ZLACGV(N, X, INCX);
    for (int i = 0; i < N; ++i) {
        std::cout << "X[" << i << "] = " << X[i] << std::endl;
    }

    // Test case 2: INCX = 2
    INCX = 2;
    std::cout << "Test case 2: INCX = 2" << std::endl;
    for (int i = 0; i < N; ++i) {
        X[i] = std::complex<double>(i+1, i+1); // Re-initialize X
    }
    ZLACGV(N, X, INCX);
    for (int i = 0; i < N; ++i) {
        std::cout << "X[" << i << "] = " << X[i] << std::endl;
    }

    return 0;
}

void ZLACGV(int N, std::complex<double>* X, int INCX) {
    if (INCX == 1) {
        for (int i = 0; i < N; ++i) {
            X[i] = std::conj(X[i]);
        }
    } else {
        int IOFF = 0; // Adjusted for 0-based indexing
        if (INCX < 0) {
            IOFF = (N - 1) * INCX; // Adjust to starting position based on stride
        }
        for (int i = 0; i < N; ++i) {
            X[IOFF] = std::conj(X[IOFF]);
            IOFF += INCX;
        }
    }
}