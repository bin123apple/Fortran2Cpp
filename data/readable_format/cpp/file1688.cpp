#include <iostream>
#include <climits>
#include <vector>
#include <cassert> // For assert()

std::vector<int> generateLast11Values() {
    std::vector<int> values;
    // Use int for loop control to safely handle incrementing past CHAR_MAX
    for (int i = static_cast<int>(CHAR_MAX) - 10; i <= static_cast<int>(CHAR_MAX); ++i) {
        values.push_back(i);
    }
    return values;
}

void testLast11Values() {
    std::vector<int> expectedValues;
    for (int i = CHAR_MAX - 10; i <= CHAR_MAX; ++i) {
        expectedValues.push_back(i);
    }

    std::vector<int> actualValues = generateLast11Values();

    // Using assert for a simple check, but more sophisticated testing frameworks can provide better reporting
    assert(actualValues == expectedValues && "Test failed: The last 11 values are not as expected.");
    std::cout << "Test passed: The last 11 values are as expected." << std::endl;
}

int main() {
    // Run your test
    testLast11Values();

    // You can also place the original program logic here if needed
    for (int val : generateLast11Values()) {
        std::cout << val << std::endl;
    }

    return 0;
}