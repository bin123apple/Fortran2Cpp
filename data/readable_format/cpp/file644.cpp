#include <iostream>
#include <array>

// Function to add two arrays
void addArrays(const std::array<float, 5>& array1, const std::array<float, 5>& array2, std::array<float, 5>& sumArray) {
    for (size_t i = 0; i < sumArray.size(); ++i) {
        sumArray[i] = array1[i] + array2[i];
    }
}

// Manual test for the addArrays function
void testAddArrays() {
    std::array<float, 5> testArray1 = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::array<float, 5> testArray2 = {5.0, 4.0, 3.0, 2.0, 1.0};
    std::array<float, 5> expectedSum = {6.0, 6.0, 6.0, 6.0, 6.0};
    std::array<float, 5> resultSum;

    addArrays(testArray1, testArray2, resultSum);

    bool testPassed = true;
    for (size_t i = 0; i < resultSum.size(); ++i) {
        if (resultSum[i] != expectedSum[i]) {
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    testAddArrays();
    return 0;
}