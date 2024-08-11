#include <cmath>
#include <algorithm>

void vpot(double r, double& v, double& vp, double& vpp) {
    // Define constants
    const double expmax = 666.0;
    const double a = 544850.4;
    const double alp = 13.353384;
    const double d = 1.241314;
    const double c6 = 1.3732412;
    const double c8 = 0.4253785;
    const double c10 = 0.1781;
    const double sigma = 2.556;
    const double rm = 2.9673;
    const double eps = 10.8;

    double units = sigma / rm;
    double y = rm / (sigma * r);

    double v1 = a * eps * exp(-alp / y);
    double v1p = -alp * units * v1;
    double v1pp = -alp * units * v1p;
    double x2 = y * y;

    double f = eps;
    double fp = 0.0;
    double dy = d * y;

    double v2 = (c6 + (c8 + c10 * x2) * x2) * pow(x2, 3);
    double v2p = -(6.0 * c6 + (8.0 * c8 + 10.0 * c10 * x2) * x2) * pow(x2, 3) / r;
    double v2pp = (6.0 * 7.0 * c6 + (8.0 * 9.0 * c8 + 10.0 * 11.0 * c10 * x2) * x2) * pow(x2, 3) / (r * r);

    if (dy > 1.0) {
        f *= exp(-std::min(expmax, pow(dy - 1.0, 2)));
        fp = 2.0 * (dy - 1.0) * dy * f / r;
    }

    v = v1 - f * v2;
    vp = v1p - f * v2p - fp * v2;
    vpp = v1pp - f * v2pp - 2.0 * fp * v2p;
}