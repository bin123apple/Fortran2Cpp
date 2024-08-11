#include <iostream>
#include <vector>
#include <cassert>

// Struct to hold shared variables
struct ComRp {
    double ubar, vbar;
} comrp; // Global instance

// Function prototypes
void rpn2cons_update(int meqn, int maux, int idir, int iface,
                     std::vector<double>& q,
                     const std::vector<double>& auxvec_center,
                     const std::vector<double>& auxvec_edge,
                     std::vector<double>& flux);

void rpn2_cons_update_zero(int meqn, int maux, int idir, int iface,
                           const std::vector<double>& q,
                           const std::vector<double>& auxvec_center,
                           const std::vector<double>& auxvec_edge,
                           std::vector<double>& flux);

// Function implementations
void rpn2cons_update(int meqn, int maux, int idir, int iface,
                     std::vector<double>& q,
                     const std::vector<double>& auxvec_center,
                     const std::vector<double>& auxvec_edge,
                     std::vector<double>& flux) {
    double urot = (idir == 0) ? comrp.ubar : comrp.vbar;
    for (size_t m = 0; m < meqn; ++m) {
        flux[m] = urot * q[m];
    }
}

void rpn2_cons_update_zero(int meqn, int maux, int idir, int iface,
                           const std::vector<double>& q,
                           const std::vector<double>& auxvec_center,
                           const std::vector<double>& auxvec_edge,
                           std::vector<double>& flux) {
    for (size_t m = 0; m < meqn; ++m) {
        flux[m] = 0.0;
    }
}

// Unit test code
void test_rpn2cons_update() {
    int meqn = 5;
    int maux = 3;
    int idir = 0;
    int iface = 0;
    std::vector<double> q = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> auxvec_center(maux, 0.0);
    std::vector<double> auxvec_edge(maux, 0.0);
    std::vector<double> flux(meqn);

    comrp.ubar = 2.0; // Set ubar
    comrp.vbar = 3.0; // Set vbar but will not be used in this test

    rpn2cons_update(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux);
    std::cout << "Testing rpn2cons_update with idir = 0..." << std::endl;
    for (size_t i = 0; i < meqn; ++i) {
        std::cout << "flux[" << i << "] = " << flux[i] << std::endl;
        assert(flux[i] == q[i] * comrp.ubar); // Verify the operation was correct
    }
}

void test_rpn2_cons_update_zero() {
    int meqn = 5;
    std::vector<double> q(meqn, 1.0);
    std::vector<double> auxvec_center; // Not used in this test
    std::vector<double> auxvec_edge; // Not used in this test
    std::vector<double> flux(meqn);

    rpn2_cons_update_zero(meqn, 0, 0, 0, q, auxvec_center, auxvec_edge, flux);
    std::cout << "Testing rpn2_cons_update_zero..." << std::endl;
    for (size_t i = 0; i < meqn; ++i) {
        std::cout << "flux[" << i << "] = " << flux[i] << std::endl;
        assert(flux[i] == 0.0); // Verify that the flux vector has been zeroed out
    }
}

int main() {
    test_rpn2cons_update();
    test_rpn2_cons_update_zero();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}