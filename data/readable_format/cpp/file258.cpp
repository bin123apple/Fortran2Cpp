// Compile with: g++ -o cpp_test cpp_code.cpp
// Run with: ./cpp_test

#include <iostream>
#include <cmath>
#include <cassert>

// Example coefficients and constants for demonstration
const double gsw_sso = 35.0;
const double c0 = 0.0, c1 = 1.0, c2 = 2.0, c3 = 3.0, c4 = 4.0;
const double c5 = 5.0, c6 = 6.0, c7 = 7.0, c8 = 8.0, c9 = 9.0;
const double c10 = 10.0, c11 = 11.0, c12 = 12.0, c13 = 13.0;
const double c14 = 14.0, c15 = 15.0, c16 = 16.0, c17 = 17.0;
const double c18 = 18.0, c19 = 19.0, c20 = 20.0, c21 = 21.0;
const double c22 = 22.0;
const double a = 1.0, b = 2.0;

double gsw_ct_freezing_poly(double sa, double p, double saturation_fraction) {
    double sa_r = sa * 1e-2;
    double x = sqrt(sa_r);
    double p_r = p * 1e-4;

    double result = c0 + sa_r*(c1 + x*(c2 + x*(c3 + x*(c4 + x*(c5 + c6*x))))) +
        p_r*(c7 + p_r*(c8 + c9*p_r)) + sa_r*p_r*(c10 + p_r*(c12 + p_r*(c15 + c21*sa_r)) +
        sa_r*(c13 + c17*p_r + c19*sa_r) + 
        x*(c11 + p_r*(c14 + c18*p_r) + sa_r*(c16 + c20*p_r + c22*sa_r)));

    result -= saturation_fraction * (1e-3) * (2.4 - a*sa) * (1.0 + b*(1.0 - sa/gsw_sso));

    return result;
}

int main() {
    double result = gsw_ct_freezing_poly(35.0, 100.0, 0.5);

    std::cout << "Result: " << result << std::endl;

    return 0;
}