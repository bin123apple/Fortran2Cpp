#include <cmath>

int IDAMAX(int N, const double* DX, int INCX) {
    int IDAMAX = 0;
    if (N <= 0) return 0;
    IDAMAX = 1;
    if (N == 1) return 1;

    if (INCX == 1) {
        double DMAX = std::abs(DX[0]);
        for (int I = 1; I < N; ++I) {
            double XMAG = std::abs(DX[I]);
            if (XMAG > DMAX) {
                IDAMAX = I + 1;
                DMAX = XMAG;
            }
        }
        return IDAMAX;
    }

    int IX = 0;
    if (INCX < 0) IX = (-N + 1) * INCX;
    double DMAX = std::abs(DX[IX]);
    IX += INCX;
    for (int I = 1; I < N; ++I) {
        double XMAG = std::abs(DX[IX]);
        if (XMAG > DMAX) {
            IDAMAX = I + 1;
            DMAX = XMAG;
        }
        IX += INCX;
    }
    return IDAMAX;
}