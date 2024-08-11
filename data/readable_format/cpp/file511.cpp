#include <iostream>
#include <cstdlib> // For std::abort()

int main() {
    int i, j, k, l, r;
    int a[30];
    int q[30];
    int* p = nullptr;

    // Initialize arrays a and q
    for (i = 0; i < 30; ++i) {
        a[i] = 1;
        q[i] = 1;
    }

    // Pointer p points to the first element of array q
    p = &q[0];

    r = 0;
    j = 10;
    k = 20;

    // OpenMP pragma for SIMD. Note: C++ may have different support/syntax for OpenMP features.
    // Ensure your compiler supports OpenMP and the features you use.
    #pragma omp simd safelen(8) reduction(+:r) linear(j, k:2) private(l) aligned(p:4)
    for (i = 0; i < 30; ++i) {
        l = j + k + a[i] + p[i];
        r += l;
        j += 2;
        k += 2;
    }

    if (r != 2700 || j != 70 || k != 80) std::abort();

    return 0;
}