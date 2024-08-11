// sla_DCS2C.cpp
#include <cmath>
#include <iostream>
#include <cassert>

void sla_DCS2C(double A, double B, double V[3]) {
    double COSB = std::cos(B);
    V[0] = std::cos(A) * COSB;
    V[1] = std::sin(A) * COSB;
    V[2] = std::sin(B);
}

int main() {
    double V[3];

    // Test case 1
    sla_DCS2C(0.0, 0.0, V);
    std::cout << "Test case 1: A = 0 B = 0" << std::endl;
    assert(std::abs(V[0] - 1.0) < 1e-6);
    assert(std::abs(V[1] - 0.0) < 1e-6);
    assert(std::abs(V[2] - 0.0) < 1e-6);

    // Test case 2
    sla_DCS2C(3.14159265358979323846 / 4.0, 3.14159265358979323846 / 4.0, V);
    std::cout << "Test case 2: A = " << 3.14159265358979323846 / 4.0 << " B = " << 3.14159265358979323846 / 4.0 << std::endl;
    assert(std::abs(V[0] - 0.5) < 1e-6);
    assert(std::abs(V[1] - 0.5) < 1e-6);
    assert(std::abs(V[2] - std::sqrt(2)/2) < 1e-6);
    
    std::cout << "All tests passed." << std::endl;
    return 0;
}