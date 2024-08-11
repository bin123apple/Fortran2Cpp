#include <iostream>
#include <array>
#include <cmath> // For fabs function

int main() {
    std::array<float, 3> yv1 = {1.0, 2.0, 3.0};
    std::array<float, 3> yv2 = {4.0, 5.0, 6.0};
    std::array<float, 3> oidpsv = {0.5, 0.5, 0.5};
    std::array<float, 3> mtc = {1.0, 1.0, 1.0};
    std::array<float, 3> strackc = {0.1, 0.2, 0.3};
    std::array<float, 3> stracks = {0.4, 0.5, 0.6};
    float crkve = 2.0;
    float cikve = 3.0;

    int i = 1; // Adjusting for 0-based indexing
    for (int j = 0; j < 3; ++j) {
        yv1[j] = yv1[j] + (oidpsv[j] * (strackc[i] * crkve + stracks[i] * cikve)) * mtc[j];
        yv2[j] = yv2[j] + (oidpsv[j] * (stracks[i] * crkve - strackc[i] * cikve)) * mtc[j];
    }

    // Print results to verify correctness
    std::cout << "yv1: ";
    for (const auto& val : yv1) std::cout << val << " ";
    std::cout << std::endl; // Correctly adding newline for C++

    std::cout << "yv2: ";
    for (const auto& val : yv2) std::cout << val << " ";
    std::cout << std::endl; // Correctly adding newline for C++

    return 0;
}