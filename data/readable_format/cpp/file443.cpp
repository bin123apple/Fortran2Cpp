#include <iostream>
#include <cmath>
#include <vector>

const double r23 = std::pow(0.5, 23);
const double r46 = r23 * r23;
const double t23 = std::pow(2.0, 23);
const double t46 = t23 * t23;

double randlc(double& x, double a) {
    double t1, t2, t3, t4, a1, a2, x1, x2, z;
    
    t1 = r23 * a;
    a1 = static_cast<int>(t1);
    a2 = a - t23 * a1;
    t1 = r23 * x;
    x1 = static_cast<int>(t1);
    x2 = x - t23 * x1;
    t1 = a1 * x2 + a2 * x1;
    t2 = static_cast<int>(r23 * t1);
    z = t1 - t23 * t2;
    t3 = t23 * z + a2 * x2;
    t4 = static_cast<int>(r46 * t3);
    x = t3 - t46 * t4;
    
    return r46 * x;
}

void vranlc(int n, double& x, double a, std::vector<double>& y) {
    for (int i = 0; i < n; ++i) {
        y[i] = randlc(x, a);
    }
}

int main() {
    double x = 12345.6789;
    double a = 987654.321;
    std::vector<double> y(10);

    std::cout << "Testing randlc with x = " << x << " and a = " << a << std::endl;
    std::cout << "randlc result: " << randlc(x, a) << std::endl;

    vranlc(10, x, a, y);
    std::cout << "Testing vranlc with 10 elements" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "y[" << i << "] = " << y[i] << std::endl;
    }

    return 0;
}