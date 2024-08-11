#include <iostream>
#include <string>

// Defining constants
constexpr int nn = 25;
constexpr int ni = 48;
constexpr int nj = 96;
constexpr int nnaf = 23;
constexpr int minc = 4;

constexpr int nnp2 = nn + 2;
constexpr int nnp1 = nn + 1;
constexpr int nn1 = nn - 1;
constexpr int nn2 = nn - 2;
constexpr int nn3 = nn - 3;
constexpr int nps2 = nnp1 / 2;
constexpr int ns2 = nn1 / 2;
constexpr int nnx2 = 2 * nn;
constexpr int nja = nj / minc;
constexpr int nrp = nja + 2;
constexpr int ncp = nrp / 2;
constexpr int ntf = 3 * nja / 2 + 1;
constexpr int njp1 = nj + 1;
constexpr int nip1 = ni + 1;
constexpr int lmax = nj / 3;
constexpr int mmax = (lmax / minc) * minc;
constexpr int nmaf = mmax + 1;
constexpr int nmafa = mmax / minc + 1;
constexpr int nlm = (nmaf * (nmaf + 1)) / 2;
constexpr int nlaf = lmax + 1;
constexpr int nlma = mmax * nlaf / minc - mmax * (mmax - minc) / (2 * minc) + nlaf - mmax;
constexpr int lot = 2 * nlma;
constexpr int nlafp1 = nlaf + 1;
constexpr int nlmpa = nlma + nmafa;

void test_value(const std::string& name, int value, int expected) {
    if (value == expected) {
        std::cout << name << " test passed." << std::endl;
    } else {
        std::cout << name << " test failed. Expected: " << expected << " Got: " << value << std::endl;
    }
}

int main() {
    // Test cases
    test_value("nnp2", nnp2, 27);
    test_value("njp1", njp1, 97);
    // Add additional tests as needed...
    // Example for an additional test
    test_value("ni", ni, 48);

    return 0;
}