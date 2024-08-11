#include <iostream>
#include <algorithm> // For std::max and std::min
#include <cassert>

// Define the Panel_Diagonal function directly in this file.
bool Panel_Diagonal(int Ilo, int Ihi, int Jlo, int Jhi, int& Dlo, int& Dhi) {
    int UR, LL;

    UR = Ihi - Jlo;
    LL = Ilo - Jhi;

    if (UR * LL > 0) {
        return false;
    } else {
        Dlo = std::max(Ilo, Jlo);
        Dhi = std::min(Ihi, Jhi);
        return true;
    }
}

// Define a function to run tests on Panel_Diagonal.
void TestPanelDiagonal(int Ilo, int Ihi, int Jlo, int Jhi, bool expected, int expectedDlo, int expectedDhi) {
    int Dlo, Dhi;
    bool result = Panel_Diagonal(Ilo, Ihi, Jlo, Jhi, Dlo, Dhi);
    
    assert(result == expected);
    if (result) {
        assert(Dlo == expectedDlo);
        assert(Dhi == expectedDhi);
        std::cout << "Test passed: Dlo = " << Dlo << ", Dhi = " << Dhi << std::endl;
    } else {
        std::cout << "Test passed: Function returned false as expected." << std::endl;
    }
}

// Test the functionality with a main function.
int main() {
    // Test Case 1
    TestPanelDiagonal(1, 5, 2, 6, true, 2, 5);

    // Test Case 2
    TestPanelDiagonal(3, 7, 1, 4, true, 3, 4);

    // Test Case 3
    TestPanelDiagonal(4, 8, 5, 9, true, 5, 8);

    return 0;
}