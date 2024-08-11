#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::min
#include <cmath>     // For std::abs

float sla_gbrpvgrw(int n, int kl, int ku, int ncols, float* ab, int ldab, float* afb, int ldafb) {
    int i, j, kd;
    float amax, umax, rpvgrw = 1.0f;
    kd = ku;

    for (j = 0; j < ncols; ++j) {
        amax = 0.0f;
        umax = 0.0f;
        for (i = std::max(j - ku, 0); i < std::min(j + kl + 1, n); ++i) {
            amax = std::max(std::abs(ab[(kd + i - j) + j * ldab]), amax);
        }
        for (i = std::max(j - ku, 0); i <= j; ++i) {
            umax = std::max(std::abs(afb[(kd + i - j) + j * ldafb]), umax);
        }
        if (umax != 0.0f) {
            rpvgrw = std::min(amax / umax, rpvgrw);
        }
    }

    return rpvgrw;
}

int main() {
    const int n = 3, kl = 1, ku = 1, ncols = 3, ldab = 3, ldafb = 3;
    std::vector<float> AB = {
        1.0f, 2.0f, 0.0f,
        3.0f, 4.0f, 1.0f,
        0.0f, 3.0f, 5.0f
    };
    std::vector<float> AFB = {
        0.5f, 1.0f, 0.0f,
        1.5f, 2.0f, 0.5f,
        0.0f, 1.5f, 2.5f
    };

    float result = sla_gbrpvgrw(n, kl, ku, ncols, AB.data(), ldab, AFB.data(), ldafb);
    std::cout << "Result: " << result << std::endl;
    return 0;
}