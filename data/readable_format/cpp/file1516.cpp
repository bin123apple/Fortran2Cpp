#include <iostream>
#include <complex>
#include <vector>

// Function prototype is no longer needed since the definition is included before main()

// Here's your cswap function implementation directly in this file
void cswap(int n, std::complex<float>* cx, int incx, std::complex<float>* cy, int incy) {
    if (n <= 0) return;

    if (incx == 1 && incy == 1) {
        for (int i = 0; i < n; ++i) {
            std::swap(cx[i], cy[i]);
        }
    } else {
        int ix = 0;
        int iy = 0;
        if (incx < 0) ix = (n - 1) * incx;
        if (incy < 0) iy = (n - 1) * incy;
        for (int i = 0; i < n; ++i) {
            std::swap(cx[ix], cy[iy]);
            ix += incx;
            iy += incy;
        }
    }
}

int main() {
    std::vector<std::complex<float>> cx = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::vector<std::complex<float>> cy = {{-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}};

    cswap(5, cx.data(), 1, cy.data(), 1);

    std::cout << "After swapping:" << std::endl;
    std::cout << "cx:" << std::endl;
    for (const auto& c : cx) {
        std::cout << c << std::endl;
    }
    std::cout << "cy:" << std::endl;
    for (const auto& c : cy) {
        std::cout << c << std::endl;
    }

    return 0;
}