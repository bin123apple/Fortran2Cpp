#include <vector>

// Assuming DATA_TYPE is double for this example
using DATA_TYPE = double;

void kernel_atax(int nx, int ny, const std::vector<std::vector<DATA_TYPE>>& a, 
                const std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& y, 
                std::vector<DATA_TYPE>& tmp) {
    // Initialize y to 0
    for (int i = 0; i < ny; ++i) {
        y[i] = 0.0;
    }

    // Compute tmp and update y
    for (int i = 0; i < nx; ++i) {
        tmp[i] = 0.0;
        for (int j = 0; j < ny; ++j) {
            tmp[i] += a[j][i] * x[j];
        }
        for (int j = 0; j < ny; ++j) {
            y[j] += a[j][i] * tmp[i];
        }
    }
}

int main() {
    // Example usage
    int nx = 4; // Number of columns
    int ny = 3; // Number of rows
    std::vector<std::vector<DATA_TYPE>> a = {{1.0, 2.0, 3.0, 4.0}, 
                                             {5.0, 6.0, 7.0, 8.0}, 
                                             {9.0, 10.0, 11.0, 12.0}};
    std::vector<DATA_TYPE> x = {1.0, 2.0, 3.0};
    std::vector<DATA_TYPE> y(ny, 0.0); // Initialize y with zeros
    std::vector<DATA_TYPE> tmp(nx, 0.0);

    kernel_atax(nx, ny, a, x, y, tmp);

    // Output results
    for (int i = 0; i < ny; ++i) {
        std::cout << "y[" << i << "] = " << y[i] << std::endl;
    }

    return 0;
}
