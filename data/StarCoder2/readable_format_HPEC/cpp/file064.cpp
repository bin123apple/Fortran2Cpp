#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int n = 20;
    std::vector<std::vector<float>> a(n, std::vector<float>(n, 0.0f));

    // Initialize the array
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0.0f;
        }
    }

    // Parallel region
    for (int i = 0; i < n - 1; ++i) {
        #pragma omp parallel for
        for (int j = 0; j < n; ++j) {
            a[i][j] = a[i][j] + a[i + 1][j];
        }
    }

    return 0;
}
