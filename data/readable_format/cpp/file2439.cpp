#include <iostream>
#include <string>

namespace hello_constants {
    const std::string hello_string = "Hello World!";
}

void testHelloString() {
    const std::string expected_string = "Hello World!";
    if (hello_constants::hello_string == expected_string) {
        std::cout << "Test passed: hello_string matches expected_string" << std::endl;
    } else {
        std::cout << "Test failed: hello_string does not match expected_string" << std::endl;
    }
}

int main() {
    testHelloString();
    return 0;
}