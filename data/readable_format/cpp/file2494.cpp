#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

namespace e_50_3_mod {

void init(std::vector<float>& v1, std::vector<float>& v2, int N) {
    for (int i = 0; i < N; ++i) {
        v1[i] = i + 2.0f;
        v2[i] = i - 3.0f;
    }
}

void check(const std::vector<float>& p, int N) {
    const float EPS = 0.00001f;
    for (int i = 0; i < N; ++i) {
        float diff = p[i] - (i + 2.0f) * (i - 3.0f);
        if (std::fabs(diff) > EPS) {
            std::cerr << "Check failed at index " << i << " with difference " << diff << std::endl;
            std::exit(1);
        }
    }
}

void vec_mult(int N) {
    std::vector<float> p(N), v1(N), v2(N);
    init(v1, v2, N);

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        p[i] = v1[i] * v2[i];
    }

    check(p, N);
}

} // namespace e_50_3_mod

void test_vec_mult() {
    int n;

    // Test case 1: Small size
    n = 10;
    e_50_3_mod::vec_mult(n);
    std::cout << "Test case 1 passed." << std::endl;

    // Test case 2: Medium size
    n = 100;
    e_50_3_mod::vec_mult(n);
    std::cout << "Test case 2 passed." << std::endl;

    // Test case 3: Larger size
    n = 1000;
    e_50_3_mod::vec_mult(n);
    std::cout << "Test case 3 passed." << std::endl;

    // Add more test cases as needed
}

int main() {
    test_vec_mult();
    return 0;
}