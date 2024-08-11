#include <iostream>
#include <cmath>
#include <iomanip>

// Declaration of DCOORD function
void DCOORD(double A0, double B0, double AP, double BP, double& A1, double& B1, double& A2, double& B2);

int main() {
    double A0, B0, AP, BP, A1, B1, A2, B2;

    // Test Case 1
    A0 = 0.1;
    B0 = 0.2;
    AP = 0.3;
    BP = 0.4;
    A1 = 0.5;
    B1 = 0.6;
    DCOORD(A0, B0, AP, BP, A1, B1, A2, B2);
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Test Case 1 - A2: " << A2 << " B2: " << B2 << std::endl;

    // You can add more test cases here if needed

    return 0;
}

// Definition of DCOORD function
void DCOORD(double A0, double B0, double AP, double BP, double& A1, double& B1, double& A2, double& B2) {
    double SB0 = sin(B0);
    double CB0 = cos(B0);
    double SBP = sin(BP);
    double CBP = cos(BP);
    double SB1 = sin(B1);
    double CB1 = cos(B1);
    double SB2 = SBP*SB1 + CBP*CB1*cos(AP-A1);
    double CB2 = sqrt(1.0-SB2*SB2);
    B2 = atan2(SB2, CB2);
    double SAA = sin(AP-A1)*CB1/CB2;
    double CAA = (SB1-SB2*SBP)/(CB2*CBP);
    double CBB = SB0/CBP;
    double SBB = sin(AP-A0)*CB0;
    double SA2 = SAA*CBB - CAA*SBB;
    double CA2 = CAA*CBB + SAA*SBB;
    double TA2O2 = 0.0;
    if (CA2 <= 0.0) TA2O2 = (1.0-CA2)/SA2;
    if (CA2 > 0.0) TA2O2 = SA2/(1.0+CA2);
    A2 = 2.0*atan(TA2O2);
    if (A2 < 0.0) A2 = A2 + 2*M_PI;
}