#include <iostream>
#include <cmath>
#include <cassert>

// Mock-up function - replace with the actual function
double gsw_gibbs_ice(int n0, int n1, double t, double p) {
    return t * p * 0.0001;
}

double gsw_specvol_ice(double t, double p) {
    return gsw_gibbs_ice(0, 1, t, p);
}

void test_gsw_specvol_ice() {
    double t, p, result;

    // Test 1
    t = 273.15; // Temperature in Kelvin
    p = 0.0;    // Pressure in dbar
    result = gsw_specvol_ice(t, p);
    std::cout << "Test 1: T=273.15 K, P=0.0 dbar, SpecVolIce=" << result << std::endl;
    assert(fabs(result - 0.0) < 1e-6);

    // Test 2
    t = 263.15;
    p = 10.0;
    result = gsw_specvol_ice(t, p);
    std::cout << "Test 2: T=263.15 K, P=10.0 dbar, SpecVolIce=" << result << std::endl;
    assert(fabs(result - 0.26315) < 1e-6);
}

int main() {
    test_gsw_specvol_ice();
    std::cout << "All tests passed." << std::endl;
    return 0;
}