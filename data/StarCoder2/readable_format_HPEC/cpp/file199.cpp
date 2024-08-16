#include <vector>

// Assuming DATA_TYPE is a type alias for some floating-point type, e.g., float or double.
using DATA_TYPE = double;

void kernel_syrk(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a) {
    // Assuming _PB_NI and _PB_NJ are preprocessor definitions for ni and nj, respectively.
    // These are used in the original Fortran code for parallelization purposes.
    // In C++, we'll directly use ni and nj for simplicity.

    // First, scale the matrix c by beta
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] *= beta;
        }
    }

    // Then, update the matrix c based on the formula
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < nj; ++k) {
                c[j][i] += alpha * a[k][i] * a[k][j];
            }
        }
    }
}
