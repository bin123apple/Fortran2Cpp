#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int N, M, K, len;
    len = 100;
    N = len;
    M = len;
    K = len;

    // Allocate and initialize matrices a, b, and c
    std::vector<std::vector<float>> a(N, std::vector<float>(M));
    std::vector<std::vector<float>> b(M, std::vector<float>(K));
    std::vector<std::vector<float>> c(K, std::vector<float>(N));

    // Initialize matrices a and b with some values (optional, for demonstration)
    // ...

    // Parallel loop to multiply matrices a and b and store the result in matrix c
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int l = 0; l < K; ++l) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    // No need to explicitly deallocate the vectors, as they will automatically be destroyed
    return 0;
}
