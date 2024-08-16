#include <cmath>

void l2norm(int ldx, int ldy, int ldz, 
            int nx0, int ny0, int nz0, 
            int ist, int iend, 
            int jst, int jend, 
            double v[5][(ldx/2*2+1)][(ldy/2*2+1)][ldz], 
            double sum[5]) {

    // Initialize sum to 0
    for (int m = 0; m < 5; ++m) {
        sum[m] = 0.0;
    }

    // Compute the sum of squares
    for (int k = 1; k < nz0 - 1; ++k) {
        for (int j = jst; j <= jend; ++j) {
            for (int i = ist; i <= iend; ++i) {
                for (int m = 0; m < 5; ++m) {
                    sum[m] += v[m][i][j][k] * v[m][i][j][k];
                }
            }
        }
    }

    // Compute the L2 norm
    for (int m = 0; m < 5; ++m) {
        sum[m] = std::sqrt(sum[m] / (static_cast<double>(nx0 - 2) * (ny0 - 2) * (nz0 - 2)));
    }
}
