#include <iostream>
#include <complex>

std::complex<double> zdotuf(int n, const std::complex<double>* zx, int incx, const std::complex<double>* zy, int incy) {
    std::complex<double> ztemp(0.0, 0.0);
    if (n <= 0) return ztemp;
    
    int ix = 0;
    int iy = 0;
    if (incx < 0) ix = (-(n-1)) * incx;
    if (incy < 0) iy = (-(n-1)) * incy;
    for (int i = 0; i < n; ++i) {
        ztemp += zx[ix] * zy[iy];
        ix += incx;
        iy += incy;
    }
    return ztemp;
}

int main() {
    std::complex<double> zx[] = {std::complex<double>(1.0, 2.0), std::complex<double>(3.0, 4.0)};
    std::complex<double> zy[] = {std::complex<double>(5.0, 6.0), std::complex<double>(7.0, 8.0)};
    int n = 2;

    std::complex<double> result = zdotuf(n, zx, 1, zy, 1);
    std::cout << "Test Result: " << result << std::endl;
    // Expected: (-18.0, 44.0)

    return 0;
}