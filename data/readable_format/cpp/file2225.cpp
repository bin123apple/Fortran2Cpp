#include <iostream>

double cvmgp(double x1, double x2, int x3) {
    if (x3 < 0) {
        return x2;
    } else {
        return x1;
    }
}

double cvmgz(double x1, double x2, int x3) {
    if (x3 < 0) {
        return x2;
    } else {
        return x1;
    }
}

double cvmgn(double x1, double x2, int x3) {
    if (x3 <= 0) {
        return x1;
    } else {
        return x2;
    }
}

double cvmgt(double x1, double x2, bool x3) {
    if (x3) {
        return x1;
    } else {
        return x2;
    }
}

double cvmgm(double x1, double x2, int x3) {
    if (x3 <= 0) {
        return x2;
    } else {
        return x1;
    }
}

int main() {
    // Test the functions
    std::cout << "cvmgp(1.0, 2.0, -1): " << cvmgp(1.0, 2.0, -1) << std::endl;
    std::cout << "cvmgz(1.0, 2.0, -1): " << cvmgz(1.0, 2.0, -1) << std::endl;
    std::cout << "cvmgn(1.0, 2.0, 1): " << cvmgn(1.0, 2.0, 1) << std::endl;
    std::cout << "cvmgt(1.0, 2.0, true): " << cvmgt(1.0, 2.0, true) << std::endl;
    std::cout << "cvmgm(1.0, 2.0, -1): " << cvmgm(1.0, 2.0, -1) << std::endl;

    return 0;
}