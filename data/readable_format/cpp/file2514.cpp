#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

void init(std::vector<float>& v1, std::vector<float>& v2, int N) {
    for (int i = 0; i < N; ++i) {
        v1[i] = static_cast<float>(i) + 2.0f;
        v2[i] = static_cast<float>(i) - 3.0f;
    }
}

void check(const std::vector<float>& p, int N) {
    const float EPS = 0.00001f;
    for (int i = 0; i < N; ++i) {
        float diff = p[i] - ((static_cast<float>(i) + 2.0f) * (static_cast<float>(i) - 3.0f));
        if (std::abs(diff) > EPS) {
            std::cerr << "Check failed at index " << i << " with diff " << diff << std::endl;
            std::abort();
        }
    }
}

void vec_mult(int N) {
    std::vector<float> p(N), v1(N), v2(N);
    init(v1, v2, N);

    // Use OpenMP for parallelization without targeting GPU offloading
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        p[i] = v1[i] * v2[i];
    }

    check(p, N);
}

int main() {
    int n = 1000;
    vec_mult(n);
    std::cout << "All tests passed!" << std::endl;
    return 0;
}