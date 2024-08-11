#include <cmath>
#include <cstddef>

double dasumf(size_t n, const double* dx, int incx) {
    double dtemp = 0.0;

    // Early exit if n <= 0 or incx <= 0
    if (n <= 0 || incx <= 0) {
        return 0.0;
    }

    // incx == 1 case
    if (incx == 1) {
        size_t m = n % 6;

        // Process the first m elements
        for (size_t i = 0; i < m; ++i) {
            dtemp += std::abs(dx[i]);
        }

        // Process the remaining elements in chunks of 6
        if (n >= 6) {
            for (size_t i = m; i < n; i += 6) {
                dtemp += std::abs(dx[i]) + std::abs(dx[i + 1]) + std::abs(dx[i + 2])
                         + std::abs(dx[i + 3]) + std::abs(dx[i + 4]) + std::abs(dx[i + 5]);
            }
        }
        return dtemp;
    }

    // incx != 1 case
    size_t nincx = n * incx;
    for (size_t i = 0; i < nincx; i += incx) {
        dtemp += std::abs(dx[i]);
    }

    return dtemp;
}