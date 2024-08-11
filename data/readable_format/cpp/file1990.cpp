#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

void ZROT(const int N, std::complex<double>* CX, const int INCX, std::complex<double>* CY, const int INCY, const double C, const std::complex<double> S) {
    if (N <= 0) return;

    int IX, IY;
    std::complex<double> STEMP;

    if (INCX == 1 && INCY == 1) {
        for (int I = 0; I < N; ++I) {
            STEMP = C * CX[I] + S * CY[I];
            CY[I] = C * CY[I] - std::conj(S) * CX[I];
            CX[I] = STEMP;
        }
    } else {
        IX = 0;
        IY = 0;
        if (INCX < 0) IX = (-N + 1) * INCX;
        if (INCY < 0) IY = (-N + 1) * INCY;
        for (int I = 0; I < N; ++I) {
            STEMP = C * CX[IX] + S * CY[IY];
            CY[IY] = C * CY[IY] - std::conj(S) * CX[IX];
            CX[IX] = STEMP;
            IX += INCX;
            IY += INCY;
        }
    }
}

int main() {
    int N = 2;
    std::complex<double> CX[] = {std::complex<double>(1.0, 2.0), std::complex<double>(3.0, 4.0)};
    std::complex<double> CY[] = {std::complex<double>(5.0, 6.0), std::complex<double>(7.0, 8.0)};
    double C = 0.5;
    std::complex<double> S(0.5, 0.5);
    int INCX = 1, INCY = 1;

    ZROT(N, CX, INCX, CY, INCY, C, S);

    std::cout << "Test 1 Results:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "CX[" << i << "] = " << CX[i] << std::endl;
        std::cout << "CY[" << i << "] = " << CY[i] << std::endl;
    }

    return 0;
}