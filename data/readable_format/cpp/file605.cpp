#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>

bool check_arrays() {
    std::array<float, 3> a = {128, 128, 128};
    std::array<float, 3> b = {0, 0, 0};
    std::array<float, 3> c;

    for (int i = 1; i <= 16; ++i) {
        c = {static_cast<float>(i), static_cast<float>(i - 5), static_cast<float>(i + 5)};
        std::transform(a.begin(), a.end(), c.begin(), a.begin(), [](float aVal, float cVal) { return std::min(aVal, cVal); });
        std::transform(b.begin(), b.end(), c.begin(), b.begin(), [](float bVal, float cVal) { return std::max(bVal, cVal); });
    }

    std::array<float, 3> expectedA = {1, -4, 6};
    std::array<float, 3> expectedB = {16, 11, 21};

    return std::equal(a.begin(), a.end(), expectedA.begin()) && std::equal(b.begin(), b.end(), expectedB.begin());
}

int main() {
    if (check_arrays()) {
        std::cout << "Test Passed" << std::endl; // Corrected string
    } else {
        std::cout << "Test Failed" << std::endl; // Corrected string
    }
    return 0;
}