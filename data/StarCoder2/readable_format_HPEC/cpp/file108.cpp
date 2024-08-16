#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int N = 100;
    std::vector<std::vector<float>> a(N, std::vector<float>(N));
    std::vector<float> v(N), v_out(N);

    // Initialize a and v with some values (optional, for demonstration)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = static_cast<float>(i * N + j);
        }
        v[i] = static_cast<float>(i);
    }

    #pragma omp parallel for collapse(2)
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
