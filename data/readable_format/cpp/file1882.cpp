#include <cmath>
#include <iostream>

struct CM9 {
    double TOMEGA, PHIX;
    int ICHG, IWT;
} cm9;

struct CM29 {
    double GAM;
    int MDEX;
} cm29;

double GDAEFN1(double X) {
    double SGNP = std::copysign(1.0, cm9.PHIX);
    double XABX = std::abs(X * cm9.PHIX);

    double XEE = std::exp(X);

    double XCU = X * cm9.ICHG - SGNP * std::pow(XABX, cm29.GAM) / cm29.GAM;

    if (std::abs(XCU) > 300.0) XCU = std::copysign(300.0, XCU);

    if (cm9.IWT == 1) {
        double result = std::exp(XCU) / (1.0 + std::pow(cm9.TOMEGA * XEE, 2.0));
        if (cm29.MDEX < 0) result *= XEE;
        return result;
    } else {
        double XAR = XCU - cm9.TOMEGA * std::exp(-X);
        if (XAR < -50.0) {
            return 0.0;
        } else {
            return std::exp(XAR);
        }
    }
}

int main() {
    // Setting up the common block variables
    cm9.TOMEGA = 1.0;
    cm9.PHIX = 2.0;
    cm9.ICHG = 1;
    cm9.IWT = 1;
    cm29.GAM = 0.5;
    cm29.MDEX = -1;

    // Test
    double X = 1.0;
    double result = GDAEFN1(X);
    std::cout << "C++ Test 1: Result = " << result << std::endl;

    return 0;
}