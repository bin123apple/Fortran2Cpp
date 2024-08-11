#include <iostream>
#include <vector>
#include <cassert>

// Function declaration
int sum0_i(const std::vector<int>& dv_array, const std::vector<bool>& dv_mask);

int main() {
    std::vector<int> testArray = {1, 2, 3, 4};
    std::vector<bool> testMask = {true, false, true, false};
    int expectedSum = 4; // 1 + 3 = 4

    int calculatedSum = sum0_i(testArray, testMask);
    
    assert(calculatedSum == expectedSum);
    std::cout << "Test Passed: Sum is " << calculatedSum << std::endl;

    return 0;
}

// Function implementation
int sum0_i(const std::vector<int>& dv_array, const std::vector<bool>& dv_mask) {
    int result = 0;
    for(std::size_t i = 0; i < dv_array.size() && i < dv_mask.size(); ++i) {
        if (dv_mask[i]) {
            result += dv_array[i];
        }
    }
    return result;
}