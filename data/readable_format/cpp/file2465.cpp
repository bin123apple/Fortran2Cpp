// test_misc_values.cpp
#include <iostream>

// Let's define the real precision type directly in this file
using dp = double;

// Define the MiscValues struct in this file
struct MiscValues {
    dp mv_leafmol;
    dp mv_soilw;
    dp mv_soil2g;
    dp mv_respref;
};

// Global instance of MiscValues, since we're emulating the module behavior
MiscValues msv;

int main() {
    // Set values
    msv.mv_leafmol = 1.1;
    msv.mv_soilw = 2.2;
    msv.mv_soil2g = 3.3;
    msv.mv_respref = 4.4;

    // Print the values to verify
    std::cout << "mv_leafmol: " << msv.mv_leafmol << std::endl;
    std::cout << "mv_soilw: " << msv.mv_soilw << std::endl;
    std::cout << "mv_soil2g: " << msv.mv_soil2g << std::endl;
    std::cout << "mv_respref: " << msv.mv_respref << std::endl;

    return 0;
}