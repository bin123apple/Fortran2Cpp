#include <array>

void iau_CP(const std::array<double, 3>& P, std::array<double, 3>& C) {
    for (int i = 0; i < 3; ++i) {
        C[i] = P[i];
    }
}