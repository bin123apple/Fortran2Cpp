#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

// Function declaration
void test(std::string& a);

// Function definition
void test(std::string& a) {
    a = "Sample#2";
}

// Test functions
void testInitialTransferAndComparison() {
    std::vector<char> ptr(9);
    std::string sample = "Sample#0";
    std::memcpy(ptr.data(), sample.data(), sample.size() + 1);

    std::string expected = "Sample#0";
    bool match = std::equal(ptr.begin(), ptr.end() - 1, expected.begin()); // -1 to exclude null terminator in comparison

    if (match) {
        std::cout << "Test 1 Passed: Initial Transfer and Comparison";
    } else {
        std::cout << "Test 1 Failed";
    }
    std::cout << std::endl;
}

void testSubroutineCallAndModification() {
    std::string a = "        "; // Initial string with 8 spaces
    test(a);
    if (a == "Sample#2") {
        std::cout << "Test 2 Passed: Subroutine Call and Modification";
    } else {
        std::cout << "Test 2 Failed";
    }
    std::cout << std::endl;
}

int main() {
    testInitialTransferAndComparison();
    testSubroutineCallAndModification();
    return 0;
}