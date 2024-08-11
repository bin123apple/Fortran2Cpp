#include <iostream>
#include <string>

// Declaration and definition of PWRZGT in the same file
void PWRZGT(char KCHAR, char JCHAR[], int INDEX[], int NSIZE, int& IPOINT) {
    int KOUNT = 0;
    int IBOT = 0; // Adjusted to 0-based indexing
    int ITOP = NSIZE - 1;
    int I = ITOP;

    while (true) {
        I = (IBOT + ITOP) / 2;
        KOUNT++;

        if (KOUNT > 10) {
            IPOINT = -1;
            return;
        }

        if (JCHAR[I] < KCHAR) {
            IBOT = I + 1;
        } else if (JCHAR[I] > KCHAR) {
            ITOP = I - 1;
        } else {
            IPOINT = INDEX[I];
            return;
        }

        if (IBOT > ITOP) {
            IPOINT = -1;
            return;
        }
    }
}

// runTest function to help with testing PWRZGT
void runTest(char KCHAR, char JCHAR[], int INDEX[], int NSIZE, int expected, const std::string& testName) {
    int IPOINT = 0;
    PWRZGT(KCHAR, JCHAR, INDEX, NSIZE, IPOINT);
    if (IPOINT == expected) {
        std::cout << testName << " Passed" << std::endl;
    } else {
        std::cout << testName << " Failed: Expected " << expected << ", got " << IPOINT << std::endl;
    }
}

// main function to execute tests
int main() {
    char JCHAR[] = {'A', 'B', 'C', 'D', 'E'};
    int INDEX[] = {1, 2, 3, 4, 5};
    int NSIZE = sizeof(JCHAR) / sizeof(JCHAR[0]);

    // Test 1: Search for a character in the middle
    runTest('C', JCHAR, INDEX, NSIZE, 3, "Test 1");

    // Test 2: Search for a character not in the array
    runTest('Z', JCHAR, INDEX, NSIZE, -1, "Test 2");

    // Additional tests can be added here as needed...

    return 0;
}