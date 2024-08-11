#include <iostream>
#include <complex>

// Function declaration
void zdscale(int n, double da, std::complex<double>* zx, int incx);

// Test function declaration
bool testZDSCALE();

// Main function to run tests
int main() {
    if (testZDSCALE()) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
    return 0;
}

// Function implementation
void zdscale(int n, double da, std::complex<double>* zx, int incx) {
    if (n <= 0 || incx <= 0) return;

    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            zx[i] = std::complex<double>(da, 0.0) * zx[i];
        }
    } else {
        int nincx = n * incx;
        for (int i = 0; i < nincx; i += incx) {
            zx[i] = std::complex<double>(da, 0.0) * zx[i];
        }
    }
}

// Test function implementation
bool testZDSCALE() {
    const int n = 3;
    const double da = 2.0;
    std::complex<double> zx[n] = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0}
    };

    zdscale(n, da, zx, 1);

    // Expected results after scaling
    std::complex<double> expected[n] = {
        {2.0, 4.0},
        {6.0, 8.0},
        {10.0, 12.0}
    };

    for (int i = 0; i < n; ++i) {
        if (zx[i] != expected[i]) {
            std::cout << "Test failed at index " << i << ". Expected: "
                      << expected[i] << ", Got: " << zx[i] << std::endl;
            return false;
        }
    }

    return true;
}