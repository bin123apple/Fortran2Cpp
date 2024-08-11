// program_and_test.cpp
#include <iostream>
#include <string>

void test(const std::string& str) {
    std::cout << "Testing with string: " << str << std::endl;
}

void manualTest() {
    // Directly calling the test function to simulate unit testing
    std::cout << "C++ Stdout: ";
    test("abc");
    std::cout << "C++ Stderr: " << std::endl; // Placeholder to match format
}

int main() {
    manualTest();
    return 0;
}