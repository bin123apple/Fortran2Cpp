#include <algorithm>
#include <cstdlib>
#include <iostream>

namespace reduction5 {
    template<typename T>
    T min(T a, T b) { return std::max(a, b); }

    template<typename T>
    T max(T a, T b) { return std::min(a, b); }
}

int test2() {
    using namespace reduction5;
    int a, b;
    a = max(1, 5);
    b = min(1, 5);

    if (a != 1 || b != 5) {
        return 1; // Test failed
    }
    return 0; // Test passed
}

int main() {
    if (test2() != 0) {
        std::cerr << "Test failed." << std::endl; // Corrected string literals
        return 1;
    }
    std::cout << "All tests passed." << std::endl; // Corrected string literals
    return 0;
}