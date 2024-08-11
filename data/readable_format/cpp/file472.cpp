#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>

// Utility function simulating basic testing
void assertCondition(bool condition, const std::string& errorMessage) {
    if (!condition) {
        std::cerr << "Assertion failed: " << errorMessage << std::endl;
        std::exit(EXIT_FAILURE); // Exit the program with a failure status
    }
}

int main() {
    // Initialize and populate the array
    std::vector<int> arr(12);
    std::iota(arr.begin(), arr.end(), 1);
    
    // Test array initialization
    for (int i = 0; i < 12; ++i) {
        assertCondition(arr[i] == i + 1, "Array initialization failed.");
    }
    
    // Simulate the reshaping and subsetting with manual checks
    // Note: This is a simplified example to demonstrate testing without external libraries
    
    // Example: Check the first and last elements to simulate reshaping
    int expectedFirst = 1;
    int expectedLast = 12;
    assertCondition(arr.front() == expectedFirst && arr.back() == expectedLast, "Reshape test failed.");

    // Subset simulation - Check for elements at even positions
    std::vector<int> subset;
    for (int i = 0; i < arr.size(); i += 2) {
        subset.push_back(arr[i]);
    }
    assertCondition(subset.size() == 6, "Subset size incorrect.");
    for (size_t i = 0; i < subset.size(); ++i) {
        assertCondition(subset[i] == arr[i * 2], "Subset content incorrect.");
    }
    
    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}