#include <vector>

int ILADLC(int M, int N, const std::vector<std::vector<double>> &A) {
    const double ZERO = 0.0;

    if (N == 0 || A[0][N - 1] != ZERO || A[M - 1][N - 1] != ZERO) {
        return N;
    } else {
        for (int ILADLC = N; ILADLC >= 1; --ILADLC) {
            for (int I = 0; I < M; ++I) {
                if (A[I][ILADLC - 1] != ZERO) {
                    return ILADLC;
                }
            }
        }
    }

    return 0;
}