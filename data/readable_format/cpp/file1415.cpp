#include <iostream>
#include <string>
#include <cstdlib> // For std::exit

// Modified function definition without 'constexpr'
std::string s_to_c(const std::string& string) {
    return string;
}

// Simple assertion function to avoid external dependencies
void assertEqual(const std::string& lhs, const std::string& rhs, int testNumber) {
    if (lhs != rhs) {
        std::cerr << "Test " << testNumber << " FAILED: " << lhs << " != " << rhs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::cout << "Test " << testNumber << " PASSED." << std::endl;
}

void assertLength(const std::string& str, size_t expectedLength, int testNumber) {
    if (str.length() != expectedLength) {
        std::cerr << "Test " << testNumber << " FAILED: Length " << str.length() << " != " << expectedLength << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::cout << "Test " << testNumber << " PASSED." << std::endl;
}

int main() {
    // Test 1: Check return value and length of s_to_c("ABCdef")
    assertEqual(s_to_c("ABCdef"), "ABCdef", 1);
    assertLength(s_to_c("ABCdef"), 6, 2);

    // Test 2: Assign s_to_c("ABCdef") to str and check
    std::string str = s_to_c("ABCdef");
    assertEqual(str, "ABCdef", 3);
    assertLength(str, 6, 4);

    // Test 3: Modify first 3 characters and check
    str.replace(0, 3, s_to_c("123"));
    assertEqual(str, "123def", 5);
    assertLength(str, 6, 6);

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}