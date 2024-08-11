#include <iostream>
#include <array>
#include <string>

void testArrayContent(const std::array<std::string, 3>& a, const std::array<std::string, 3>& expected, const std::string& testName) {
    bool pass = true;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != expected[i]) {
            pass = false;
            break;
        }
    }
    std::cout << "Test " << testName << ": " << (pass ? "PASS" : "FAIL") << std::endl;
}

void testStringContent(const std::string& s, const std::string& expected, const std::string& testName) {
    bool pass = (s == expected);
    std::cout << "Test " << testName << ": " << (pass ? "PASS" : "FAIL") << std::endl;
}

int main() {
    // Original data
    std::array<std::string, 3> a = {"Takata ", "Tanaka ", "Hayashi"};
    std::array<std::string, 3> b = {"abc", "abc", "abc"};
    std::string c = "abcd";

    // Test cases
    testArrayContent(a, {"Takata ", "Tanaka ", "Hayashi"}, "Array a");
    testArrayContent(b, {"abc", "abc", "abc"}, "Array b");
    testStringContent(c, "abcd", "String c");

    // Any other logic or tests you wish to perform
    return 0;
}