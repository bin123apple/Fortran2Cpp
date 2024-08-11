#include <iostream>

void DAXPY(int N, double DA, double* DX, int INCX, double* DY, int INCY) {
    if (N <= 0) return;
    if (DA == 0.0) return;

    int IX, IY;
    if (INCX == 1 && INCY == 1) {
        int M = N % 4;
        for (int i = 0; i < M; ++i) {
            DY[i] += DA * DX[i];
        }
        if (N < 4) return;
        for (int i = M; i < N; i += 4) {
            DY[i] += DA * DX[i];
            DY[i + 1] += DA * DX[i + 1];
            DY[i + 2] += DA * DX[i + 2];
            DY[i + 3] += DA * DX[i + 3];
        }
    } else {
        IX = 0;
        IY = 0;
        if (INCX < 0) IX = (N-1) * INCX;
        if (INCY < 0) IY = (N-1) * INCY;
        for (int I = 0; I < N; ++I) {
            DY[IY] += DA * DX[IX];
            IX += INCX;
            IY += INCY;
        }
    }
}

// The following is a simple test using main function
// For comprehensive testing, it's recommended to use a unit testing framework like Google Test.

int main() {
    const int N = 5;
    double DA = 2.0;
    double DX[N] = {1, 2, 3, 4, 5};
    double DY[N] = {5, 4, 3, 2, 1};
    int INCX = 1, INCY = 1;

    DAXPY(N, DA, DX, INCX, DY, INCY);

    std::cout << "Test Case 1: DY = ";
    for (int i = 0; i < N; ++i) {
        std::cout << DY[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}