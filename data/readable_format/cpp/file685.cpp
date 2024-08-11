#include <iostream>
#include <vector>
#include <complex>

// Declaration of the crot function
void crot(int n, std::vector<std::complex<float>>& cx, int incx, std::vector<std::complex<float>>& cy, int incy, float c, std::complex<float> s) {
    if (n <= 0) {
        return;
    }

    int ix, iy;
    if (incx == 1 && incy == 1) {
        for (int i = 0; i < n; ++i) {
            std::complex<float> stemp = c * cx[i] + s * cy[i];
            cy[i] = c * cy[i] - std::conj(s) * cx[i];
            cx[i] = stemp;
        }
    } else {
        ix = 0;
        iy = 0;
        if (incx < 0) {
            ix = (-n + 1) * incx;
        }
        if (incy < 0) {
            iy = (-n + 1) * incy;
        }
        for (int i = 0; i < n; ++i) {
            std::complex<float> stemp = c * cx[ix] + s * cy[iy];
            cy[iy] = c * cy[iy] - std::conj(s) * cx[ix];
            cx[ix] = stemp;
            ix += incx;
            iy += incy;
        }
    }
}

int main() {
    std::vector<std::complex<float>> cx = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    std::vector<std::complex<float>> cy = {{7.0, 8.0}, {9.0, 10.0}, {11.0, 12.0}};
    float c = 0.5;
    std::complex<float> s(0.0, 1.0);

    crot(3, cx, 1, cy, 1, c, s);

    std::cout << "CX:" << std::endl;
    for (const auto& val : cx) {
        std::cout << val.real() << ", " << val.imag() << std::endl;
    }

    std::cout << "CY:" << std::endl;
    for (const auto& val : cy) {
        std::cout << val.real() << ", " << val.imag() << std::endl;
    }

    return 0;
}