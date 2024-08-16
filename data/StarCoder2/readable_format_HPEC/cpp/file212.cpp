#include <cmath>

// Assuming DATA_TYPE is double for this example
void kernel_gramschmidt(int ni, int nj, double** a, double** r, double** q) {
    double nrm;

    // OpenMP pragma for scoping
    #pragma omp parallel for collapse(2)
    for (int k = 0; k < nj; ++k) {
        nrm = 0.0;
        for (int i = 0; i < ni; ++i) {
            nrm += a[k][i] * a[k][i];
        }
        r[k][k] = std::sqrt(nrm);
        for (int i = 0; i < ni; ++i) {
            q[k][i] = a[k][i] / r[k][k];
        }
        for (int j = k + 1; j < nj; ++j) {
            r[j][k] = 0.0;
            for (int i = 0; i < ni; ++i) {
                r[j][k] += q[k][i] * a[j][i];
            }
            for (int i = 0; i < ni; ++i) {
                a[j][i] -= q[k][i] * r[j][k];
            }
        }
    }
}
