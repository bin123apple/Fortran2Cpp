#include <iostream>
#include <complex>

// Define the ccopy function right in this file
void ccopy(int n, const std::complex<float>* cx, int incx, std::complex<float>* cy, int incy) {
    if (n <= 0) return;

    if (incx == 1 && incy == 1) {
        for (int i = 0; i < n; ++i) {
            cy[i] = cx[i];
        }
    } else {
        int ix = 0;
        int iy = 0;
        if (incx < 0) ix = (n - 1) * incx;
        if (incy < 0) iy = (n - 1) * incy;
        for (int i = 0; i < n; ++i) {
            cy[iy] = cx[ix];
            ix += incx;
            iy += incy;
        }
    }
}

// The test function
void testCCopy() {
    int n = 5;
    int incx = 1, incy = 1;
    std::complex<float> cx[] = { {1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5} };
    std::complex<float> cy[5]; // Initialized to 0

    ccopy(n, cx, incx, cy, incy);

    std::cout << "Test 1: Basic functionality" << std::endl;
    for (int i = 0; i < n; ++i) {
        if (cy[i] != cx[i]) {
            std::cout << "Mismatch at " << i << ": cy = " << cy[i] << ", cx = " << cx[i] << std::endl;
        } else {
            std::cout << "cy[" << i << "] = cx[" << i << "] = " << cy[i] << std::endl;
        }
    }
    
    // Additional tests can follow here
}

// Main function to run the test
int main() {
    testCCopy();
    return 0;
}