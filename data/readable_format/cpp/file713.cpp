#include <iostream>
#include <complex>

void ZLARTV(int N, std::complex<double>* X, int INCX, std::complex<double>* Y, int INCY, double* C, std::complex<double>* S, int INCC) {
    int IX = 0;
    int IY = 0;
    int IC = 0;

    for (int I = 0; I < N; ++I) {
        std::complex<double> XI = X[IX];
        std::complex<double> YI = Y[IY];

        X[IX] = C[IC] * XI + S[IC] * YI;
        Y[IY] = C[IC] * YI - std::conj(S[IC]) * XI;

        IX += INCX;
        IY += INCY;
        IC += INCC;
    }
}

int main() {
    const int N = 5;
    double C[N] = {1, 2, 3, 4, 5};
    std::complex<double> S[N] = {{1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0}};
    std::complex<double> X[N] = {{4, 1}, {3, 2}, {2, 3}, {1, 4}, {0, 5}};
    std::complex<double> Y[N] = {{1, 5}, {2, 4}, {3, 3}, {4, 2}, {5, 1}};

    ZLARTV(N, X, 1, Y, 1, C, S, 1);

    std::cout << "X: ";
    for (const auto& x : X) {
        std::cout << x << " ";
    }
    std::cout << std::endl << "Y: ";
    for (const auto& y : Y) {
        std::cout << y << " ";
    }
    std::cout << std::endl;

    return 0;
}