#include <iostream>
#include <cmath>
#include <iomanip> // For std::setprecision

void DLAE2(const double& A, const double& B, const double& C, double& RT1, double& RT2) {
    const double ONE = 1.0;
    const double TWO = 2.0;
    const double ZERO = 0.0;
    const double HALF = 0.5;
    
    double SM, DF, ADF, TB, AB, ACMN, ACMX, RT;
    
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
    double A, B, C, RT1, RT2;

    // Test case 1
    A = 4.0;
    B = 2.0;
    C = 1.0;
    DLAE2(A, B, C, RT1, RT2);
    std::cout << "Test Case 1: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << "RT1=" << std::setprecision(10) << RT1 << " RT2=" << RT2 << std::endl;

    // Add more test cases as needed

    return 0;
}