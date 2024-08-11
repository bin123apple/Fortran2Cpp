#include <iostream>
using namespace std;

// Function prototype (declaration)
void iau_PR00(double DATE1, double DATE2, double& DPSIPR, double& DEPSPR);

// Test function prototype
void test_iau_PR00();

int main() {
    test_iau_PR00();
    return 0;
}

// Definition of the iau_PR00 function
void iau_PR00(double DATE1, double DATE2, double& DPSIPR, double& DEPSPR) {
    const double DAS2R = 4.848136811095359935899141e-6;
    const double DJ0 = 2451545.0;
    const double DJC = 36525.0;
    
    const double PRECOR = -0.29965 * DAS2R;
    const double OBLCOR = -0.02524 * DAS2R;
    
    double T = ((DATE1 - DJ0) + DATE2) / DJC;
    
    DPSIPR = PRECOR * T;
    DEPSPR = OBLCOR * T;
}

// Test function for iau_PR00
void test_iau_PR00() {
    double DATE1 = 2451545.0; // Example date
    double DATE2 = 0.0; // Example date
    double DPSIPR, DEPSPR;
    
    iau_PR00(DATE1, DATE2, DPSIPR, DEPSPR);
    
    cout << "Test case: DATE1 = 2451545.0, DATE2 = 0.0" << endl;
    cout << "DPSIPR = " << DPSIPR << endl;
    cout << "DEPSPR = " << DEPSPR << endl;
}