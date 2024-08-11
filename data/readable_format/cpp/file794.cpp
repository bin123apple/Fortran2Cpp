#include <iostream>
#include <string>
#include <cstdlib>

struct t {
    std::string x;
    t() : x(2, ' ') {}
};

void test(const std::string& testName, bool condition) {
    if (condition) {
        std::cout << testName << " Passed" << std::endl;
    } else {
        std::cout << testName << " Failed" << std::endl;
        std::abort();
    }
}

int main() {
    t a;
    std::string b(3, ' ');
    std::string line(10, ' ');

    // Test 1
    a.x[0] = 'a';
    line = a.x.substr(0,1) + "X" + std::string(8, ' ');
    test("Test 1", line == "aX        ");

    // Test 2
    b[0] = 'a'; b[1] = 'b';
    line = b.substr(0,2) + "Y" + std::string(7, ' ');
    test("Test 2", line == "abY       ");

    return 0;
}