#include <complex>
#include <algorithm>

// Assuming the complex matrix is stored in a 1D array in row-major order
int ILAZLR(int M, int N, std::complex<double>* A, int LDA) {
    std::complex<double> ZERO(0.0, 0.0);
    int i, j;

    if (M == 0 || A[(M-1)*LDA] != ZERO || A[(M-1)*LDA + (N-1)] != ZERO) {
        return M;
    } else {
        int ilazlr = 0;
        for (j = 0; j < N; ++j) {
            for (i = M-1; i >= 0; --i) {
                if (A[i*LDA + j] != ZERO) break;
            }
            ilazlr = std::max(ilazlr, i+1); // +1 to adjust for 0-based indexing
        }
        return ilazlr;
    }
}