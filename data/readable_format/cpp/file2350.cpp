#include <iostream>
#include <complex>
#include <cmath>

double dznrm2(int n, std::complex<double>* x, int incx) {
    const double ONE = 1.0;
    const double ZERO = 0.0;
    double norm = ZERO;
    double scale = ZERO;
    double ssq = ONE;

    if (n < 1 || incx < 1) {
        norm = ZERO;
    } else {
        for (int ix = 0; ix < n * incx; ix += incx) {
            if (std::abs(x[ix].real()) != ZERO) {
                double temp = std::abs(x[ix].real());
                if (scale < temp) {
                    ssq = ONE + ssq * (scale / temp) * (scale / temp);
                    scale = temp;
                } else {
                    ssq += (temp / scale) * (temp / scale);
                }
            }
            if (std::abs(x[ix].imag()) != ZERO) {
                double temp = std::abs(x[ix].imag());
                if (scale < temp) {
                    ssq = ONE + ssq * (scale / temp) * (scale / temp);
                    scale = temp;
                } else {
                    ssq += (temp / scale) * (temp / scale);
                }
            }
        }
        norm = scale * std::sqrt(ssq);
    }

    return norm;
}

int main() {
    // Example usage
    std::complex<double> x[] = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
    int n = 3;
    int incx = 1;

    double result = dznrm2(n, x, incx);
    std::cout << "Result: " << result << std::endl;

    return 0;
}