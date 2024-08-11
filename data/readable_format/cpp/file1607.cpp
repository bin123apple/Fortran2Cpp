#include <iostream>
#include <sstream>
#include <string>

class D {
public:
    std::string f_d() {
        return "f_d()";
    }
};

// A simple test function to test f_d method of class D
void test_f_d() {
    D d;
    std::string result = d.f_d();
    std::string expected = "f_d()";

    if (result == expected) {
        std::cout << "Test passed: f_d()" << std::endl;
    } else {
        std::cerr << "Test failed: f_d() - Expected '" << expected << "', but got '" << result << "'" << std::endl;
    }
}

// Main function to run tests
int main() {
    test_f_d();
    return 0;
}