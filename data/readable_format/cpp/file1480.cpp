#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cassert>

class ValoutMod {
public:
    void VALOUT(std::string& STRING, int& IBEFOR, const int WIDTH, const int VALUE) {
        std::ostringstream ss;
        ss << std::setw(WIDTH) << VALUE;
        
        if (IBEFOR > 0) {
            STRING += ss.str();
        } else {
            STRING = ss.str();
        }

        IBEFOR += WIDTH;
    }
};

void testVALOUT() {
    ValoutMod valout;
    std::string testString;
    int testIbefor, width, value;

    // Test 1
    testString = "";
    testIbefor = 0;
    width = 5;
    value = 123;
    valout.VALOUT(testString, testIbefor, width, value);
    assert(testString == "  123" && testIbefor == 5);
    std::cout << "Test 1 passed: " << testString << ", " << testIbefor << std::endl;
    
    // Test 2
    testString = "";
    testIbefor = 0;
    valout.VALOUT(testString, testIbefor, width, -45);
    assert(testString == "  -45" && testIbefor == 5);
    std::cout << "Test 2 passed: " << testString << ", " << testIbefor << std::endl;

    // More tests can be added here
}

int main() {
    try {
        testVALOUT();
        std::cout << "All tests passed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "A test failed: " << e.what() << std::endl;
    }
    return 0;
}