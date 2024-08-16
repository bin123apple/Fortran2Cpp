#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int N = 100;
    std::vector<std::vector<float>> a(N, std::vector<float>(N)); // Matrix of size NxN
    std::vector<float> v(N); // Vector of size N
    std::vector<float> v_out(N); // Vector of size N for output

    // Initialize matrix a and vector v with some values (not shown in the original code)

    #pragma omp parallel for collapse(2) private(j, sum)
    for (int i = 0; i < N; ++i) {
        float sum = 0.0f;
        for (int j = 0; j < N; ++j) {
            sum += a[i][j] * v[j];
        }
        v_out[i] = sum;
    }
}

int main() {
    foo();
    return 0;
}
