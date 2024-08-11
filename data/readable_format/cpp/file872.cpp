#include <array>
#include <iostream>

void foo(std::array<int, 4>& a) {
    for (auto& elem : a) {
        if (elem != 0) {
            elem = 1;
        }
    }
}

void printArray(const std::array<int, 4>& a) {
    for (const auto& elem : a) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void testFoo(std::array<int, 4> a) {
    foo(a);
    printArray(a);
}

int main() {
    // Test case 1: All elements are non-zero
    testFoo({1, 2, 3, 4});

    // Test case 2: Some elements are zero
    testFoo({0, 2, 0, 4});

    // Test case 3: All elements are zero
    testFoo({0, 0, 0, 0});

    return 0;
}