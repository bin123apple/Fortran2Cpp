#include <iostream>
#include <iomanip>

void dger(int m, int n, double alpha, const double* x, int incx, const double* y, int incy, double* a, int lda) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            a[i + j*lda] += alpha * x[i*incx] * y[j*incy];
        }
    }
}

int main() {
    const int M = 2, N = 3;
    double A[M*N] = {1, 2, 3, 4, 5, 6};
    double X[M] = {1, 2};
    double Y[N] = {1, 2, 3};
    double ALPHA = 2.0;

    dger(M, N, ALPHA, X, 1, Y, 1, A, M);

    std::cout << "Updated matrix A:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(6) << A[i + j*M] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}