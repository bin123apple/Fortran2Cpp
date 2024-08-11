#include <iostream>
#include <array>
#include <cstdlib> // for std::abort

void test_main_program() {
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    std::array<int, 5> b = {0, 0, 0, 0, 0};
    std::array<int, 5> expected_b = {0, 2, 2, 2, 2};

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != 1) {
            b[i] = 2;
        }
    }

    for (size_t i = 0; i < b.size(); ++i) {
        if (b[i] != expected_b[i]) {
            std::cerr << "Test failed: b array does not match expected values." << std::endl;
            std::abort();
        }
    }
    std::cout << "Test passed: b = { ";
    for (const auto& val : b) {
        std::cout << val << " ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    test_main_program();
    return 0;
}