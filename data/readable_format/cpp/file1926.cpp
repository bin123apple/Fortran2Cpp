#include <iostream>
#include <iomanip> // for std::setprecision
#include <cmath>

// Declaration of the iau_PV2S function
void iau_PV2S(const double PV[3][2], double& THETA, double& PHI, double& R, double& TD, double& PD, double& RD) {
    double X = PV[0][0];
    double Y = PV[1][0];
    double Z = PV[2][0];
    double XD = PV[0][1];
    double YD = PV[1][1];
    double ZD = PV[2][1];

    double RXY2 = X*X + Y*Y;
    double R2 = RXY2 + Z*Z;

    double RTRUE = sqrt(R2);
    double RW = RTRUE;

    if (RTRUE == 0.0) {
        X = XD;
        Y = YD;
        Z = ZD;
        RXY2 = X*X + Y*Y;
        R2 = RXY2 + Z*Z;
        RW = sqrt(R2);
    }

    double RXY = sqrt(RXY2);
    double XYP = X*XD + Y*YD;

    if (RXY2 != 0.0) {
        THETA = atan2(Y, X);
        PHI = atan2(Z, RXY);
        TD = (X*YD - Y*XD) / RXY2;
        PD = (ZD*RXY2 - Z*XYP) / (R2*RXY);
    } else {
        THETA = 0.0;
        PHI = 0.0;
        TD = 0.0;
        PD = 0.0;
    }

    R = RTRUE;

    if (RW != 0.0) {
        RD = (XYP + Z*ZD) / RW;
    } else {
        RD = 0.0;
    }
}

int main() {
    double PV[3][2] = { {1.0, 4.0}, {2.0, 5.0}, {3.0, 6.0} };
    double THETA, PHI, R, TD, PD, RD;

    // Call the function
    iau_PV2S(PV, THETA, PHI, R, TD, PD, RD);

    // Print results with precision
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "THETA: " << THETA << std::endl;
    std::cout << "PHI: " << PHI << std::endl;
    std::cout << "R: " << R << std::endl;
    std::cout << "TD: " << TD << std::endl;
    std::cout << "PD: " << PD << std::endl;
    std::cout << "RD: " << RD << std::endl;

    return 0;
}