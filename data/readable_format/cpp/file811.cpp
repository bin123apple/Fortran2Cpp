#include <iostream>
#include <omp.h>

int main() {
    int u[1024], v[1024], w[1024];
    int a, b, c, d, e;
    int a1, b1, a2, b2, d1, d2;

    // Initialize arrays
    for (int i = 0; i < 1024; ++i) {
        v[i] = i + 1; // Adjusting for 1-based equivalent values
        w[i] = 1025 - (i + 1); // Adjusting for 1-based equivalent values
    }

    a = 0; // Adjusted for 0-based indexing
    b = 1024;
    c = 17;
    d = 75;

    #pragma omp parallel for
    for (d = a; d < b; ++d) {
        u[d] = v[d] + w[d];
    }

    #pragma omp parallel for private(d) lastprivate(e)
    for (d = a; d < b; ++d) {
        u[d] = v[d] + w[d];
        e = c + d * 5;
    }

    a1 = 0;
    b1 = 31;
    a2 = 0;
    b2 = 31;

    #pragma omp parallel for collapse(2) private(d1, d2)
    for (d1 = a1; d1 <= b1; ++d1) {
        for (d2 = a2; d2 <= b2; ++d2) {
            u[d1 * 32 + d2] = v[d1 * 32 + d2] + w[d1 * 32 + d2];
        }
    }

    // Test results
    for (int i = 0; i < 1024; ++i) {
        if (u[i] != 1025) {
            std::cout << "Test failed at index: " << i << std::endl;
            return 1;
        }
    }
    std::cout << "All tests passed." << std::endl;

    return 0;
}