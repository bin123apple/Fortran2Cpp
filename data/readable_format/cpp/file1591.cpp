#include <iostream>

namespace mod12 {
    // Simple function to demonstrate functionality
    int square(int x) {
        return x * x;
    }
}

int main() {
    // Testing the square function
    int testValue = 4;
    int result = mod12::square(testValue);

    std::cout << "Square of " << testValue << " is " << result << std::endl;

    if (result == testValue * testValue) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return 0;
}