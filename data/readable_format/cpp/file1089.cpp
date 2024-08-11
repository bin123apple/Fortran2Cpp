#include <iostream>
#include <cmath>
#include <cassert>

constexpr double DAS2R = 4.848136811095359935899141e-6;
constexpr double DJ00 = 2451545.0;
constexpr double DJC = 36525.0;

double iau_OBL06(double DATE1, double DATE2) {
    double T = ((DATE1 - DJ00) + DATE2) / DJC;
    double obliquity = (84381.406 +
                        (-46.836769 +
                         (-0.0001831 +
                          (0.00200340 +
                           (-0.000000576 +
                            (-0.0000000434) * T) * T) * T) * T) * T) * DAS2R;
    return obliquity;
}

int main() {
    double date1 = 2451545.0; // Example date1
    double date2 = 0.0;       // Example date2
    double expected = 0.40909260060058289; // Adjusted expected result to match Fortran output
    double tolerance = 1e-12;

    double result = iau_OBL06(date1, date2);

    assert(std::fabs(result - expected) < tolerance && "C++ Test failed.");
    std::cout << "C++ Test passed." << std::endl;

    return 0;
}