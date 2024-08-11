#include <iostream>
#include <string>

class Para {
public:
    static std::string bobo(int n) {
        std::string baseString = "1234567890";
        if (n > static_cast<int>(baseString.size())) {
            return baseString;
        } else {
            return baseString.substr(0, n);
        }
    }
};

void testBobo(int n, const std::string& expected) {
    std::string result = Para::bobo(n);
    if (result == expected) {
        std::cout << "Test Passed for n = " << n << ": " << result << std::endl;
    } else {
        std::cout << "Test Failed for n = " << n << ". Expected: " << expected << ", Got: " << result << std::endl;
    }
}

int main() {
    testBobo(5, "12345");
    testBobo(10, "1234567890");
    testBobo(3, "123");
    testBobo(0, "");           // Additional test for empty string
    testBobo(15, "1234567890"); // Test for n larger than the base string

    return 0;
}