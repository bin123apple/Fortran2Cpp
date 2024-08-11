#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>

void sla_DD2TF(int NDP, double DAYS, char& SIGN, std::array<int, 4>& IHMSF) {
    const double D2S = 86400.0;
    int NRS = 1, N;
    double RS, RM, RH, A, AH, AM, AS, AF;

    // Determine sign
    if (DAYS >= 0.0) {
        SIGN = '+';
    } else {
        SIGN = '-';
    }

    // Compute scale factors for decimal places
    for (N = 1; N <= NDP; ++N) {
        NRS *= 10;
    }
    RS = static_cast<double>(NRS);
    RM = RS * 60.0;
    RH = RM * 60.0;

    // Convert days to seconds and scale as requested
    A = std::round(RS * D2S * std::abs(DAYS));

    // Hours
    AH = std::floor(A / RH);
    A -= AH * RH;
    // Minutes
    AM = std::floor(A / RM);
    A -= AM * RM;
    // Seconds
    AS = std::floor(A / RS);
    AF = std::round(A - AS * RS);

    // Assign results to the output array
    IHMSF[0] = std::lround(AH);
    IHMSF[1] = std::lround(AM);
    IHMSF[2] = std::lround(AS);
    IHMSF[3] = std::lround(AF);
}

int main() {
    char SIGN;
    std::array<int, 4> IHMSF;

    sla_DD2TF(3, 1.34567, SIGN, IHMSF);

    std::cout << "Sign: " << SIGN << std::endl;
    std::cout << "IHMSF: ";
    for (auto val : IHMSF) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}