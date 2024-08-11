#include <iostream>
#include <vector>

// A simple function to test
int increment(int value) {
    return value + 1;
}

// A simple test function for 'increment'
void testIncrement() {
    if (increment(5) == 6) {
        std::cout << "Test passed: increment(5) == 6" << std::endl;
    } else {
        std::cout << "Test failed: increment(5) != 6" << std::endl;
    }
}

int main() {
    // Call the test function
    testIncrement();

    // Main program logic
    int result = increment(10);
    std::cout << "Incrementing 10 gives: " << result << std::endl;

    return 0;
}