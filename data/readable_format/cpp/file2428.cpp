#include <iostream>
#include <complex>
#include <cassert>

void clascl2(int M, int N, const float* D, std::complex<float>* X, int LDX) {
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < M; ++i) {
            X[i + j * LDX] *= D[i];
        }
    }
}

int main() {
    const int M = 3;
    const int N = 2;
    const int LDX = 3;

    float D[M] = {1.0f, 2.0f, 3.0f};
    std::complex<float> X[M * N] = {
        {1.0f, 0.0f}, {2.0f, 0.0f}, {3.0f, 0.0f},
        {4.0f, 0.0f}, {5.0f, 0.0f}, {6.0f, 0.0f}
    };

    clascl2(M, N, D, X, LDX);

    // Print the results for verification
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < M; ++i) {
            std::complex<float> result = X[i + j * LDX];
            std::cout << "X(" << i+1 << "," << j+1 << ") = (" << result.real() << "," << result.imag() << ")";
        }
    }

    return 0;
}