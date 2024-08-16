#include <cmath>
#include <vector>

void l2norm(int ldx, int ldy, int ldz, 
            int nx0, int ny0, int nz0, 
            int ist, int iend, 
            int jst, int jend, 
            std::vector<std::vector<std::vector<std::vector<double>>> &v, 
            std::vector<double> &sum) {
    // Initialize sum to 0
    for (int m = 0; m < 5; ++m) {
        sum[m] = 0.0;
    }

    // Compute the L2 norm
    for (int k = 1; k < nz0 - 1; ++k) { // Adjusted for 0-based indexing
        for (int j = jst; j <= jend; ++j) {
            for (int i = ist; i <= iend; ++i) {
                for (int m = 0; m < 5; ++m) {
                    sum[m] += v[m][i][j][k] * v[m][i][j][k];
                }
            }
        }
    }

    // Finalize the sum
    for (int m = 0; m < 5; ++m) {
        sum[m] = std::sqrt(sum[m] / (static_cast<double>(nx0 - 2) * (ny0 - 2) * (nz0 - 2)));
    }
}

int main() {
    // Example usage
    int ldx = 100, ldy = 100, ldz = 100;
    int nx0 = 100, ny0 = 100, nz0 = 100;
    int ist = 0, iend = 99, jst = 0, jend = 99;

    std::vector<std::vector<std::vector<std::vector<double>>> v(5, std::vector<std::vector<std::vector<double>>>(ldx, std::vector<std::vector<double>>(ldy, std::vector<double>(ldz, 0.0))));
    std::vector<double> sum(5, 0.0);

    // Populate v with some values
    // For example:
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < ldx; ++j) {
            for (int k = 0; k < ldy; ++k) {
                for (int l = 0; l < ldz; ++l) {
                    v[i][j][k][l] = 1.0; // Just an example value
                }
            }
        }
    }

    l2norm(ldx, ldy, ldz, nx0, ny0, nz0, ist, iend, jst, jend, v, sum);

    // Print the results
    for (int m = 0; m < 5; ++m) {
        std::cout << "Sum[" << m << "] = " << sum[m] << std::endl;
    }

    return 0;
}
