// combined.cpp
#include <iostream>
#include <cmath>

namespace mod_setprecision {
    constexpr int sprec = sizeof(float);
    constexpr int dprec = sizeof(double);
}

int main() {
    bool tests_passed = true;

    if (mod_setprecision::sprec != sizeof(float)) {
        std::cout << "Test for single precision failed." << std::endl;
        tests_passed = false;
    }

    if (mod_setprecision::dprec != sizeof(double)) {
        std::cout << "Test for double precision failed." << std::endl;
        tests_passed = false;
    }

    if (tests_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return !tests_passed;
}