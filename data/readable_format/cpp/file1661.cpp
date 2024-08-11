// switch1.cpp
#include <iostream>
#include <cassert>
#include <cmath>

void switch1(float& sw, float& dsw, const float z, const float p1, const float ip1, const float zmemb1, const float zmemb2) {
    float delz, delzp1;

    if (z >= (zmemb2 + p1) || z <= (zmemb1 - p1)) {
        sw = 0.0;
        dsw = 0.0;
    } else {
        if (z > zmemb2) {
            delz = z - zmemb2;
            delzp1 = delz * ip1;
            sw = 1.0 + (2.0 * delzp1 - 3.0) * delzp1 * delzp1;
            dsw = -6.0 * (delzp1 - 1.0) * ip1 * delzp1;
        } else if (z < zmemb1) {
            delz = zmemb1 - z;
            delzp1 = delz * ip1;
            sw = 1.0 + (2.0 * delzp1 - 3.0) * delzp1 * delzp1;
            dsw = 6.0 * (delzp1 - 1.0) * ip1 * delzp1;
        } else {
            sw = 1.0;
            dsw = 0.0;
        }
    }
}

void test(const float z, const float p1, const float ip1, const float zmemb1, const float zmemb2, const float expectedSw, const float expectedDsw) {
    float sw, dsw;
    switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2);
    assert(std::abs(sw - expectedSw) < 0.001 && "sw does not match expected value");
    assert(std::abs(dsw - expectedDsw) < 0.001 && "dsw does not match expected value");
    std::cout << "Test passed for z=" << z << " with sw=" << sw << " and dsw=" << dsw << std::endl;
}

int main() {
    // Test cases
    test(1.5, 0.5, 2.0, 1.0, 2.0, 1.0, 0.0);
    test(0.5, 0.5, 2.0, 1.0, 2.0, 0.0, 0.0);
    test(2.5, 0.5, 2.0, 1.0, 2.0, 0.0, 0.0);
    test(1.5, 0.5, 2.0, 0.0, 3.0, 1.0, 0.0);

    return 0;
}