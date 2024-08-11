// testStringAllocation.cpp
#include <iostream>
#include <string>

int main() {
    int i = 10;
    std::string s; // Create an empty string
    s.resize(i, ' '); // Resize the string to length i, filling with spaces

    // Test: Check the length of the string
    if (s.length() == static_cast<size_t>(i)) {
        std::cout << "C++ Test passed." << std::endl;
    } else {
        std::cout << "C++ Test failed." << std::endl;
    }

    return 0;
}