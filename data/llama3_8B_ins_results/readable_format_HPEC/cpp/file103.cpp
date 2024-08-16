#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int N, M, K;
    int len = 100;

    N = len;
    M = len;
    K = len;

    std::vector<std::vector<double>> a(N, std::vector<double>(M));
    std::vector<std::vector<double>> b(M, std::vector<double>(K));
    std::vector<std::vector<double>> c(K, std::vector<double>(N));

    #pragma omp parallel for private(j, l)
    for (int i = 0; i < N; i++) {
        for (int l = 0; l < K; l++) {
            for (int j = 0; j < M; j++) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    // Deallocate memory (not necessary in C++ since vectors manage their own memory)
    // deallocate(a,b,c);

    return 0;
}
