#include <iostream>
#include <cmath>

void norshell3(double xi, double et, double xl[3][3], double xnor[3]) {
    double shp[2][3] = {
        {-1.0, 1.0, 0.0},
        {-1.0, 0.0, 1.0}
    };
    double xs[3][2] = {0};
    int i, j, k;

    // Computing xs array
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 2; ++j) {
            xs[i][j] = 0.0;
            for (k = 0; k < 3; ++k) {
                xs[i][j] += xl[i][k] * shp[j][k];
            }
        }
    }

    // Computing xnor vector
    xnor[0] = xs[1][0] * xs[2][1] - xs[2][0] * xs[1][1];
    xnor[1] = xs[2][0] * xs[0][1] - xs[0][0] * xs[2][1];
    xnor[2] = xs[0][0] * xs[1][1] - xs[1][0] * xs[0][1];
}

int main() {
    double xi = 0.0; // These values could be set as needed
    double et = 0.0; // Same here
    double xl[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double xnor[3];
    
    norshell3(xi, et, xl, xnor);
    
    // Output result for verification
    for (int i = 0; i < 3; ++i) {
        std::cout << "xnor(" << i + 1 << ") = " << xnor[i] << std::endl;
    }
    
    return 0;
}