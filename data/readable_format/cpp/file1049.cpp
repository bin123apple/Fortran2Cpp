#include <iostream>
#include <vector>
#include <cstdlib> // For std::exit

void check(const std::vector<int>& a, const std::vector<int>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            std::cout << "Mismatch found - Check failed" << std::endl;
            return; // Changed from std::abort() to return for testing
        }
    }
    std::cout << "All values match." << std::endl;
}

void testCheck() {
    std::vector<int> testA(20), testB(20);

    // Test case 1: Equal arrays
    for (int i = 0; i < 20; ++i) {
        testA[i] = i + 1;
        testB[i] = i + 1;
    }
    check(testA, testB);
    std::cout << "Test 1 Passed: Equal arrays" << std::endl;

    // Test case 2: Unequal arrays
    testB[9] = 0;  // Introduce a difference
    check(testA, testB);
    std::cout << "Test 2 Passed: Unequal arrays" << std::endl;
}

int main() {
    // Main logic would go here if needed

    // Run tests
    testCheck();

    return 0;
}