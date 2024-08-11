#include <iostream>
#include <cassert>
#include <cmath>

void sla_CAF2R(int IDEG, int IAMIN, double ASEC, double& RAD, int& J) {
    const double AS2R = 0.484813681109535994E-5;

    J = 0;

    if (ASEC < 0.0 || ASEC >= 60.0) J = 3;
    if (IAMIN < 0 || IAMIN > 59) J = 2;
    if (IDEG < 0 || IDEG > 359) J = 1;

    RAD = AS2R * (60.0 * (60.0 * static_cast<double>(IDEG) + static_cast<double>(IAMIN)) + ASEC);
}

int main() {
    double RAD;
    int J;

    // Test 1
    sla_CAF2R(10, 20, 30.0, RAD, J);
    std::cout << "Test 1: RAD = " << RAD << " J = " << J << std::endl;

    // Test 2
    sla_CAF2R(10, 20, 60.0, RAD, J);
    std::cout << "Test 2: RAD = " << RAD << " J = " << J << std::endl;

    // Test 3
    sla_CAF2R(10, 60, 30.0, RAD, J);
    std::cout << "Test 3: RAD = " << RAD << " J = " << J << std::endl;

    // Test 4
    sla_CAF2R(360, 20, 30.0, RAD, J);
    std::cout << "Test 4: RAD = " << RAD << " J = " << J << std::endl;

    // Test 5
    sla_CAF2R(0, 0, 0.0, RAD, J);
    std::cout << "Test 5: RAD = " << RAD << " J = " << J << std::endl;

    return 0;
}