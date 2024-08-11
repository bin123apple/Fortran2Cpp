#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

// Namespace foo
namespace foo {
    int i;
}

// Namespace bar
namespace bar {
    void baz(std::vector<int>& j) {
        if (j.size() != static_cast<size_t>(foo::i)) {
            std::cerr << "Array length mismatch." << std::endl;
            std::exit(1); // Exiting the whole program might not be ideal for real unit tests, consider throwing an exception in real scenarios
        }

        for (int n = 0; n < foo::i; ++n) {
            if (j[n] != std::pow(n + 1, 2)) {
                std::cerr << "Condition failed." << std::endl;
                std::exit(1);
            }
        }
    }
}

// Simplified testing functions
void testBaz(const std::vector<int>& testVector, int expectedSize) {
    foo::i = expectedSize;
    try {
        bar::baz(const_cast<std::vector<int>&>(testVector)); // Not ideal, but necessary for compatibility with the example test structure
        std::cout << "Test Passed. Size: " << expectedSize << std::endl;
    } catch (...) {
        std::cout << "Test Failed. Size: " << expectedSize << std::endl;
    }
}

int main() {
    // Test cases
    std::vector<int> test1 = {1, 4};
    testBaz(test1, 2);

    std::vector<int> test2 = {1, 4, 9, 16, 25, 36, 49};
    testBaz(test2, 7);

    // Add more tests as needed

    return 0;
}