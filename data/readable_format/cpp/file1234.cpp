#include <iostream>
#include <string>
#include <cassert>  // For assert()

std::string x(30, ' ');

std::string& foo(int i) {
    return x;
}

// A simple test function
void testFunctionality() {
    std::string& s = foo(30);
    s = "Test Successful";

    assert(x == "Test Successful");
    assert(s == x);

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testFunctionality();  // Run our test
    return 0;
}