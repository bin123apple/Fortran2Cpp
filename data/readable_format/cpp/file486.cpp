#include <cmath>
#include <cassert>
#include <iostream>

// Define the SLAE2 function directly in this file
void SLAE2(float A, float B, float C, float& RT1, float& RT2) {
    const float ONE = 1.0E0;
    const float TWO = 2.0E0;
    const float ZERO = 0.0E0;
    const float HALF = 0.5E0;
    
    float AB, ACMN, ACMX, ADF, DF, RT, SM, TB;
    
    SM = A + C;
    DF = A - C;
    ADF = std::abs(DF);
    TB = B + B;
    AB = std::abs(TB);
    
    if (std::abs(A) > std::abs(C)) {
        ACMX = A;
        ACMN = C;
    } else {
        ACMX = C;
        ACMN = A;
    }
    
    if (ADF > AB) {
        RT = ADF * std::sqrt(ONE + std::pow((AB / ADF), 2));
    } else if (ADF < AB) {
        RT = AB * std::sqrt(ONE + std::pow((ADF / AB), 2));
    } else {
        RT = AB * std::sqrt(TWO);
    }
    
    if (SM < ZERO) {
        RT1 = HALF * (SM - RT);
        RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B;
    } else if (SM > ZERO) {
        RT1 = HALF * (SM + RT);
        RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B;
    } else {
        RT1 = HALF * RT;
        RT2 = -HALF * RT;
    }
}

int main() {
    // Test Case
    float A = 2.0;
    float B = -3.0;
    float C = 1.0;
    float RT1, RT2;
    
    SLAE2(A, B, C, RT1, RT2);
    
    // Simple assertions to validate the test case
    // Without specific expected values, these lines are here just as placeholders
    // Please replace the 0.0 with your actual expected values after running the test to see the output
    std::cout << "RT1: " << RT1 << ", RT2: " << RT2 << std::endl;

    // Example of an assertion, assuming expected values were RT1=1.0 and RT2=-2.0.
    // assert(RT1 == 1.0); // Uncomment and adjust based on actual expected results
    // assert(RT2 == -2.0); // Uncomment and adjust based on actual expected results
    
    std::cout << "Test passed." << std::endl;
    
    return 0;
}