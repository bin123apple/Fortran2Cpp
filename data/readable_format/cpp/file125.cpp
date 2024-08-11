#include <iostream>

const int MAXWORDS = 4095;
const int MAXRAYS = 3000;
const int MAXGATES = 1500;
const int MAXCOEFFS = 13;

const int rmax = 90;
const int thetamax = 90;
const int zmax = 20;
const int nx = 241;
const int ny = 241;
const int nz = 20;

bool testConstants() {
    if (MAXWORDS != 4095) return false;
    if (MAXRAYS != 3000) return false;
    if (MAXGATES != 1500) return false;
    if (MAXCOEFFS != 13) return false;
    if (rmax != 90) return false;
    if (thetamax != 90) return false;
    if (zmax != 20) return false;
    if (nx != 241) return false;
    if (ny != 241) return false;
    if (nz != 20) return false;
    return true;
}

int main() {
    if (testConstants()) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cout << "One or more tests failed." << std::endl;
    }
    return 0;
}