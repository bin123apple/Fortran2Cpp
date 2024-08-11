#include <iostream>
#include <cmath>
#include <cassert>

float specific__anint_r4(float parm) {
    return std::nearbyint(parm);
}

int main() {
    std::cout << "C++ Tests:" << std::endl;

    assert(specific__anint_r4(2.5f) == 2.0f);
    std::cout << "Test 1 (2.5) passed." << std::endl;

    assert(specific__anint_r4(3.5f) == 4.0f);
    std::cout << "Test 2 (3.5) passed." << std::endl;

    assert(specific__anint_r4(-2.5f) == -2.0f);
    std::cout << "Test 3 (-2.5) passed." << std::endl;

    assert(specific__anint_r4(-3.5f) == -4.0f);
    std::cout << "Test 4 (-3.5) passed." << std::endl;

    assert(specific__anint_r4(2.4f) == 2.0f);
    std::cout << "Test 5 (2.4) passed." << std::endl;

    assert(specific__anint_r4(-2.4f) == -2.0f);
    std::cout << "Test 6 (-2.4) passed." << std::endl;

    return 0;
}