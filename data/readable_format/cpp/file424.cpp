#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void floop23_F90(int N, std::vector<float>& x, const std::vector<float>& a, const std::vector<float>& b, const std::vector<float>& c, const std::vector<float>& d, std::vector<float>& y) {
    for (int i = 0; i < N; ++i) {
        x[i] = a[i] * b[i] + c[i] * d[i];
        y[i] = b[i] + d[i];
    }
}

bool compare_vectors(const std::vector<float>& v1, const std::vector<float>& v2, float tolerance = 0.001f) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (std::fabs(v1[i] - v2[i]) > tolerance) return false;
    }
    return true;
}

int main() {
    int N = 5;
    std::vector<float> x(N), a = {1, 2, 3, 4, 5}, b = {5, 4, 3, 2, 1}, c = {1, 2, 3, 4, 5}, d = {5, 4, 3, 2, 1}, y(N);

    floop23_F90(N, x, a, b, c, d, y);

    assert(compare_vectors(x, {10, 16, 18, 16, 10}));
    assert(compare_vectors(y, {10, 8, 6, 4, 2}));

    std::cout << "C++ Test Passed: " << std::endl;
    std::cout << "x = ";
    for (const auto& val : x) std::cout << val << " ";
    std::cout << std::endl << "y = ";
    for (const auto& val : y) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}