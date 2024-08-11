#include <iostream>
#include <cmath>
#include <cassert>

float S2MACH(float XR, int BASE, int EXP) {
    float TBASE = static_cast<float>(BASE);
    float result = XR;
    int N = EXP;

    if (N < 0) {
        N = -N;
        TBASE = 1.0f / TBASE;
    }

    while (N > 0) {
        if (N % 2 != 0) result *= TBASE;
        N /= 2;
        if (N > 0) TBASE *= TBASE;
    }

    return result;
}

void run_tests() {
    // Note: The precision of floating-point arithmetic can lead to small differences.
    // Using a small epsilon value for comparison.
    float epsilon = 1e-5f;

    assert(std::abs(S2MACH(2.0f, 3, 5) - std::pow(3, 5) * 2.0f) < epsilon);
    assert(std::abs(S2MACH(1.0f, 2, -3) - std::pow(2, -3)) < epsilon);
    assert(std::abs(S2MACH(1.5f, 10, 0) - 1.5f) < epsilon);
    assert(std::abs(S2MACH(2.0f, 2, 4) - std::pow(2, 4) * 2.0f) < epsilon);

    std::cout << "All tests passed." << std::endl;
}

int main() {
    run_tests();
    return 0;
}