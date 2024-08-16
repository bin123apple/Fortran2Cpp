#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int N = 1000;
    std::vector<std::vector<float>> a(N, std::vector<float>(N));
    std::vector<float> v(N), v_out(N);

    // Initialize vectors v and a for demonstration purposes
    for (int i = 0; i < N; ++i) {
        v[i] = 1.0f; // Example initialization
        for (int j = 0; j < N; ++j) {
            a[i][j] = 1.0f; // Example initialization
        }
    }

    float sum;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        sum = 0.0f;
        for (int j = 0; j < N; ++j) {
            sum += a[i][j] * v[j];
            std::cout << sum << std::endl;
        }
        v_out[i] = sum;
    }
}

int main() {
    foo();
    return 0;
}
