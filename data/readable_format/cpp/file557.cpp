#include <iostream>
#include <complex>

// Declaration and definition of the cdotc function
std::complex<double> cdotc(int n, const std::complex<double>* cx, int incx, const std::complex<double>* cy, int incy) {
    std::complex<double> ctemp(0.0, 0.0);
    if (n <= 0) return ctemp;

    int ix, iy;
    if (incx != 1 || incy != 1) {
        ix = iy = 0;
        if (incx < 0) ix = (n - 1) * incx;
        if (incy < 0) iy = (n - 1) * incy;
        for (int i = 0; i < n; ++i) {
            ctemp += std::conj(cx[ix]) * cy[iy];
            ix += incx;
            iy += incy;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            ctemp += std::conj(cx[i]) * cy[i];
        }
    }

    return ctemp;
}

int main() {
    // Test 1
    int n = 2, incx = 1, incy = 1;
    std::complex<double> cx[] = {std::complex<double>(1, 2), std::complex<double>(3, 4)};
    std::complex<double> cy[] = {std::complex<double>(5, 6), std::complex<double>(7, 8)};
    auto result = cdotc(n, cx, incx, cy, incy);
    std::cout << "Test 1 Result: " << result << std::endl;

    // Test 2
    n = 2;
    incx = 2;
    incy = 2;
    std::complex<double> cx2[] = {std::complex<double>(1, 2), std::complex<double>(0, 0), std::complex<double>(3, 4), std::complex<double>(0, 0)};
    std::complex<double> cy2[] = {std::complex<double>(5, 6), std::complex<double>(0, 0), std::complex<double>(7, 8), std::complex<double>(0, 0)};
    result = cdotc(n, cx2, incx, cy2, incy);
    std::cout << "Test 2 Result: " << result << std::endl;

    return 0;
}