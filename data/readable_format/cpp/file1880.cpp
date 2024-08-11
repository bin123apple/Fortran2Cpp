#include <iostream>
#include <string>

// Function to match the Fortran behavior
std::string getCaseString(int nn) {
    switch(nn) {
        case 1:
            return "case1";
        case 2:
            return "case2";
        default:
            return "";  // No output for cases not explicitly defined, aligning with Fortran
    }
}

// Test function
void testCases() {
    std::cout << getCaseString(1) << std::endl; // Expected to print "case1"
    std::cout << getCaseString(2) << std::endl; // Expected to print "case2"
    std::cout << getCaseString(3) << std::endl; // Expected not to print anything
}

int main() {
    testCases();
    return 0;
}