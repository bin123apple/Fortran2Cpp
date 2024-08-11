// euler_stability.cpp
#include <iostream>
#include <cmath>
#include <iomanip>

float f(float x, float t) {
    return -100.0f * x + 100.0f * t + 101.0f;
}

int main() {
    int N;
    float x, h;

    h = 0.1f;
    N = static_cast<int>(1.0f / h + 0.5f); // Using +0.5f for rounding to nearest int

    x = 1.01f;
    std::cout << std::fixed << std::setprecision(2) << 0.00 << " " << x << std::endl;
    for (int i = 1; i <= N; ++i) {
        x = x + h * f(x, (i - 1) * h);
        std::cout << std::fixed << std::setprecision(2) << i * h << " " << x << std::endl;
    }

    return 0;
}