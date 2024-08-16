#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., double, float).
// Adjust the type accordingly.
using DATA_TYPE = double;

void kernel_atax(int nx, int ny, const std::vector<std::vector<DATA_TYPE>>& a, 
                 const std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& y, std::vector<DATA_TYPE>& tmp) {
    // Initialize y and tmp vectors
    for (int i = 0; i < ny; ++i) {
        y[i] = 0.0;
    }
    for (int i = 0; i < nx; ++i) {
        tmp[i] = 0.0;
    }

    // Compute the operations as in the Fortran code
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            tmp[i] += a[j][i] * x[j];
        }
    }
    for (int j = 0; j < ny; ++j) {
        y[j] += a[j][i] * tmp[i];
    }
}

int main() {
    // Example usage
    int nx = 100, ny = 100; // Example dimensions
    std::vector<std::vector<DATA_TYPE>> a(ny, std::vector<DATA_TYPE>(nx)); // Initialize 2D vector a
    std::vector<DATA_TYPE> x(ny), y(ny), tmp(nx); // Initialize vectors x, y, tmp

    // Fill 'a', 'x' with some values for demonstration
    // ...

    kernel_atax(nx, ny, a, x, y, tmp);

    // Output results (for demonstration)
    // ...

    return 0;
}
