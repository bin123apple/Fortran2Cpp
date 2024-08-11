#include <array>

void iau_PVUP(double DT, const std::array<std::array<double, 2>, 3>& PV, std::array<double, 3>& P) {
    for (int i = 0; i < 3; ++i) {
        P[i] = PV[i][0] + PV[i][1] * DT;
    }
}