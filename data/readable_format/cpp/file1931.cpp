#include <vector>
#include <complex>

void ZLASCL2(int M, int N, const std::vector<double>& D, std::vector<std::vector<std::complex<double>>>& X) {
    for (int J = 0; J < N; ++J) {
        for (int I = 0; I < M; ++I) {
            X[I][J] *= D[I];
        }
    }
}