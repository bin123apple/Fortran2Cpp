#include <cmath>
#include <algorithm>
#include <vector>

float snrm2(int n, const std::vector<float>& x, int incx) {
    const float ONE = 1.0f;
    const float ZERO = 0.0f;

    float absxi, norm, scale, ssq;

    if (n < 1 || incx < 1) {
        norm = ZERO;
    } else if (n == 1) {
        norm = std::abs(x[0]);
    } else {
        scale = ZERO;
        ssq = ONE;

        for (int ix = 0; ix < 1 + (n - 1) * incx; ix += incx) {
            if (x[ix] != ZERO) {
                absxi = std::abs(x[ix]);
                if (scale < absxi) {
                    ssq = ONE + ssq * std::pow(scale / absxi, 2);
                    scale = absxi;
                } else {
                    ssq = ssq + std::pow(absxi / scale, 2);
                }
            }
        }
        norm = scale * std::sqrt(ssq);
    }

    return norm;
}