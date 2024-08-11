#include <iostream>
#include <array>

// Function to check if all elements in the 3x3 array are 2
bool checkArrayFilledWithTwos(const std::array<std::array<int, 3>, 3>& a) {
    for (const auto& row : a) {
        for (int elem : row) {
            if (elem != 2) {
                return false;
            }
        }
    }
    return true;
}

// Simple function for running tests
void runTests() {
    std::array<std::array<int, 3>, 3> a{};

    // Test 1: Check if all elements are set to 2
    for (int l = 0; l < 3; ++l) {
        for (int ll = 0; ll < 3; ++ll) {
            a[l][ll] = 2;
        }
    }

    if (checkArrayFilledWithTwos(a)) {
        std::cout << "Test 1 Passed: All elements are correctly set to 2." << std::endl;
    } else {
        std::cout << "Test 1 Failed." << std::endl;
    }
}

int main() {
    // Run the tests
    runTests();

    return 0;
}