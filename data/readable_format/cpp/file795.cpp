#include <iostream>
#include <string>

// Function definition
void TDLBLP(char AXIS, const std::string& VLBL, std::string& PLBL) {
    PLBL = VLBL;
}

// Basic test function
void testTDLBLP() {
    std::string testLabel = "Test Label";
    std::string result;
    
    // Test case 1: AXIS = 'U'
    TDLBLP('U', testLabel, result);
    if (result == "Test Label") {
        std::cout << "Test 1 Passed - AXIS = 'U'" << std::endl;
    } else {
        std::cout << "Test 1 Failed - AXIS = 'U'" << std::endl;
    }
    
    // Test case 2: AXIS = 'X' (Not U, V, or W)
    std::string anotherLabel = "Another Label";
    TDLBLP('X', anotherLabel, result);
    if (result == "Another Label") {
        std::cout << "Test 2 Passed - AXIS = 'X'" << std::endl;
    } else {
        std::cout << "Test 2 Failed - AXIS = 'X'" << std::endl;
    }
}

int main() {
    testTDLBLP();
    return 0;
}