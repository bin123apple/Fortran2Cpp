#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstddef>

const double EPS = 0.0000000000001;

void init(std::vector<double>& a, std::vector<double>& a_ref, std::vector<double>& b, std::vector<double>& c, int n, int offset) {
    int s = -1;
    for (int i = 0; i < n; ++i) {
        a[i] = (i + 1) * (i + 1) * s;
        a_ref[i] = a[i];
        b[i] = (i + 1) + (i + 1);
    }

    for (int i = 0; i < n + offset; ++i) {
        c[i] = (i + 1) * 3;
    }
}

void check(const std::vector<double>& a, const std::vector<double>& b, int n) {
    for (int i = 0; i < n; ++i) {
        double diff = a[i] - b[i];
        if (std::abs(diff) > EPS) {
            std::abort();
        }
    }
}

void star(std::vector<double>& a, std::vector<double>& a_ref, std::vector<double>& b, std::vector<double>& c, int n, int offset) {
    init(a, a_ref, b, c, n, offset);

    // Simulate OpenMP SIMD with a simple for loop
    for (int i = 0; i < n; ++i) {
        a[i] = a[i] * b[i] * c[i + offset];
    }

    for (int i = 0; i < n; ++i) {
        a_ref[i] = a_ref[i] * b[i] * c[i + offset];
    }

    check(a, a_ref, n);
}

int main() {
    const int N = 128;
    const int OFFSET = 16;

    std::vector<double> a(N);
    std::vector<double> a_ref(N);
    std::vector<double> b(N);
    std::vector<double> c(N + OFFSET);

    star(a, a_ref, b, c, N, OFFSET);

    std::cout << "Computation completed successfully!" << std::endl;

    return 0;
}