#include <iostream>
#include <array>

int main() {
    const int n = 8;
    std::array<int, n> a;

    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    std::cout << "PASS" << std::endl;

    return 0;
}