#include <iostream>
#include <cassert>
#include <algorithm> // For std::swap

// Declaration of the sswap function
void sswap(int n, float sx[], int incx, float sy[], int incy);

int main() {
    float sx[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float sy[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    
    // Call the sswap function
    sswap(5, sx, 1, sy, 1);
    
    // Expected arrays after swap
    float expected_sx[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    float expected_sy[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    
    // Verify the results
    for (int i = 0; i < 5; ++i) {
        assert(sx[i] == expected_sx[i] && "sx array did not match the expected result.");
        assert(sy[i] == expected_sy[i] && "sy array did not match the expected result.");
    }
    
    std::cout << "Test passed successfully." << std::endl;

    return 0;
}

// Definition of the sswap function
void sswap(int n, float sx[], int incx, float sy[], int incy) {
    if (n <= 0) return;

    if (incx == 1 && incy == 1) {
        // Special case for unit strides
        int m = n % 3;
        if (m != 0) {
            for (int i = 0; i < m; ++i) {
                std::swap(sx[i], sy[i]);
            }
        }
        if (n < 3) return;

        for (int i = m; i < n; i += 3) {
            std::swap(sx[i], sy[i]);
            std::swap(sx[i + 1], sy[i + 1]);
            std::swap(sx[i + 2], sy[i + 2]);
        }
    } else {
        // General case for arbitrary strides
        int ix = 0;
        int iy = 0;

        if (incx < 0) ix = (n - 1) * incx;
        if (incy < 0) iy = (n - 1) * incy;

        for (int i = 0; i < n; ++i) {
            std::swap(sx[ix], sy[iy]);
            ix += incx;
            iy += incy;
        }
    }
}