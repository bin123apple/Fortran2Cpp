#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int N, M, K, len, i, j, l;
    len = 100;
    N = len;
    M = len;
    K = len;

    std::vector<std::vector<float>> a(N, std::vector<float>(M));
    std::vector<std::vector<float>> b(M, std::vector<float>(K));
    std::vector<std::vector<float>> c(K, std::vector<float>(N));

    // Initialize matrices a and b with some values (for demonstration purposes)
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            a[i][j] = 1.0f; // Example value
        }
    }

    for (i = 0; i < M; ++i) {
        for (j = 0; j < K; ++j) {
            b[i][j] = 1.0f; // Example value
        }
    }

    // Matrix multiplication
    #pragma omp parallel for collapse(2)
    for (i = 0; i < N; ++i) {
        for (l = 0; l < K; ++l) {
            for (j = 0; j < M; ++j) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    // Deallocate matrices
    a.clear();
    b.clear();
    c.clear();

    return 0;
}
