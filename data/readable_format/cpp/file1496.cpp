#include <iostream>
#include <array>

// Function that encapsulates the core logic of the program
std::array<int, 2> calculateNums() {
    std::array<int, 2> nums;
    for (int i = 0; i < 2; ++i) {
        nums[i] = i + 1 + 47; // Adjusted for 0-based indexing
    }
    return nums;
}

// Test function
void testCalculateNums() {
    auto nums = calculateNums();
    bool testPassed = true;

    // Verifying the correctness of each element
    if (nums[0] != 48 || nums[1] != 49) {
        testPassed = false;
    }

    if (testPassed) {
        std::cout << "Test passed: the array contains the correct values." << std::endl;
    } else {
        std::cout << "Test failed: the array does not contain the expected values." << std::endl;
    }
}

int main() {
    // Running the core function and displaying its results
    auto nums = calculateNums();
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Running the test
    testCalculateNums();

    return 0;
}