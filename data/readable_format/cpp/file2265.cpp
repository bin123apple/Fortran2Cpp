#include <iostream>
#include <array>

// Constants that mimic the Fortran module parameters
const int nAlts = 10;
const int nSpecies = 5;
const int nIonsAdvect = 3;
const int nSpeciesTotal = nSpecies + nIonsAdvect;

class ModVertical {
public:
    std::array<double, nAlts + 4> dAlt_F; // Adjusted for 0-based indexing

    ModVertical() {
        for (int i = -1; i <= nAlts + 2; ++i) {
            dAlt_F[i + 1] = static_cast<double>(i); // Adjust index for 0-based and initialize
        }
    }
};

int main() {
    ModVertical vertical;

    // Print a test value (adjust index for 0-based)
    std::cout << "C++ dAlt_F[0]: " << vertical.dAlt_F[0 + 1] << std::endl;

    return 0;
}