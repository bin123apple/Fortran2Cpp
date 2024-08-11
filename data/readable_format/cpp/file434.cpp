#include <iostream>
#include <cctype> // For std::toupper
#include <cassert>

// LSAME function directly included
bool LSAME(char CA, char CB) {
    // Convert characters to upper case using std::toupper for comparison
    int INTA = std::toupper(static_cast<unsigned char>(CA));
    int INTB = std::toupper(static_cast<unsigned char>(CB));

    // Return comparison result
    return INTA == INTB;
}

// Test function for LSAME
void testLSAME(char a, char b, bool expected) {
    bool result = LSAME(a, b);
    assert(result == expected);
    std::cout << "Test passed for comparing '" << a << "' with '" << b << "' - Expected: " 
              << (expected ? "true" : "false") << ", Got: " << (result ? "true" : "false") << std::endl;
}

int main() {
    // Test Cases
    testLSAME('A', 'A', true);    // Identical uppercase letters
    testLSAME('b', 'b', true);    // Identical lowercase letters
    testLSAME('c', 'C', true);    // Uppercase and lowercase of the same letter
    testLSAME('D', 'E', false);   // Different letters
    testLSAME('1', '1', true);    // Non-letter characters
    testLSAME('z', 'Z', true);    // Lowercase and uppercase z
    testLSAME('?', '?', true);    // Non-alphabetic identical characters
    testLSAME('3', '8', false);   // Different numeric characters

    return 0;
}