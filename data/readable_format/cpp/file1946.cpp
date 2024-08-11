// mandelbrot.cpp
#include <iostream>
#include <complex>

double calculateMandelbrotArea(int npoints, int maxiter) {
    int numoutside = 0;
    std::complex<double> c, z;

    for (int i = 0; i < npoints; ++i) {
        for (int j = 0; j < npoints; ++j) {
            c = std::complex<double>(-2.0 + (2.5 * i) / npoints, (1.125 * j) / npoints);
            z = c;
            int iter = 0;
            while (iter < maxiter) {
                z = z * z + c;
                iter++;
                if (std::norm(z) > 4.0) {
                    numoutside++;
                    break;
                }
            }
        }
    }

    return 2.0 * 2.5 * 1.125 * static_cast<double>(npoints * npoints - numoutside) / static_cast<double>(npoints * npoints);
}

int main() {
    double area = calculateMandelbrotArea(200, 200); // Using smaller values for a quick test
    std::cout << "Computed Area: " << area << std::endl;
    return 0;
}