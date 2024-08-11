#include <iostream>
#include <vector>
#include <string>

class ByteType {
    char singleByte;
public:
    ByteType() : singleByte(0) {}
    ByteType(char c) : singleByte(c) {}
    char getByte() const { return singleByte; }
};

std::vector<ByteType> StringToBytes(const std::string &v) {
    std::vector<ByteType> bytes;
    for (char c : v) {
        bytes.push_back(ByteType(c));
    }
    return bytes;
}

std::string BytesToString(const std::vector<ByteType> &bytes) {
    std::string str;
    for (const ByteType &b : bytes) {
        str += b.getByte();
    }
    return str;
}

// Simple testing mechanism
void TestConversion(const std::string& testStr) {
    auto bytes = StringToBytes(testStr);
    std::string convertedStr = BytesToString(bytes);
    if (convertedStr == testStr) {
        std::cout << "Test Passed: " << testStr << " == " << convertedStr << std::endl;
    } else {
        std::cerr << "Test Failed: " << testStr << " != " << convertedStr << std::endl;
    }
}

int main() {
    // Test cases
    TestConversion("Hello, world!");
    TestConversion("Test string with multiple characters, numbers 1234567890, and symbols !@#$%^&*()");

    return 0;
}