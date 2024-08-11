#include <vector>
#include <string>
#include <iostream>
#include <cassert>

class StringParser {
public:
    static const int MaxStringLength = 132;
    static const int MaxStringTokens = 100;
    
    std::vector<std::string> StringParts;
    
    StringParser() {} // Default constructor
    ~StringParser() {} // Destructor
};

// Simple test functions
void testConstants() {
    assert(StringParser::MaxStringLength == 132);
    assert(StringParser::MaxStringTokens == 100);
    std::cout << "Constants test passed." << std::endl;
}

void testVectorUsage() {
    StringParser parser;
    std::string testStr = "Test";
    
    for (int i = 0; i < StringParser::MaxStringTokens; ++i) {
        parser.StringParts.push_back(testStr + std::to_string(i));
    }

    assert(parser.StringParts.size() == StringParser::MaxStringTokens);
    for (int i = 0; i < StringParser::MaxStringTokens; ++i) {
        assert(parser.StringParts[i] == testStr + std::to_string(i));
    }
    std::cout << "Vector usage test passed." << std::endl;
}

int main() {
    testConstants();
    testVectorUsage();
    
    std::cout << "All tests passed." << std::endl;
    return 0;
}