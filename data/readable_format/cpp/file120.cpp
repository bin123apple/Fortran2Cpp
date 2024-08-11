#include <cassert> // For assert()
#include <iostream>
#include <cctype> // For std::isdigit and std::isalpha

// Declaration of the ST_ALNM function for the sake of completeness in this example
void ST_ALNM(const char& chrstr, int& ityp, int& iret) {
    iret = 0; // Initialize iret to 0
    ityp = 0; // Initialize ityp to 0

    // Check if the character is a digit
    if (std::isdigit(static_cast<unsigned char>(chrstr))) {
        ityp = 1;
    }
    // Check if the character is a letter (either uppercase or lowercase)
    else if (std::isalpha(static_cast<unsigned char>(chrstr))) {
        ityp = 2;
    }
}

int main() {
    char testChar;
    int ityp, iret;

    // Test 1: Check a digit
    testChar = '5';
    ST_ALNM(testChar, ityp, iret);
    assert(ityp == 1);

    // Test 2: Check a lowercase letter
    testChar = 'a';
    ST_ALNM(testChar, ityp, iret);
    assert(ityp == 2);

    // Test 3: Check an uppercase letter
    testChar = 'Z';
    ST_ALNM(testChar, ityp, iret);
    assert(ityp == 2);

    // Test 4: Check a non-alphanumeric character
    testChar = '@';
    ST_ALNM(testChar, ityp, iret);
    assert(ityp == 0);

    std::cout << "All tests passed." << std::endl;

    return 0;
}