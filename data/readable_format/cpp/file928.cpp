#include <iostream>
#include <cmath> // For fabs()

void zmlt(double ar, double ai, double br, double bi, double& cr, double& ci) {
    double ca = ar * br - ai * bi;
    double cb = ar * bi + ai * br;
    cr = ca;
    ci = cb;
}

bool test(double ar, double ai, double br, double bi, double expected_cr, double expected_ci) {
    double cr, ci;
    zmlt(ar, ai, br, bi, cr, ci);
    if(std::fabs(cr - expected_cr) < 1e-9 && std::fabs(ci - expected_ci) < 1e-9) {
        std::cout << "Test passed." << std::endl;
        return true;
    } else {
        std::cout << "Test failed." << std::endl;
        return false;
    }
}

int main() {
    bool result = true;
    result &= test(1.0, 2.0, 3.0, 4.0, -5.0, 10.0);
    result &= test(-1.0, -2.0, -3.0, -4.0, -5.0, 10.0);
    result &= test(-1.0, 2.0, 3.0, -4.0, 5.0, -10.0);
    result &= test(0.0, 0.0, 3.0, 4.0, 0.0, 0.0);

    if(result) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
    
    return 0;
}