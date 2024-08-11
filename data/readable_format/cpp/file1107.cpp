#include <cassert>
#include <iostream>
#include <string>
#include <cctype>

// First version of LSAME
bool LSAME1(const std::string& CA, char CB) {
    const int ICIRFX = 62;
    bool result = (CA[0] == CB) && (CA[0] != static_cast<char>(ICIRFX));
    if (result) return true;
    
    int IVAL = static_cast<int>(CA[1]);
    if (IVAL >= static_cast<int>('A') && IVAL <= static_cast<int>('Z')) {
        result = (CA[0] == static_cast<char>(ICIRFX)) && (CA[1] == CB);
    }
    return result;
}

// Second version of LSAME
bool LSAME2(char CA, char CB) {
    const int IOFF = 32;
    bool result = (CA == CB);
    if (result) return true;
    
    int ISHIFT = static_cast<int>(CA) - IOFF;
    if (ISHIFT >= static_cast<int>('A') && ISHIFT <= static_cast<int>('Z')) {
        result = (ISHIFT == static_cast<int>(CB));
    }
    return result;
}

// Third version of LSAME
bool LSAME3(char CA, char CB) {
    const int IOFF = 64;
    bool result = (CA == CB);
    if (result) return true;
    
    int ISHIFT = static_cast<int>(CA) + IOFF;
    if ((ISHIFT >= static_cast<int>('A') && ISHIFT <= static_cast<int>('I')) ||
        (ISHIFT >= static_cast<int>('J') && ISHIFT <= static_cast<int>('R')) ||
        (ISHIFT >= static_cast<int>('S') && ISHIFT <= static_cast<int>('Z'))) {
        result = (ISHIFT == static_cast<int>(CB));
    }
    return result;
}

int main() {
    // Tests for LSAME1
    assert(LSAME1("AB", 'A') == true);
    assert(LSAME1("AB", 'B') == false);

    // Tests for LSAME2
    assert(LSAME2('A', 'A') == true);
    assert(LSAME2('A', 'a') == false); // Assuming case-sensitivity

    // Tests for LSAME3
    assert(LSAME3('A', 'A') == true);
    assert(LSAME3('A', 'a') == false); // Depending on the offset logic, this may vary

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}