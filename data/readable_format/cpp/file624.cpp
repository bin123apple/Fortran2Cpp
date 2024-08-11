#include <iostream>
#include <array>

int main() {
    const int imax = 3;
    std::array<float, imax + 1> a{}; // +1 to account for 0-based indexing
    std::array<float, imax + 1> b{};

    // Assuming b is already initialized or filled with values somewhere
    // Copying b into a
    a = b;

    return 0;
}