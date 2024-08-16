#include <iostream>
#include <vector>

void kernel_syr2k(int ni, int nj, double alpha, double beta, std::vector<std::vector<double>>& c, const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            c[j][i] = c[j][i] * beta;
        }
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            for (int k = 0; k < ni; k++) {
                c[j][i] += alpha * a[k][i] * b[k][j];
                c[j][i] += alpha * b[k][i] * a[k][j];
            }
        }
    }
}
