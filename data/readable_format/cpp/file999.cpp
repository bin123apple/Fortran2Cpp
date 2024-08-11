#include <iostream>
#include <string>

// Function that we are going to test
std::string helloWorld() {
    return "Hello, World!";
}

// Simple test function to verify the correctness of helloWorld()
void testHelloWorld() {
    std::string expected = "Hello, World!";
    std::string result = helloWorld();
    
    if (result == expected) {
        std::cout << "Test passed: helloWorld() returned the expected value." << std::endl;
    } else {
        std::cout << "Test failed: helloWorld() returned '" << result << "' but expected '" << expected << "'" << std::endl;
    }
}

// Main function
int main() {
    // Call the test function
    testHelloWorld();
    return 0;
}