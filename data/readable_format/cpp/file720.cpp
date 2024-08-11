#include <iostream>
#include <cmath>

// Function declaration and definition in the same file
float INHG_FROM_PA(float PA, float BADDATA) {
    if (PA != BADDATA) {
        return PA / 3386.39f;
    } else {
        return BADDATA;
    }
}

int main() {
    const float BADDATA = -999.0f;
    const float PA1 = 101325.0f;  // Standard atmospheric pressure in Pascals
    const float INHG1 = 29.9213f; // Expected result in inches of mercury

    // Test 1: Standard atmospheric pressure
    float result = INHG_FROM_PA(PA1, BADDATA);
    if (std::abs(result - INHG1) > 0.0001f) {
        std::cout << "Test 1 failed: Expected " << INHG1 << " but got " << result << std::endl;
    } else {
        std::cout << "Test 1 passed." << std::endl;
    }

    // Test 2: Bad data
    result = INHG_FROM_PA(BADDATA, BADDATA);
    if (result != BADDATA) {
        std::cout << "Test 2 failed: Expected " << BADDATA << " but got " << result << std::endl;
    } else {
        std::cout << "Test 2 passed." << std::endl;
    }

    return 0;
}