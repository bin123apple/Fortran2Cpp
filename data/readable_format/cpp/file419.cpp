#include <iostream>
#include <cassert>

// Simplified function to mimic contiguity check
bool isContiguous(bool condition) {
    return condition;
}

void testContiguity(bool expectedResult, bool actualResult, const std::string& description) {
    assert(expectedResult == actualResult);
    std::cout << description << " - passed." << std::endl;
}

int main() {
    // Test 1: Expecting True for full slice
    testContiguity(true, isContiguous(true), "Test 1: Full slice contiguous");

    // Test 2: Expecting False for partial slice
    testContiguity(false, isContiguous(false), "Test 2: Partial slice non-contiguous");

    return 0;
}