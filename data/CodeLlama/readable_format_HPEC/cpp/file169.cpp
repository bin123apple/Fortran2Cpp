#include <iostream>

// Assuming the dimensions of ce are known and defined globally or passed as a parameter
const int ce_rows = 5; // Example value, adjust as necessary
const int ce_cols = 13; // Example value, adjust as necessary
double ce[ce_rows][ce_cols]; // Example declaration, adjust according to actual use

void exact_solution(double xi, double eta, double zeta, double* dtemp) {
    for (int m = 0; m < 5; ++m) {
        dtemp[m] = ce[m][0] + xi * (ce[m][1] + xi * (ce[m][5] + xi * (ce[m][8] + xi * ce[m][11]))) +
                   eta * (ce[m][2] + eta * (ce[m][6] + eta * (ce[m][9] + eta * ce[m][12]))) +
                   zeta * (ce[m][3] + zeta * (ce[m][7] + zeta * (ce[m][10] + zeta * ce[m][13])));
    }
}

int main() {
    // Example usage
    double xi = 0.5, eta = 0.25, zeta = 0.75;
    double dtemp[5];
    
    exact_solution(xi, eta, zeta, dtemp);
    
    // Print the results
    for (int i = 0; i < 5; ++i) {
        std::cout << "dtemp[" << i << "] = " << dtemp[i] << std::endl;
    }
    
    return 0;
}
