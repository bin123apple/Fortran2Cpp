#include <iostream>
#include <string>

// Declaration of 'great' function
void great(const std::string& arg1, const std::string& arg2) {
    std::cout << arg1 << " and " << arg2 << " are in 'great' subroutine." << std::endl;
}

// Test function for 'great'
void testGreat() {
    great("test1", "test2");
    great("data1", "data2");
    std::cout << "Test cases for 'great' executed. Please verify output manually." << std::endl;
}

int main() {
    testGreat();
    return 0;
}