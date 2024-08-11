#include <iostream>
#include <cmath>
#include <cassert>

void iau_PAS(double AL, double AP, double BL, double BP, double &THETA) {
    double DL, X, Y;

    DL = BL - AL;
    Y = std::sin(DL) * std::cos(BP);
    X = std::sin(BP) * std::cos(AP) - std::cos(BP) * std::sin(AP) * std::cos(DL);

    if (X != 0.0 || Y != 0.0) {
        THETA = std::atan2(Y, X);
    } else {
        THETA = 0.0;
    }
}

// Test function
void test_iau_PAS() {
    double AL, AP, BL, BP, THETA;
    // Example test case
    AL = 0.0;
    AP = 0.0;
    BL = 1.0;
    BP = 1.0;
    double expectedTheta = std::atan2(std::sin(1.0) * std::cos(1.0), std::sin(1.0) * std::cos(0.0) - std::cos(1.0) * std::sin(0.0) * std::cos(1.0));
    
    iau_PAS(AL, AP, BL, BP, THETA);

    std::cout << "Calculated THETA: " << THETA << std::endl;
    std::cout << "Expected THETA: " << expectedTheta << std::endl;

    assert(std::fabs(THETA - expectedTheta) < 1e-10);
    std::cout << "Test passed!" << std::endl;
}

int main() {
    test_iau_PAS();
    return 0;
}