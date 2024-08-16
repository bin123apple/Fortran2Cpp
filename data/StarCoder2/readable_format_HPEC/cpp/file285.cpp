#include <cmath>
#include <algorithm>

extern bool timeron; // Assuming this is defined elsewhere

void norm2u3(double* r, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz) {
    double s = 0.0;
    double a = 0.0;
    double dn = 1.0 * nx * ny * nz;

    if (timeron) {
        // Assuming timer_start and timer_stop are defined elsewhere
        timer_start(9);
    }

    for (int i3 = 2; i3 < n3 - 1; ++i3) {
        for (int i2 = 2; i2 < n2 - 1; ++i2) {
            for (int i1 = 2; i1 < n1 - 1; ++i1) {
                s += r[i1 + (i2 * n1) + (i3 * n1 * n2)] * r[i1 + (i2 * n1) + (i3 * n1 * n2)];
                a = std::abs(r[i1 + (i2 * n1) + (i3 * n1 * n2)]);
                rnmu = std::max(rnmu, a);
            }
        }
    }

    rnm2 = std::sqrt(s / dn);

    if (timeron) {
        timer_stop(9);
    }
}
