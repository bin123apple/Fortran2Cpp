#include <iostream>
#include <iomanip>

double w(double r, double h, double coef) {
    const double a1 = 2.0 / 3.0;
    double s = r / h;
    double q;

    if (s <= 1.0) {
        q = a1 * (1.0 - 1.5 * (s * s) * (1.0 - s / 2.0));
    } else if (s > 1.0 && s < 2.0) {
        double dms = 2.0 - s;
        q = a1 * (dms * dms * dms) / 6.0;
    } else {
        q = 0.0;
    }

    return q * coef;
}

int main() {
    double r, h, coef;

    // Test case 1
    r = 0.5;
    h = 1.0;
    coef = 2.0;
    std::cout << "Test case 1: " << std::setprecision(10) << w(r, h, coef) << std::endl;

    // Test case 2
    r = 1.5;
    h = 1.0;
    coef = 2.0;
    std::cout << "Test case 2: " << std::setprecision(10) << w(r, h, coef) << std::endl;

    // Test case 3
    r = 2.5;
    h = 1.0;
    coef = 2.0;
    std::cout << "Test case 3: " << std::setprecision(10) << w(r, h, coef) << std::endl;

    return 0;
}