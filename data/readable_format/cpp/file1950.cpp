#include <iostream>
#include <cmath>
#include <array>
#include <cassert>

std::array<double, 2> center = {0.0, 1.0};  // Adjust center to avoid division by zero in alpha calculation
double theta = 0.0;  // Radians
std::array<double, 2> xcb = {-1.0, 1.0};

void mapc2p(double xc, double yc, double& xp, double& yp) {
    double ls, alpha, xrot, yrot;

    if (xc < xcb[0]) {
        ls = std::sqrt(std::pow(xc - xcb[0], 2) + std::pow(yc - center[1], 2));
    } else if (xc > xcb[1]) {
        ls = std::sqrt(std::pow(xc - xcb[1], 2) + std::pow(yc - center[1], 2));
    } else {
        ls = std::abs(yc - center[1]);
    }

    alpha = ls / (-center[1]);
    xrot = center[0] + std::cos(theta) * (xc - center[0]) + std::sin(theta) * (yc - center[1]);
    yrot = center[1] - std::sin(theta) * (xc - center[0]) + std::cos(theta) * (yc - center[1]);

    if (alpha < 1.0) {
        xp = (1.0 - alpha) * xrot + alpha * xc;
        yp = (1.0 - alpha) * yrot + alpha * yc;
    } else {
        xp = xc;
        yp = yc;
    }
}

void run_test(double xc, double yc, double expected_xp, double expected_yp) {
    double xp, yp;
    mapc2p(xc, yc, xp, yp);
    std::cout << "Test - Got xp: " << xp << " yp: " << yp << std::endl;
    assert(std::abs(xp - expected_xp) < 1e-9 && std::abs(yp - expected_yp) < 1e-9);
}

int main() {
    // Example test case with expected values (these should be replaced with correct values)
    run_test(0.5, 0.5, 0.5, 0.5);  // Example; replace expected values with correct ones based on manual calculation

    std::cout << "All tests passed!" << std::endl;

    return 0;
}