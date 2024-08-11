#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

class VaryingString {
public:
    std::vector<char> chars;

    // Assignment from a C-style string
    VaryingString& operator=(const char* expr) {
        chars.assign(expr, expr + std::strlen(expr));
        return *this;
    }
};

// Function to check if two ranges of characters are not equal
bool notEqual(const std::vector<char>& vec, const char* str, size_t len) {
    return !std::equal(vec.begin(), vec.begin() + len, str);
}

int main() {
    // Simulating the equivalence of char_arb and char_elm
    // by using a single character array and manipulating pointers.
    char char_storage[10]; // Storage for both char_arb and char_elm
    char* char_arb[2] = {char_storage, char_storage + 5};
    char* char_elm = char_storage;

    // Copying strings into the shared storage
    std::strcpy(char_arb[0], "Hello");
    std::strcpy(char_arb[1], "World");

    // Creating VaryingString instances and assigning values
    VaryingString str_ara[2];
    str_ara[0] = char_arb[0];
    str_ara[1] = char_arb[1];

    // Performing the checks as in the original Fortran program
    if (notEqual(str_ara[0].chars, char_elm, 5)) return 1;
    if (notEqual(str_ara[1].chars, char_elm + 5, 5)) return 2;

    return 0;
}