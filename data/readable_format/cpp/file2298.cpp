#include <complex>
#include <cmath>
#include <vector>

double dzsum1(int n, const std::vector<std::complex<double>>& cx, int incx) {
    if (n <= 0) {
        return 0.0;
    }

    double stemp = 0.0;

    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            stemp += std::abs(cx[i]);
        }
    } else {
        for (int i = 0; i < n * incx; i += incx) {
            stemp += std::abs(cx[i]);
        }
    }

    return stemp;
}