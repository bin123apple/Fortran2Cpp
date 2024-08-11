// E_kinetic.cpp
#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <cmath>
#include <cassert>

#define _REAL_ double

void E_kinetic(_REAL_ &KE, int natom, const std::vector<_REAL_> &mass, 
               const std::vector<_REAL_> &v, const std::vector<_REAL_> &oldv) {
    KE = 0.0;
    int i1 = 0;
    std::array<_REAL_, 3> tmpvec;

    for (int i = 0; i < natom; ++i) {
        for (int j = 0; j < 3; ++j) {
            tmpvec[j] = v[i1 + j] + oldv[i1 + j];
        }

        _REAL_ dot_product = std::inner_product(tmpvec.begin(), tmpvec.end(), tmpvec.begin(), 0.0);
        KE += mass[i] * dot_product;
        i1 += 3;
    }

    KE *= 0.5 * 0.25;
}

int main() {
    // Test Case 1
    int natom = 2;
    std::vector<_REAL_> mass = {1.0, 2.0};
    std::vector<_REAL_> v = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<_REAL_> oldv = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0};
    _REAL_ KE;

    E_kinetic(KE, natom, mass, v, oldv);
    std::cout << "Test Case 1: KE = " << KE << std::endl;
    // The assertion now checks for the correct value produced by both the Fortran and C++ codes
    assert(std::fabs(KE - 47.25) < 1e-9);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}