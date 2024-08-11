#include <iostream>
#include <complex>
#include <vector>

using Complex = std::complex<double>;

void ZGEMV(char TRANS, int M, int N, Complex ALPHA, const Complex* A, int LDA,
           const Complex* X, int INCX, Complex BETA, Complex* Y, int INCY) {
    if (TRANS == 'N' || TRANS == 'n') {
        for (int i = 0; i < M; ++i) {
            Complex temp(0.0, 0.0);
            for (int j = 0; j < N; ++j) {
                temp += A[i + j * LDA] * X[j * INCX]; // Adjusted indexing for column-major order
            }
            Y[i * INCY] = ALPHA * temp + BETA * Y[i * INCY];
        }
    } else {
        // Implement transpose case if needed
    }
}

int main() {
    int M = 2, N = 2, LDA = 2, INCX = 1, INCY = 1;
    Complex ALPHA(1.0, 0.0), BETA(0.0, 0.0);
    Complex A[] = {Complex(1.0, 0.0), Complex(3.0, 0.0), Complex(2.0, 0.0), Complex(4.0, 0.0)};
    Complex X[] = {Complex(1.0, 0.0), Complex(2.0, 0.0)};
    Complex Y[] = {Complex(0.0, 0.0), Complex(0.0, 0.0)};

    ZGEMV('N', M, N, ALPHA, A, LDA, X, INCX, BETA, Y, INCY);

    std::cout << "Y: ";
    for (int i = 0; i < M; ++i) {
        std::cout << "(" << Y[i].real() << "," << Y[i].imag() << ") ";
    }
    std::cout << std::endl;

    return 0;
}