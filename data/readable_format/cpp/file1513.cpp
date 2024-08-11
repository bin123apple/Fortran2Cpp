#include <array>
#include <cassert>
#include <iostream>

// Assuming the maximum dimensions based on the Fortran code
const int MXDIM = 50;

// Structure to mimic the Fortran common blocks
struct BPARM1 {
    std::array<double, MXDIM> XL;
    std::array<double, MXDIM> XU;
    int NDIM;
    int NWILD;
    std::array<int, MXDIM> IG;
    int NCALL;
} bparm1; // Global instance of BPARM1

struct BPARM2 {
    double ACC1;
    double ACC2;
    int ITMX1;
    int ITMX2;
} bparm2; // Global instance of BPARM2

// Translated subroutine
void bsparm(int MCALL, double AC1, double AC2, int IT1, int IT2) {
    bparm1.NCALL = MCALL;
    bparm2.ACC1 = AC1;
    bparm2.ACC2 = AC2;
    bparm2.ITMX1 = IT1;
    bparm2.ITMX2 = IT2;
}

// Test function
int main() {
    // Call the function with test values
    bsparm(100, 0.01, 0.02, 10, 20);
    
    // Assertions to check if the values are as expected
    assert(bparm1.NCALL == 100);
    assert(bparm2.ACC1 == 0.01);
    assert(bparm2.ACC2 == 0.02);
    assert(bparm2.ITMX1 == 10);
    assert(bparm2.ITMX2 == 20);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}