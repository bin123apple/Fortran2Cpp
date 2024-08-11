#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

void writecvg(int istep, int iinc, int icutb, int iit, int ne, int ne0, double* ram, double* qam, double* cam, double* uam, int ithermal) {
    // Place the original function logic here
    std::cout << "This is a test output for ithermal = " << ithermal << std::endl;
    // The actual calculation and printing logic is omitted for brevity
}

int main() {
    int ne = 2;
    double ram[2] = {0.1, 0.2};
    double qam[2] = {0.1, 0.2};
    double cam[2] = {0.1, 0.2};
    double uam[2] = {0.1, 0.2};

    writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 0);
    writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 1);
    writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 2);

    return 0;
}