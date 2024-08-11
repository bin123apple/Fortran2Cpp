#include <iostream>
#include <cctype> // for std::toupper

// Function declaration
bool OLSAME(char CA, char CB);

int main() {
    // Test cases
    struct TestCase {
        char CA;
        char CB;
        bool expected;
    };

    TestCase tests[] = {
        {'A', 'A', true},
        {'a', 'A', true},
        {'A', 'B', false},
        // Add more test cases as needed
    };

    bool allTestsPassed = true;

    for (const auto& test : tests) {
        bool result = OLSAME(test.CA, test.CB);
        if (result != test.expected) {
            std::cerr << "Test failed: OLSAME(" << test.CA << ", " << test.CB
                      << ") = " << std::boolalpha << result
                      << ", expected: " << test.expected << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}

// Function definition
bool OLSAME(char CA, char CB) {
    if (CA == CB) return true;
    
    int INTA = static_cast<int>(CA);
    int INTB = static_cast<int>(CB);
    int ZCODE = static_cast<int>('Z');
    
    if (ZCODE == 90 || ZCODE == 122) {
        if (INTA >= 97 && INTA <= 122) INTA -= 32;
        if (INTB >= 97 && INTB <= 122) INTB -= 32;
    } else if (ZCODE == 233 || ZCODE == 169) {
        if ((INTA >= 129 && INTA <= 137) || (INTA >= 145 && INTA <= 153) || (INTA >= 162 && INTA <= 169)) INTA += 64;
        if ((INTB >= 129 && INTB <= 137) || (INTB >= 145 && INTB <= 153) || (INTB >= 162 && INTB <= 169)) INTB += 64;
    } else if (ZCODE == 218 || ZCODE == 250) {
        if (INTA >= 225 && INTA <= 250) INTA -= 32;
        if (INTB >= 225 && INTB <= 250) INTB -= 32;
    }
    
    return INTA == INTB;
}