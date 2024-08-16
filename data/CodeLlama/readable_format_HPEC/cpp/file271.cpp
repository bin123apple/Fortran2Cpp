#include <iostream>
#include <omp.h>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> a(100);
    std::string str;
    bool test_passed = true;

    #pragma omp parallel for
    for (int i = 0; i < 100; ++i) {
        str = std::to_string(i + 1); // Convert integer to string
        a[i] = str.substr(str.size() - 10, 10); // Right-pad with zeros and take last 10 characters
    }

    // Check if the 23rd element matches the expected value
    if (a[22] != "000000023") { // Arrays in C++ are 0-indexed
        test_passed = false;
    }

    if (test_passed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
