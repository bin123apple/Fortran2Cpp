#include <iostream>
#include <cmath> // For fabs (floating point absolute value)

// Constants definitions, translated from Fortran to C++
const int nn = 25;
const int ni = 144;
const int nj = 288;
const int nnaf = 23;
const int minc = 6;

const int nnp2 = nn + 2;
const int nnp1 = nn + 1;
const int nn1 = nn - 1;
const int nn2 = nn - 2;
const int nn3 = nn - 3;
const int nps2 = nnp1 / 2;
const int ns2 = nn1 / 2;
const int nnx2 = 2 * nn;
const int nja = nj / minc;
const int nrp = nja + 2;
const int ncp = nrp / 2;
const int ntf = (3 * nja) / 2 + 1;
const int njp1 = nj + 1;
const int nip1 = ni + 1;
const int lmax = nj / 3;
const int mmax = (lmax / minc) * minc;
const int nmaf = mmax + 1;
const int nmafa = mmax / minc + 1;
const int nlm = (nmaf * (nmaf + 1)) / 2;
const int nlaf = lmax + 1;
const int nlma = mmax * nlaf / minc - mmax * (mmax - minc) / (2 * minc) + nlaf - mmax;
const int lot = 2 * nlma;
const int nlafp1 = nlaf + 1;
const int nlmpa = nlma + nmafa;

// Simplified test function
void test(const std::string& name, int value, int expected) {
    if (value == expected) {
        std::cout << name << " Test Passed." << std::endl;
    } else {
        std::cout << name << " Test Failed. Expected: " << expected << ", Got: " << value << std::endl;
    }
}

int main() {
    // Running tests
    test("nnp2", nnp2, 27);
    test("nnp1", nnp1, 26);
    test("nn1", nn1, 24);
    // Add more tests as needed...
    
    return 0;
}