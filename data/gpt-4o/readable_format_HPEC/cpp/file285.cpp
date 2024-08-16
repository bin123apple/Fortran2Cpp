#include <cmath>

int T_norm2 = 9;
bool timeron = false;

void timer_start(int t) {}

void timer_stop(int t) {}

void norm2u3(double ***r, int n1, int n2, int n3, double &rnm2, double &rnmu, int nx, int ny, int nz) {
    double dn, s, a;

    if (timeron) timer_start(T_norm2);
    dn = 1.0 * nx * ny * nz;

    s = 0.0;
    rnmu = 0.0;
    for (int i3 = 1; i3 < n3; i3++) {
        for (int i2 = 1; i2 < n2; i2++) {
            for (int i1 = 1; i1 < n1; i1++) {
                s = s + pow(r[i1][i2][i3], 2);
                a = abs(r[i1][i2][i3]);
                rnmu = std::max(rnmu, a);
            }
        }
    }

    rnm2 = sqrt(s / dn);
    if (timeron) timer_stop(T_norm2);
}
