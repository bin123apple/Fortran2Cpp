#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int n = 100;
    int m = 100;
    std::vector<std::vector<float>> b(n, std::vector<float>(m));

    // Initialization of b
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = (i + 1) * (j + 1); // +1 to match Fortran's 1-based indexing
        }
    }

    // Parallel region for the inner loop
    for (int i = 1; i < n; ++i) {
        #pragma omp parallel for collapse(2)
        for (int j = 1; j < m; ++j) {
            b[i][j] = b[i - 1][j - 1];
        }
    }

    // No need to explicitly deallocate b, as it will be automatically done by the vector destructor
    return 0;
}
