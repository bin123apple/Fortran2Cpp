#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double).
// Adjust the type according to your needs.
using DATA_TYPE = double;

void kernel_fdtd_2d(int tmax, int nx, int ny, std::vector<DATA_TYPE>& ex, std::vector<DATA_TYPE>& ey, std::vector<DATA_TYPE>& hz, const std::vector<DATA_TYPE>& fict) {
    // Resize the vectors to match the dimensions
    ex.resize(ny * nx);
    ey.resize(ny * nx);
    hz.resize(ny * nx);

    // Loop variables
    int i, j, t;

    // Scoped block
    {
        for (t = 0; t < tmax; ++t) {
            for (j = 0; j < ny; ++j) {
                ey[j * nx] = fict[t];
            }
        }

        for (i = 1; i < nx; ++i) {
            for (j = 0; j < ny; ++j) {
                ey[j * nx + i] = ey[j * nx + i] - (0.5 * (hz[j * nx + i] - hz[j * nx + i - 1]));
            }
        }

        for (i = 0; i < nx; ++i) {
            for (j = 1; j < ny; ++j) {
                ex[j * nx + i] = ex[j * nx + i] - (0.5 * (hz[j * nx + i] - hz[(j - 1) * nx + i]));
            }
        }

        for (i = 0; i < nx - 1; ++i) {
            for (j = 0; j < ny - 1; ++j) {
                hz[j * nx + i] = hz[j * nx + i] - (0.7 * (ex[(j + 1) * nx + i] - ex[j * nx + i] + ey[j * nx + i + 1] - ey[j * nx + i]));
            }
        }
    }
}
