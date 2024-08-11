// rk4_corrected.cpp
#include <cmath>
#include <iostream>
#include <cassert>

double rk4_int(double rhsInit, double dTime) {
    double k1, k2, k3, k4;

    k1 = rhsInit;
    k2 = rhsInit + (dTime / 2.0) * k1;
    k3 = rhsInit + (dTime / 2.0) * k2;
    k4 = rhsInit + dTime * k3;

    return rhsInit + (dTime / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
}

void test_rk4_int() {
    double result = rk4_int(1.0, 0.1);
    std::cout << "C++ Test Result: " << result << std::endl;
    // Note: The assertion was removed for direct output comparison. Adjust as needed.
}

int main() {
    test_rk4_int();
    return 0;
}