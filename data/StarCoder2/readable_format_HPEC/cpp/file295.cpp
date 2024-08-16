#include <vector>

// Assuming DATA_TYPE is a typedef for double or float
using DATA_TYPE = double;

void kernel_bicg(int nx, int ny, const std::vector<std::vector<DATA_TYPE>>& a, 
                std::vector<DATA_TYPE>& s, std::vector<DATA_TYPE>& q, 
                const std::vector<DATA_TYPE>& p, const std::vector<DATA_TYPE>& r) {
    // Initialize s to zero
    for (int i = 0; i < ny; ++i) {
        s[i] = 0.0;
    }

    // Compute s and q
    for (int i = 0; i < nx; ++i) {
        q[i] = 0.0;
        for (int j = 0; j < ny; ++j) {
            s[j] += r[i] * a[j][i];
            q[i] += a[j][i] * p[j];
        }
    }
}
