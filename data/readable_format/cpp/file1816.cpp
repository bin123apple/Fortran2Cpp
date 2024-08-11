#include <iostream>
#include <vector>

void saxpy(int n, float sa, float* sx, int incx, float* sy, int incy) {
    if (n <= 0) return;
    if (sa == 0.0f) return;

    if (incx == 1 && incy == 1) {
        int m = n % 4;
        for (int i = 0; i < m; ++i) {
            sy[i] = sy[i] + sa * sx[i];
        }
        if (n < 4) return;
        for (int i = m; i < n; i += 4) {
            sy[i] = sy[i] + sa * sx[i];
            sy[i + 1] = sy[i + 1] + sa * sx[i + 1];
            sy[i + 2] = sy[i + 2] + sa * sx[i + 2];
            sy[i + 3] = sy[i + 3] + sa * sx[i + 3];
        }
    } else {
        int ix = 0;
        int iy = 0;
        if (incx < 0) ix = (1 - n) * incx;
        if (incy < 0) iy = (1 - n) * incy;
        for (int i = 0; i < n; ++i) {
            sy[iy] = sy[iy] + sa * sx[ix];
            ix += incx;
            iy += incy;
        }
    }
}

int main() {
    int n = 5;
    std::vector<float> sx = {1, 2, 3, 4, 5};
    std::vector<float> sy = {5, 4, 3, 2, 1};
    float sa = 2.0;
    int incx = 1, incy = 1;

    saxpy(n, sa, sx.data(), incx, sy.data(), incy);

    // Expected output: {7, 8, 9, 10, 11}
    std::cout << "Result sy: ";
    for (auto y : sy) std::cout << y << " ";
    std::cout << std::endl;

    // Add more tests here if necessary

    return 0;
}