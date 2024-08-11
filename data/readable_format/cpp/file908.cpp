#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int N = 100;
    std::vector<float> A(N), B(N);
    float sum = 0.0;

    // Initialization of A and B
    for (int i = 0; i < N; ++i) {
        A[i] = (i + 1) * 1.0; // Adjust for 0-based indexing
        B[i] = A[i];
    }

    // Parallel reduction to compute the sum
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        sum += A[i] * B[i];
    }

    std::cout << "   Sum = " << sum << std::endl;

    return 0;
}