#include <complex>

void evolve(std::complex<double> u0[][2][2], std::complex<double> u1[][2][2], double twiddle[][2][2], int d1, int d2, int d3) {
    for (int k = 0; k < d3; ++k) {
        for (int j = 0; j < d2; ++j) {
            for (int i = 0; i < d1; ++i) {
                u0[i][j][k] = u0[i][j][k] * twiddle[i][j][k];
                u1[i][j][k] = u0[i][j][k];
            }
        }
    }
}
