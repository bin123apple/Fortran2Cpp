#include <iostream>
#include <cstdint>  // For std::int16_t

// Function to sum selected integers based on a mask
std::int16_t sumSelectedIntegers(const std::int16_t* array, size_t size, const bool* mask) {
    std::int16_t sum = 0;
    for (size_t i = 0; i < size; ++i) {
        if (mask[i]) {
            sum += array[i];
        }
    }
    return sum;
}

// Simple function to test 'sumSelectedIntegers' functionality
void testSumSelectedIntegers() {
    std::int16_t array[] = {1, 2, 3, 4, 5};
    bool mask[] = {true, false, true, false, true};
    size_t size = sizeof(array) / sizeof(array[0]);

    std::int16_t expected = 9;  // Expected sum: 1 + 3 + 5
    std::int16_t result = sumSelectedIntegers(array, size, mask);

    if (result == expected) {
        std::cout << "Test passed: The sum is " << result << std::endl;
    } else {
        std::cout << "Test failed: Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    testSumSelectedIntegers();
    return 0;
}