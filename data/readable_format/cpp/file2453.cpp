#include <iostream>
#include <string>
#include <omp.h>
#include <cassert>

void foo(const std::string& x, std::string& result) {
    result = std::string(80, ' ');

    #pragma omp master
    {
        result = x;
        result.erase(0, result.find_first_not_of(' ')); // Adjust left
    }
}

int main() {
    std::string input = "   example";
    std::string result;
    std::string expected = "example";

    foo(input, result);

    // Check if result matches expected
    assert(result.find_first_not_of(expected) == std::string::npos && "Test failed.");

    std::cout << "C++ Test passed." << std::endl;
    return 0;
}