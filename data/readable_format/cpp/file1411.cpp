#include <iostream>
#include <array>

// Function Declarations
std::array<std::array<int, 3>, 2> initializeArray();
void printArray(const std::array<std::array<int, 3>, 2>& a);
void testArrayInitialization(const std::array<std::array<int, 3>, 2>& a);

int main() {
    auto a = initializeArray();
    printArray(a);
    testArrayInitialization(a);
    return 0;
}

// Function Definitions
std::array<std::array<int, 3>, 2> initializeArray() {
    std::array<std::array<int, 3>, 2> a{};
    int count = 0;
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 3; ++col) {
            a[row][col] = ++count;
        }
    }
    return a;
}

void printArray(const std::array<std::array<int, 3>, 2>& a) {
    for (const auto& row : a) {
        for (int val : row) {
            std::cout << val << std::endl;
        }
    }
}

void testArrayInitialization(const std::array<std::array<int, 3>, 2>& a) {
    bool testPassed = true;
    int expectedValue = 1;
    for (const auto& row : a) {
        for (int val : row) {
            if (val != expectedValue++) {
                std::cout << "C++ Test Failed: Value is " << val << ", expected " << (expectedValue - 1) << std::endl;
                testPassed = false;
            }
        }
    }
    if (testPassed) {
        std::cout << "C++ Test Passed: Array initialized correctly." << std::endl;
    }
}