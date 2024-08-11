#include <iostream>
#include <complex>

void zdotcsub(std::complex<double>& zdotcr, int n, const std::complex<double>* x, int incx, const std::complex<double>* y, int incy) {
    zdotcr = std::complex<double>(0.0, 0.0);
    for (int i = 0; i < n; ++i) {
        zdotcr += std::conj(x[i * incx]) * y[i * incy];
    }
}

int main() {
    const int n = 3;
    const int incx = 1, incy = 1;
    std::complex<double> x[3] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, -6.0}};
    std::complex<double> y[3] = {{2.0, -1.0}, {-4.0, 3.0}, {7.0, 8.0}};
    std::complex<double> zdotcr;

    zdotcsub(zdotcr, n, x, incx, y, incy);

    std::cout << "Computed zdotcr = " << zdotcr << std::endl;
}