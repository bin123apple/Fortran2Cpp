#include <array>
#include <algorithm>

int main() {
    const int imax = 3;
    std::array<float, imax+1> a{}; // C++ arrays are 0-indexed, size is imax+1 to include 0:imax range
    std::array<float, imax+1> b{};

    // Copying elements from array b to array a
    std::copy(b.begin(), b.end(), a.begin());

    return 0;
}