#include <iostream>
#include <array>
#include <cstdlib>
#include <algorithm>

const int N = 5;
std::array<std::array<int, N>, N> A;

void FOO(int K) {
    int B;
    A[0][0] = 1;

    while (true) {
        B = 0;
        
        for (int I = 0; I < K; ++I) {
            for (int J = 0; J < K; ++J) {
                B += A[I][J];
            }
            A[I][I] *= 2;
        }
        
        if (B >= 3) {
            return;
        }
    }
}

void ABORT() {
    std::cerr << "Abort called!" << std::endl;
    std::exit(EXIT_FAILURE);
}

int main() {
    A.fill({0});
    FOO(2);

    if (A[0][0] != 8) {
        ABORT();
    }

    A[0][0] = 0;

    if (std::any_of(A.begin(), A.end(), [](const std::array<int, N>& row) {
            return std::any_of(row.begin(), row.end(), [](int val) { return val != 0; });
        })) {
        ABORT();
    }

    return 0;
}