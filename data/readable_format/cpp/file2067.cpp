#include <iostream>

extern "C" {
    void one(int& i) {
        i += 1;
    }
}

// Simple Test Function
void testOneFunction() {
    int testVal = 0;
    one(testVal); // Call the function to increment testVal
    if (testVal == 1) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected 1 but got " << testVal << std::endl;
    }
}

int main() {
    testOneFunction(); // Run the test
    return 0;
}