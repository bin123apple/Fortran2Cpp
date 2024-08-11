#include <iostream>
#include <vector>
#include <cstdlib> // For std::abort()

int main() {
    const int N = 8;
    std::vector<float> a(N), b(N);

    // Initialize vectors
    std::fill(a.begin(), a.end(), 3.0f);
    std::fill(b.begin(), b.end(), 0.0f);

    // OpenMP doesn't have direct equivalents for data region directives as OpenACC,
    // so we'll focus on the parallel loop execution part.
    
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        b[i] = a[i];
    }

    // Verification
    for (int i = 0; i < N; ++i) {
        if (a[i] != 3.0f) std::abort();
        if (b[i] != 3.0f) std::abort();
    }

    // Update vectors
    std::fill(a.begin(), a.end(), 5.0f);
    std::fill(b.begin(), b.end(), 1.0f);

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        b[i] = a[i];
    }

    // Verification
    for (int i = 0; i < N; ++i) {
        if (a[i] != 5.0f) std::abort();
        if (b[i] != 5.0f) std::abort();
    }

    return 0;
}