#include <cmath>
#include <vector>

int main() {
    // Assuming phi, psi, theta, W, V, U are defined and initialized somewhere in the code.
    double phi, psi, theta, W, V, U;

    // Initialize these variables for the sake of example
    phi = /* some value */;
    psi = /* some value */;
    theta = /* some value */;
    W = /* some value */;
    V = /* some value */;
    U = /* some value */;

    // Assuming v_n is a 2D vector initialized with 3 rows and 1 column.
    // In C++, we can use a vector of vectors, but since we know it's essentially a 3x1 vector,
    // a simple array or std::vector with 3 elements is more appropriate.
    std::vector<double> v_n(3);

    v_n[0] = (cos(phi) * cos(psi) * sin(theta) + sin(phi) * sin(psi)) * W +
             (sin(phi) * cos(psi) * sin(theta) - cos(phi) * sin(psi)) * V +
             cos(psi) * cos(theta) * U;

    v_n[1] = (cos(phi) * sin(psi) * sin(theta) - sin(phi) * cos(psi)) * W +
             (sin(phi) * sin(psi) * sin(theta) + cos(phi) * cos(psi)) * V +
             sin(psi) * cos(theta) * U;

    v_n[2] = cos(phi) * cos(theta) * W + sin(phi) * cos(theta) * V - sin(theta) * U;

    // Add code here to use v_n as needed
    return 0;
}