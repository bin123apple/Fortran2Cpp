#include <iostream>
#include <mutex>

// Global mutex for demonstration purposes
std::mutex mtx;

// Function to test
void increment(int& sharedVar) {
    std::lock_guard<std::mutex> lock(mtx);
    sharedVar += 1;
}

// A simple test function that replaces the need for a unit testing framework
void testIncrement() {
    int testVar = 0;
    increment(testVar);
    if (testVar == 1) {
        std::cout << "Test passed: testVar incremented successfully." << std::endl;
    } else {
        std::cerr << "Test failed: testVar should be 1 after increment, but found " << testVar << std::endl;
    }
}

int main() {
    // Run the test
    testIncrement();
    return 0;
}