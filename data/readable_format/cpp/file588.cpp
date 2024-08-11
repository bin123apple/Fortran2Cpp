#include <iostream>
#include <cmath>
#include <vector>

// Declaration and definition of the daxpy function
void daxpy(int N, double DA, const double* DX, int INCX, double* DY, int INCY) {
    for (int i = 0; i < N; ++i) {
        DY[i * INCY] = DA * DX[i * INCX] + DY[i * INCY];
    }
}

// Test function for daxpy
bool test_daxpy() {
    const int N = 5;
    double DA = 2.0;
    double DX[N] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double DY[N] = {1.0, 1.0, 1.0, 1.0, 1.0};
    const int INCX = 1, INCY = 1;

    // Call the daxpy function
    daxpy(N, DA, DX, INCX, DY, INCY);

    // Check the results
    for (int i = 0; i < N; ++i) {
        if (std::abs(DY[i] - (DA * DX[i] + 1.0)) > 1e-9) {
            return false; // Test failed due to mismatch
        }
    }
    return true; // Test passed
}

int main() {
    if (test_daxpy()) {
        std::cout << "TEST PASSED" << std::endl;
    } else {
        std::cout << "TEST FAILED" << std::endl;
    }
    return 0;
}