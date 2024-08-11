#include <iostream>

// Define the namespace and array directly in this file
namespace cb {
    constexpr int rows = 10;
    constexpr int cols = 10;
    float b[rows][cols] = {}; // Initialize with zeros
}

int main() {
    // Set a value
    cb::b[5][5] = 3.14f; // Remember, C++ uses 0-based indexing

    // Test
    if (cb::b[5][5] == 3.14f) {
        std::cout << "Test passed: b[5][5] is 3.14" << std::endl;
    } else {
        std::cout << "Test failed: b[5][5] is not 3.14" << std::endl;
    }

    return 0;
}