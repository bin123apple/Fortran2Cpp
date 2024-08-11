#include <iostream>
#include <cmath>
#include <cassert>

// Declare global variables
double TIME, TPRINT, CPUTOT, ERRTOT, DETOT, ONE3, ONE6, ONE9, ONE12, TWOPI;
int MODEL, NDUMP, NSTEPS, NTIMER;

// Function prototype
void ZERO();

int main() {
    // Call the ZERO function to initialize variables
    ZERO();

    // Test the initialized variables
    assert(TIME == 0.0);
    assert(TPRINT == 0.0);
    assert(CPUTOT == 0.0);
    assert(ERRTOT == 0.0);
    assert(DETOT == 0.0);
    assert(MODEL == 0);
    assert(NDUMP == 0);
    assert(NSTEPS == 0);
    assert(NTIMER == 0);
    assert(ONE3 == 1.0 / 3.0);
    assert(ONE6 == 1.0 / 6.0);
    assert(ONE9 == 1.0 / 9.0);
    assert(ONE12 == 1.0 / 12.0);
    assert(TWOPI == 8.0 * std::atan(1.0));

    // If assertion passes, print success message
    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}

void ZERO() {
    // Initialize variables
    TIME = 0.0;
    TPRINT = 0.0;
    CPUTOT = 0.0;
    ERRTOT = 0.0;
    DETOT = 0.0;
    MODEL = 0;
    NDUMP = 0;
    NSTEPS = 0;
    NTIMER = 0;
    ONE3 = 1.0 / 3.0;
    ONE6 = 1.0 / 6.0;
    ONE9 = 1.0 / 9.0;
    ONE12 = 1.0 / 12.0;
    TWOPI = 8.0 * std::atan(1.0);
}