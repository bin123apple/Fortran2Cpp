#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <omp.h> // Make sure your compiler supports OpenMP.

#define EPS 0.00001

void init(std::vector<float>& v1, std::vector<float>& v2, int N) {
    for (int i = 0; i < N; ++i) {
        v1[i] = i + 2.0f;
        v2[i] = i - 3.0f;
    }
}

void check(const std::vector<float>& p, int N) {
    for (int i = 0; i < N; ++i) {
        float diff = p[i] - (i + 2.0f) * (i - 3.0f);
        if (std::abs(diff) > EPS) {
            std::cerr << "Error: Check failed at index " << i << " with difference " << diff << std::endl;
            std::abort();
        }
    }
}

void vec_mult(std::vector<float>& p, const std::vector<float>& v1, const std::vector<float>& v2, int N) {
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        p[i] = v1[i] * v2[i];
    }
}

int main() {
    int n = 1000;
    std::vector<float> p(n), v1(n), v2(n);

    init(v1, v2, n);
    vec_mult(p, v1, v2, n);
    check(p, n);

    std::cout << "C++ test passed." << std::endl;

    return 0;
}