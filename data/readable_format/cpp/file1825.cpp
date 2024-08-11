#include <iostream>
#include <cassert>

// Define dummy rule constants
const int ppm_param_bem_quadrule_center = 1;
const int ppm_param_bem_quadrule_nodes = 2;
const int ppm_param_bem_quadrule_edges = 3;
const int ppm_param_bem_quadrule_cne = 4;
const int ppm_param_bem_quadrule_stroud = 5;
const int ppm_param_bem_quadrule_hammer7 = 6;
const int ppm_param_bem_quadrule_hammer3 = 7;
const int ppm_param_bem_quadrule_hammer4 = 8;
const int ppm_param_bem_quadrule_hammer12 = 9;

// Define error codes
const int ppm_error_success = 0;
const int ppm_error_error = -1;

// Function prototype
void ppm_bem_quadrule_npoints(int rule, int& nqp, int& info);

// Main function for testing
int main() {
    int nqp, info;

    // Test known rule
    ppm_bem_quadrule_npoints(ppm_param_bem_quadrule_center, nqp, info);
    std::cout << "Rule: " << ppm_param_bem_quadrule_center << " -> NQP: " << nqp << ", Info: " << info << std::endl;
    assert(info == ppm_error_success);

    // Test unknown rule
    ppm_bem_quadrule_npoints(-1, nqp, info);
    std::cout << "Rule: " << -1 << " -> NQP: " << nqp << ", Info: " << info << std::endl;
    assert(info == ppm_error_error);

    std::cout << "All tests passed." << std::endl;
    return 0;
}

// Function definition
void ppm_bem_quadrule_npoints(int rule, int& nqp, int& info) {
    // Assume success initially
    info = ppm_error_success;
    
    switch (rule) {
        case ppm_param_bem_quadrule_center:
            nqp = 1;
            break;
        case ppm_param_bem_quadrule_nodes:
        case ppm_param_bem_quadrule_edges:
        case ppm_param_bem_quadrule_hammer3:
            nqp = 3;
            break;
        case ppm_param_bem_quadrule_cne:
        case ppm_param_bem_quadrule_stroud:
        case ppm_param_bem_quadrule_hammer7:
            nqp = 7;
            break;
        case ppm_param_bem_quadrule_hammer4:
            nqp = 4;
            break;
        case ppm_param_bem_quadrule_hammer12:
            nqp = 12;
            break;
        default:
            nqp = 0;
            info = ppm_error_error; // Unknown rule
            std::cout << "Error: Unknown quadrature rule." << std::endl;
            break;
    }
}