#include <iostream>
#include <string>
#include <cassert>

// Define the class 't' with a member function pointer 'ptr'.
class t {
public:
    std::string& (*ptr)(std::string&);
};

// Define the function 'abc' to be pointed to by 't::ptr'.
std::string& abc(std::string& arg) {
    return arg;
}

// Main function containing tests
int main() {
    t x;
    std::string str1 = "abcde";
    std::string str2 = "fghij";

    // Assigning the function pointer
    x.ptr = abc;

    // Test 1: Check the function pointer invocation with the first string
    std::string& result1 = x.ptr(str1);
    assert(result1 == "abcde"); // Using assert for a simple test
    std::cout << "Test 1 Passed: " << result1 << std::endl;

    // Test 2: Check the function pointer invocation with the modified string
    std::string& result2 = x.ptr(str2);
    assert(result2 == "fghij"); // Using assert for a simple test
    std::cout << "Test 2 Passed: " << result2 << std::endl;

    return 0;
}