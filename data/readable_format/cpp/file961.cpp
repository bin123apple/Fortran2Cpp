#include <iostream>
#include <cmath>
#include <string>

// Constants
const float PI = 3.14159265f;
const float SMAX = 100.0f;
const float SMIN = 1.0f;

// Example ODFNRM function definition
float ODFNRM(float D, float S) {
    float AMB, ONEMS;
    float result = 0.0f;

    if (S < SMIN) S = SMIN;
    if (S > SMAX) S = SMAX;

    if (D > 0.0f) {
        AMB = 1.0f + 2.0f * D;

        if (S > 1.0f) {
            ONEMS = 1.0f - S;
            result = 2.0f * PI * (std::pow(AMB, ONEMS) - 1.0f) / (D * ONEMS);
        } else {
            result = 2.0f * PI * std::log(AMB) / D;
        }
    } else {
        result = 4.0f * PI;
    }

    return result;
}

// Test function
void testODFNRM(float D, float S, const std::string& testName) {
    float result = ODFNRM(D, S);
    std::cout << testName << ": " << result << std::endl;
}

int main() {
    testODFNRM(0.5f, 20.0f, "Test 1 (D=0.5, S=20)");
    testODFNRM(0.5f, 0.5f, "Test 2 (D=0.5, S=0.5)"); // Edge case: S < SMIN
    testODFNRM(0.5f, 150.0f, "Test 3 (D=0.5, S=150)"); // Edge case: S > SMAX
    testODFNRM(0.0f, 10.0f, "Test 4 (D=0, S=10)"); // D=0, should return 4*PI
    testODFNRM(0.5f, 1.0f, "Test 5 (D=0.5, S=1)"); // S=1 specific case

    return 0;
}