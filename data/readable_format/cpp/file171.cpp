#include <iostream>
#include <complex>

// Function declaration
int IZMAX1(int N, std::complex<double>* CX, int INCX) {
    if (N < 1) return -1; // Return -1 to indicate an invalid index for C++ 0-indexed arrays
    if (N == 1) return 0; // Return the first index in C++ (0-indexed)

    int index = 0;
    double smax = std::abs(CX[0]);

    if (INCX == 1) {
        for (int i = 1; i < N; ++i) {
            if (std::abs(CX[i]) > smax) {
                index = i;
                smax = std::abs(CX[i]);
            }
        }
    } else {
        int ix = 0;
        for (int i = 1; i < N; ++i) {
            ix += INCX;
            if (std::abs(CX[ix]) > smax) {
                index = ix;
                smax = std::abs(CX[ix]);
            }
        }
    }

    return index;
}

int main() {
    // Test 1: Single-element array
    std::complex<double> cx1[] = {std::complex<double>(1.0, 2.0)};
    std::cout << "Test 1 (Single-element array): Expected 0, got " << IZMAX1(1, cx1, 1) << std::endl;

    // Test 2: Multi-element array, INCX = 1
    std::complex<double> cx2[] = {std::complex<double>(2.0, 2.0), std::complex<double>(3.0, 4.0), std::complex<double>(1.0, 1.0)};
    std::cout << "Test 2 (Multi-element, INCX=1): Expected 1, got " << IZMAX1(3, cx2, 1) << std::endl;

    // Test 3: Multi-element array, INCX > 1
    std::cout << "Test 3 (Multi-element, INCX>1): Expected 0, got " << IZMAX1(2, cx2, 2) << std::endl;

    // Additional tests can be added here as needed

    return 0;
}