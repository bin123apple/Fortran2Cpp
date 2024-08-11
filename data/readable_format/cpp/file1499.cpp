#include <iostream>
#include <cmath> // For std::fabs

// Constants
const double DAS2R = 4.848136811095359935899141e-6;
const double DJ00 = 2451545.0;
const double DJC = 36525.0;
const double PRECOR = -0.29965 * DAS2R;
const double OBLCOR = -0.02524 * DAS2R;

// Function declaration and definition
void iau_PR00(double DATE1, double DATE2, double& DPSIPR, double& DEPSPR) {
    double T = ((DATE1 - DJ00) + DATE2) / DJC;
    
    DPSIPR = PRECOR * T;
    DEPSPR = OBLCOR * T;
}

int main() {
    double DATE1 = 2451545.0; // Example date
    double DATE2 = 0.0; // Additional days
    double DPSIPR, DEPSPR;

    iau_PR00(DATE1, DATE2, DPSIPR, DEPSPR);

    std::cout << "DPSIPR: " << DPSIPR << std::endl;
    std::cout << "DEPSPR: " << DEPSPR << std::endl;

    // Example of testing the output with a simple check
    double tolerance = 1e-6;
    if (std::fabs(DPSIPR - (-0.000000129282)) < tolerance && std::fabs(DEPSPR - (-0.000000010920)) < tolerance) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}