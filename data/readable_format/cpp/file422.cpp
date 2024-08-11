#include <iostream>
#include <cmath> // For std::fabs

void MDPIN2(float& TST1, float& TST2, float& TST3) {
    TST1 = 1.0f;
    TST2 = TST1 + 1.0e-10f;
    TST3 = TST2 + 1.0e-10f;
}

bool floatEquals(float a, float b, float epsilon = 1.0e-10f) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    float TST1, TST2, TST3;
    MDPIN2(TST1, TST2, TST3);

    if (floatEquals(TST1, 1.0f) && floatEquals(TST2, TST1 + 1.0e-10f) && floatEquals(TST3, TST2 + 1.0e-10f)) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}