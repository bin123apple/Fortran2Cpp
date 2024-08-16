#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double).
// Replace DATA_TYPE with the appropriate type, e.g., float, double.
using DATA_TYPE = double;

void kernel_2mm(DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& tmp,
                const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b,
                const std::vector<std::vector<DATA_TYPE>>& c, std::vector<std::vector<DATA_TYPE>>& d,
                int ni, int nj, int nk, int nl) {
    // Resize the tmp matrix to match the dimensions nj x ni
    tmp.resize(nj, std::vector<DATA_TYPE>(ni, 0.0));

    // Loop over i, j, k as in the Fortran code
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            tmp[j][i] = 0.0;
            for (int k = 0; k < nk; ++k) {
                tmp[j][i] += alpha * a[k][i] * b[j][k];
            }
        }
    }

    // Loop over i, j, k as in the Fortran code
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] *= beta;
            for (int k = 0; k < nj; ++k) {
                d[j][i] += tmp[k][i] * c[j][k];
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 10, nj = 10, nk = 10, nl = 10;
    DATA_TYPE alpha = 1.0, beta = 1.0;
    std::vector<std::vector<DATA_TYPE>> tmp, a(nk, std::vector<DATA_TYPE>(ni, 1.0)),
                                          b(nj, std::vector<DATA_TYPE>(nk, 1.0)),
                                          c(nl, std::vector<DATA_TYPE>(nj, 1.0)),
                                          d(nl, std::vector<DATA_TYPE>(ni, 1.0));

    kernel_2mm(alpha, beta, tmp, a, b, c, d, ni, nj, nk, nl);

    return 0;
}
