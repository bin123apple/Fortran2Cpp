#include <iostream>
#include <cmath>
#include <iomanip>

const double eps = 0.00001;

void check_and_print(int i, int j, double a2_val, double expected_val, int& nerr) {
    if (std::abs(a2_val - expected_val) > eps) {
        std::cout << "a2(" << i << "," << j << ")=" << std::fixed << std::setprecision(4) 
                  << a2_val << " should be " << expected_val << std::endl;
        ++nerr;
    }
}

int main() {
    double a2[2][3] = {{7.77, 7.77, 7.77}, {7.77, 7.77, 7.77}};
    int nerr = 0;

    // Simulating the logic for a single "process"
    // Assuming me == 1 for demonstration
    int me = 1;
    
    if (me == 1) {
        a2[0][1] = 1.22; // a2(1,2) in Fortran
        a2[1][1] = 2.22; // a2(2,2) in Fortran
    }

    // Check values (simulation of checks in original program)
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 2; ++i) {
            double expected_val = 7.77; // Default expectation

            if (i == 0 && j == 1) expected_val = 1.22;
            else if (i == 1 && j == 1) expected_val = 2.22;

            check_and_print(i + 1, j + 1, a2[i][j], expected_val, nerr);
        }
    }

    // Result reporting
    if (nerr == 0) {
        std::cout << "[" << me << "] OK" << std::endl;
    } else {
        std::cout << "[" << me << "] number of NGs: " << nerr << std::endl;
    }

    return 0;
}