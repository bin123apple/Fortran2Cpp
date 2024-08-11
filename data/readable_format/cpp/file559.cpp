// File: xxx_test.cpp
#include <iostream>
#include <array>
#include <functional> // For std::function

void XXX(int IL, int IU, int& ivvv) {
    std::array<int, 14> NXX = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14};
    ivvv = 0;
    int iaii = 0;
    bool qop = false;

    for (int ia = IL; ia <= IU; ++ia) {
        int ja = NXX[ia - 1]; // Adjust for 0-based indexing
        if (!qop && ja > 0) {
            iaii = ia;
            qop = true;
        }

        if (qop) {
            ivvv = ia - iaii + 1;
        }
    }
}

void testXXX(int IL, int IU, int expectedIvvv) {
    int ivvv;
    XXX(IL, IU, ivvv);

    if (ivvv != expectedIvvv) {
        std::cout << "Test failed: Expected ivvv = " << expectedIvvv << ", got " << ivvv << std::endl;
    } else {
        std::cout << "Test passed." << std::endl;
    }
}

int main() {
    testXXX(1, 3, 2); // Test with expected output to match the Fortran test case
    return 0;
}