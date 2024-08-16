#include <vector>

void kernel_2mm(DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& tmp, 
               const std::vector<std::vector<DATA_TYPE>>& a, 
               const std::vector<std::vector<DATA_TYPE>>& b, 
               const std::vector<std::vector<DATA_TYPE>>& c, 
               std::vector<std::vector<DATA_TYPE>>& d, 
               int ni, int nj, int nk, int nl) {
    // Assuming the dimensions of tmp, a, b, c, d are correctly set up outside this function

    // First part of the computation
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            tmp[j][i] = 0.0;
            for (int k = 0; k < nk; ++k) {
                tmp[j][i] += alpha * a[k][i] * b[j][k];
            }
        }
    }

    // Second part of the computation
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] *= beta;
            for (int k = 0; k < nj; ++k) {
                d[j][i] += tmp[k][i] * c[j][k];
            }
        }
    }
}
