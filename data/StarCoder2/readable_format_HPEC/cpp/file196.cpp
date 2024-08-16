#include <vector>

// Assuming DATA_TYPE is a type alias for double or float, for example:
using DATA_TYPE = double;

void kernel_trisolv(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& x, const std::vector<DATA_TYPE>& c) {
    // Assuming the vectors are already sized appropriately outside this function

    // OpenMP pragma for scoping
    #pragma omp scop
    for (int i = 0; i < n; ++i) {
        x[i] = c[i];
        for (int j = 0; j < i; ++j) {
            x[i] = x[i] - (a[j][i] * x[j]);
        }
        x[i] = x[i] / a[i][i];
    }
    #pragma omp endscop
}

int main() {
    // Example usage
    int n = 5; // Size of the system
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n)); // Matrix A
    std::vector<DATA_TYPE> x(n); // Solution vector
    std::vector<DATA_TYPE> c(n); // Right-hand side vector

    // Initialize a, c, and x with appropriate values
    //...

    kernel_trisolv(n, a, x, c);

    // Output the result
    for (int i = 0; i < n; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}
