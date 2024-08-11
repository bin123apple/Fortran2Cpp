#include <iostream>
#include <vector>

// Function to test
std::vector<float> createEmptyVector() {
    return std::vector<float>();
}

// Simple test function to verify vector size
void testVectorEmpty() {
    auto vec = createEmptyVector();
    if (vec.size() == 0) {
        std::cout << "Test Passed: Vector is empty as expected." << std::endl;
    } else {
        std::cout << "Test Failed: Vector is not empty." << std::endl;
    }
}

int main() {
    // Running the test
    testVectorEmpty();
    return 0;
}