#include <iostream>
#include <cstring>
#include <cassert>

// Function declaration and definition
int lenocc(const char* c) {
    int length = std::strlen(c); // Get the length of the string
    for (int i = length - 1; i >= 0; --i) {
        if (c[i] != ' ') { // Check if the current character is not a space
            return i + 1; // Return the position (length) of the last non-space character
        }
    }
    return 0; // If only spaces or empty, return 0
}

// Test function
void test_lenocc() {
    assert(lenocc("hello world  ") == 11);
    assert(lenocc("   ") == 0);
    assert(lenocc("noSpaces") == 8);

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    test_lenocc();
    return 0;
}