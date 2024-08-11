#include <iostream>
#include <cassert>
#include <cmath>

// Definition of the saxpy function
void saxpy(int n, float sa, float* sx, int incx, float* sy, int incy) {
    if (n <= 0) return;
    if (sa == 0.0f) return;

    int ix, iy;
    if (incx != 1 || incy != 1) {
        ix = 0;
        iy = 0;
        if (incx < 0) ix = (-n + 1) * incx;
        if (incy < 0) iy = (-n + 1) * incy;
        for (int i = 0; i < n; i++) {
            sy[iy] = sy[iy] + sa * sx[ix];
            ix += incx;
            iy += incy;
        }
    } else {
        int m = n % 4;
        if (m != 0) {
            for (int i = 0; i < m; i++) {
                sy[i] = sy[i] + sa * sx[i];
            }
            if (n < 4) return;
        }
        for (int i = m; i < n; i += 4) {
            sy[i] = sy[i] + sa * sx[i];
            sy[i + 1] = sy[i + 1] + sa * sx[i + 1];
            sy[i + 2] = sy[i + 2] + sa * sx[i + 2];
            sy[i + 3] = sy[i + 3] + sa * sx[i + 3];
        }
    }
}

// Test function for saxpy
void testSaxpy() {
    const int n = 5;
    float sa = 2.0f;
    float sx[n] = {1, 2, 3, 4, 5};
    int incx = 1;
    float sy[n] = {5, 4, 3, 2, 1};
    int incy = 1;

    saxpy(n, sa, sx, incx, sy, incy);

    // Expected result after SAXPY operation: sy[i] = 5 + 2 * sx[i]
    float expected[n] = {7, 8, 9, 10, 11};

    for (int i = 0; i < n; i++) {
        assert(abs(sy[i] - expected[i]) < 1e-5);
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testSaxpy();
    return 0;
}