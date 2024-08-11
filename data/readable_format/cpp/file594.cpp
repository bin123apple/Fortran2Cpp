#include <iostream>
#include <cmath>

// Definition of the switch1 function directly in the C++ file
void switch1(float& sw, float& dsw, float z, float p1, float ip1, float zmemb1, float zmemb2) {
    float delz, delzp1;

    if (z >= (zmemb2 + p1) || z <= (zmemb1 - p1)) {
        sw = 0.0f;
        dsw = 0.0f;
    } else {
        if (z > zmemb2) {
            delz = z - zmemb2;
            delzp1 = delz * ip1;
            sw = 1.0f + (2.0f * delzp1 - 3.0f) * std::pow(delzp1, 2);
            dsw = -6.0f * (delzp1 - 1.0f) * ip1 * delzp1;
        } else if (z < zmemb1) {
            delz = zmemb1 - z;
            delzp1 = delz * ip1;
            sw = 1.0f + (2.0f * delzp1 - 3.0f) * std::pow(delzp1, 2);
            dsw = 6.0f * (delzp1 - 1.0f) * ip1 * delzp1;
        } else {
            sw = 1.0f;
            dsw = 0.0f;
        }
    }
}

// Main function to test the switch1 function
int main() {
    float sw, dsw, z, p1, ip1, zmemb1, zmemb2;

    // Test case 1: z within the range
    z = 5.0f; p1 = 1.0f; ip1 = 1.0f; zmemb1 = 4.0f; zmemb2 = 6.0f;
    switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2);
    std::cout << "Test 1: sw=" << sw << " dsw=" << dsw << std::endl;

    // Test case 2: z outside the range, above zmemb2+p1
    z = 8.0f; p1 = 1.0f; ip1 = 1.0f; zmemb1 = 4.0f; zmemb2 = 6.0f;
    switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2);
    std::cout << "Test 2: sw=" << sw << " dsw=" << dsw << std::endl;

    // Test case 3: z outside the range, below zmemb1-p1
    z = 2.0f; p1 = 1.0f; ip1 = 1.0f; zmemb1 = 4.0f; zmemb2 = 6.0f;
    switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2);
    std::cout << "Test 3: sw=" << sw << " dsw=" << dsw << std::endl;

    // Additional tests can be added here with different values

    return 0;
}