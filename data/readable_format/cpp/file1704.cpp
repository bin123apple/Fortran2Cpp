#include <iostream>
#include <string>
#include <array>
#include <algorithm>

// Function under test
bool checkMinMax(const std::array<std::string, 3>& s, const std::string& minExpected, const std::string& maxExpected) {
    auto minElement = *std::min_element(s.begin(), s.end());
    auto maxElement = *std::max_element(s.begin(), s.end());

    return minElement == minExpected && maxElement == maxExpected;
}

// Simple assertion function to validate test outcomes
void assertTest(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << testName << " Passed" << std::endl;
    } else {
        std::cout << testName << " Failed" << std::endl;
    }
}

// Main function to run tests
int main() {
    std::array<std::string, 3> s = {{"a", "b", "c"}};
    // Test 1: Check if 'a' is the minimum and 'c' is the maximum
    assertTest(checkMinMax(s, "a", "c"), "Test 1: Min 'a' and Max 'c'");

    // Additional tests can be added here following the same pattern
    // For example, testing with a different set or expected values
    // assertTest(checkMinMax(otherSet, "expectedMin", "expectedMax"), "Test Description");

    return 0;
}