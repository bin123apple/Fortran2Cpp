#include <iostream>
#include <complex>
using namespace std;

// ZROT function definition
void ZROT(int N, complex<double> CX[], int INCX, complex<double> CY[], int INCY, double C, complex<double> S) {
    int IX, IY;
    complex<double> STEMP;
    
    if (N <= 0) return;

    if (INCX == 1 && INCY == 1) goto label20;

    IX = 0;
    IY = 0;
    if (INCX < 0) IX = (-N + 1) * INCX;
    if (INCY < 0) IY = (-N + 1) * INCY;
    for (int I = 0; I < N; ++I) {
        STEMP = C * CX[IX] + S * CY[IY];
        CY[IY] = C * CY[IY] - conj(S) * CX[IX];
        CX[IX] = STEMP;
        IX += INCX;
        IY += INCY;
    }
    return;

label20:
    for (int I = 0; I < N; ++I) {
        STEMP = C * CX[I] + S * CY[I];
        CY[I] = C * CY[I] - conj(S) * CX[I];
        CX[I] = STEMP;
    }
}

// Main program for unit testing
int main() {
    const int N = 4;
    complex<double> CX[N] = {{1, -1}, {2, -2}, {3, -3}, {4, -4}};
    complex<double> CY[N] = {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}};
    int INCX = 1, INCY = 1;
    double C = 0.5;
    complex<double> S = complex<double>(0.5, 0.5);

    // Call ZROT function
    ZROT(N, CX, INCX, CY, INCY, C, S);

    // Print results
    cout << "CX:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << CX[i] << endl;
    }

    cout << "CY:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << CY[i] << endl;
    }

    return 0;
}