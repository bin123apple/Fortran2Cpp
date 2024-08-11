#include <vector>
#include <iostream>
#include <cassert>
#include <cmath> // For std::fabs

// Function declarations
void rpn2_cons_update_manifold(size_t meqn, size_t maux, int idir, int iface,
                               const std::vector<double>& q,
                               const std::vector<double>& auxvec_center,
                               const std::vector<double>& auxvec_edge,
                               std::vector<double>& flux);

void rpn2_cons_update_zero(size_t meqn, size_t maux, int idir, int iface,
                           const std::vector<double>& q,
                           const std::vector<double>& auxvec_center,
                           const std::vector<double>& auxvec_edge,
                           std::vector<double>& flux);

// Function implementations
void rpn2_cons_update_manifold(size_t meqn, size_t maux, int idir, int iface,
                               const std::vector<double>& q,
                               const std::vector<double>& auxvec_center,
                               const std::vector<double>& auxvec_edge,
                               std::vector<double>& flux) {
    double urot = auxvec_center[2 + iface]; // Note: Adjust index if necessary

    for (size_t m = 0; m < meqn; ++m) {
        flux[m] = urot * q[m];
    }
}

void rpn2_cons_update_zero(size_t meqn, size_t maux, int idir, int iface,
                           const std::vector<double>& q,
                           const std::vector<double>& auxvec_center,
                           const std::vector<double>& auxvec_edge,
                           std::vector<double>& flux) {
    for (size_t m = 0; m < meqn; ++m) {
        flux[m] = 0.0;
    }
}

// Test functions
void test_rpn2_cons_update_manifold() {
    std::vector<double> q = {1.0, 2.0, 3.0};
    std::vector<double> auxvec_center = {0.1, 0.2, 0.3, 0.4};
    std::vector<double> auxvec_edge = {0.5, 0.6, 0.7, 0.8};
    std::vector<double> flux(3, 0.0);
    size_t meqn = 3, maux = 4;
    int idir = 1, iface = 2;

    rpn2_cons_update_manifold(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux);

    for (size_t m = 0; m < meqn; ++m) {
        assert(std::fabs(flux[m] - (auxvec_center[2 + iface] * q[m])) < 1e-6);
    }
}

void test_rpn2_cons_update_zero() {
    std::vector<double> q = {1.0, 2.0, 3.0};
    std::vector<double> flux(3, -1.0); // Initialize with non-zero values
    size_t meqn = 3;

    rpn2_cons_update_zero(meqn, 0, 0, 0, q, {}, {}, flux);

    for (size_t m = 0; m < meqn; ++m) {
        assert(std::fabs(flux[m]) < 1e-6);
    }
}

int main() {
    // Run tests
    test_rpn2_cons_update_manifold();
    test_rpn2_cons_update_zero();

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}