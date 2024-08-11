#include <array>

void iau_PPP(const std::array<double, 3>& A, const std::array<double, 3>& B, std::array<double, 3>& APB) {
    for (int i = 0; i < 3; ++i) {
        APB[i] = A[i] + B[i];
    }
}