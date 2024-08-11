#include <iostream>
#include <cmath>

const double ZERO = 0.0;
const double PI = 3.14159265358979323846;
const double TWO_PI = 2.0 * PI;
const double TINYVAL = 1.0e-10;

void reduce(double& theta, double& phi) {
    if (std::abs(theta) < TINYVAL) theta += 0.0000001;
    if (std::abs(phi) < TINYVAL) phi += 0.0000001;

    double th = theta;
    double ph = phi;
    int i;

    // Similar logic to Fortran for adjusting theta and phi
    // Make sure the logic matches the Fortran version provided above

}

bool areClose(double a, double b, double tolerance = 1e-7) {
    return std::abs(a - b) < tolerance;
}

void testReduce(double theta, double phi, const char* testName) {
    reduce(theta, phi);
    std::cout << testName << " (Theta, Phi): " << theta << ", " << phi << std::endl;
}

int main() {
    testReduce(-0.1, TWO_PI + 0.1, "Test 1");
    testReduce(3*PI/2, -0.1, "Test 2");
    // Add more tests as needed

    return 0;
}