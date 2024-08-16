#include <vector>

// Assuming DATA_TYPE is a double for this example
using DATA_TYPE = double;

void kernel_fdtd_2d(int tmax, int nx, int ny, std::vector<DATA_TYPE>& fict,
                    std::vector<std::vector<DATA_TYPE>>& ex,
                    std::vector<std::vector<DATA_TYPE>>& ey,
                    std::vector<std::vector<DATA_TYPE>>& hz) {
    // Assuming _PB_TMAX, _PB_NX, and _PB_NY are macros or constants defined elsewhere
    // These macros should be replaced with their actual values or passed as additional parameters

    // OpenACC directives in C++ start with #pragma
    #pragma scop
    for (int t = 0; t < tmax; ++t) {
        for (int j = 0; j < ny; ++j) {
            ey[j][0] = fict[t];
        }
        for (int i = 1; i < nx; ++i) {
            for (int j = 0; j < ny; ++j) {
                ey[j][i] = ey[j][i] - (0.5 * (hz[j][i] - hz[j][i - 1]));
            }
        }
        for (int i = 0; i < nx; ++i) {
            for (int j = 1; j < ny; ++j) {
                ex[j][i] = ex[j][i] - (0.5 * (hz[j][i] - hz[j - 1][i]));
            }
        }
        for (int i = 0; i < nx - 1; ++i) {
            for (int j = 0; j < ny - 1; ++j) {
                hz[j][i] = hz[j][i] - (0.7 * (ex[j + 1][i] - ex[j][i] + ey[j][i + 1] - ey[j][i]));
            }
        }
    }
    #pragma endscop
}
