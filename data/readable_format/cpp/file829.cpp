#include <iostream>
#include <vector>

// Function definition
int intCnt(int target, const std::vector<int>& list) {
    int count = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == target) {
            count++;
        }
    }
    return count;
}

// Main function with tests
int main() {
    // Test 1: List with multiple occurrences
    std::vector<int> testList = {1, 2, 3, 2, 4};
    if (intCnt(2, testList) == 2) {
        std::cout << "Test 1 Passed" << std::endl;
    } else {
        std::cout << "Test 1 Failed" << std::endl;
    }

    // Test 2: List with no occurrence
    if (intCnt(5, testList) == 0) {
        std::cout << "Test 2 Passed" << std::endl;
    } else {
        std::cout << "Test 2 Failed" << std::endl;
    }

    // Test 3: Empty list
    std::vector<int> emptyList;
    if (intCnt(1, emptyList) == 0) {
        std::cout << "Test 3 Passed" << std::endl;
    } else {
        std::cout << "Test 3 Failed" << std::endl;
    }

    return 0;
}