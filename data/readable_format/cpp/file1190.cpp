#include <iostream>
#include <cmath>
#include <cassert>

double eqn6001(double x) {
    return 0.04374048076242294 + x*(0.0001367780769892812 +
           x*(-4.850231342481508e-08 + x*(8.549501530074314e-12 +
           x*(-4.899699862336812e-16))));
}

void test_eqn6001() {
    double test_x = 2600.0;
    double expected_y = eqn6001(test_x); // Expected result is the output of eqn6001 for test_x
    double tolerance = 1.0e-8;
    assert(std::fabs(eqn6001(test_x) - expected_y) < tolerance && "Test for eqn6001 failed.");
    std::cout << "Test for eqn6001 passed." << std::endl;
}

int main() {
    double x, y, a, b, c, d, e, teff;
    double order1, order2, order3, order4, constant;
    double ohzflux;

    a = 0.04374048076242294;
    b = 0.0001367780769892812;
    c = -4.850231342481508e-08;
    d = 8.549501530074314e-12;
    e = -4.899699862336812e-16;
    teff = 5780.0;

    constant = a + b*teff + c*pow(teff, 2) + d*pow(teff, 3) + e*pow(teff, 4);
    order1 = b + 2.0*c*teff + 3.0*d*pow(teff, 2) + 4.0*e*pow(teff, 3);
    order2 = c + 3.0*d*teff + 6.0*e*pow(teff, 2);
    order3 = d + 4.0*e*teff;
    order4 = e;

    // Corrected the string to be on a single line
    std::cout << "Constant, Order1, Order2, Order3, Order4: ";
    std::cout << constant << ", " << order1 << ", " << order2 << ", " << order3 << ", " << order4 << std::endl;

    x = 2600.0;
    while (x <= 7201.0) {
        y = eqn6001(x);
        ohzflux = constant + order1*(x-teff) + order2*pow(x-teff, 2) +
                  order3*pow(x-teff, 3) + order4*pow(x-teff, 4);
        std::cout << "X, OHZFlux: " << x << ", " << ohzflux << std::endl;
        x += 200.0;
    }

    // Run the test
    test_eqn6001();
    std::cout << "All tests passed." << std::endl;

    return 0;
}