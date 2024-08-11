#include <iostream>
#include <cmath>
#include <iomanip>

void writeevcs(double* x, int nx, int nm, double xmin, double xmax) {
    const double pi = 4.0 * atan(1.0);
    const double xnull = 0.0;

    std::cout << std::endl;
    std::cout << "    E I G E N V A L U E   O U T P U T" << std::endl;
    std::cout << std::endl;
    std::cout << " NODAL   MODE NO    EIGENVALUE                      FREQUENCY" << std::endl;
    std::cout << "DIAMETER                                    REAL PART           IMAGINARY PART" << std::endl;
    std::cout << "                                   (RAD/TIME)      (CYCLES/TIME)   (RAD/TIME)" << std::endl;
    std::cout << std::endl;

    for (int j = 0; j < nx; ++j) {
        if (xmin > -0.5) {
            if (xmin * xmin > x[j]) continue;
        }

        if (xmax > -0.5) {
            if (xmax * xmax < x[j]) break;
        }

        std::cout << std::setw(5) << nm << std::setw(9) << (j+1);
        if (x[j] < 0.0) {
            std::cout << std::setw(4) << " " << std::scientific << std::setprecision(7)
                      << x[j] << std::setw(18) << xnull << std::setw(18) << xnull
                      << std::setw(18) << sqrt(-x[j]) << std::endl;
        } else {
            std::cout << std::setw(4) << " " << std::scientific << std::setprecision(7)
                      << x[j] << std::setw(18) << sqrt(x[j]) << std::setw(18)
                      << sqrt(x[j]) / (2.0 * pi) << std::setw(18) << xnull << std::endl;
        }
    }
}

int main() {
    // Example usage
    double x[] = {0.25, -0.5, 0.75, 1.0, -1.25, 1.5};
    int nx = sizeof(x) / sizeof(x[0]);
    int nm = 1; // Mode number, example value
    double xmin = -0.5; // Example value
    double xmax = 1.5; // Example value

    writeevcs(x, nx, nm, xmin, xmax);

    return 0;
}