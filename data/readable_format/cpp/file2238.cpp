#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

int ifun(int arg1, int arg2) {
    return arg1 + arg2;
}

double jfun(double arg1) {
    return std::sqrt(arg1);
}

void subr1(double a, double b) {
    double arrayA[3][4][3];
    auto stmtfn = [](double x, double y, double z) {
        return std::max(x, std::max(y, z));
    };
    double c = stmtfn(b, a, a);
    arrayA[0][0][0] = c;
    std::cout << "subr1 - Value is: " << c << std::endl;
}

void subr2() {
    double i = 1.0;
    int j = 2;
    int m = 3;
    double l = 4.5;

    std::cout << "inside subroutine subr2" << std::endl;
    std::cout << "IFUN RETURNS: " << ifun(j, m) << std::endl;
    std::cout << "JFUN RETURNS: " << jfun(i + l) << std::endl;
}

// Testing functions
void testIfun() {
    std::cout << "Testing ifun..." << std::endl;
    std::cout << "ifun(2, 3) should be 5: " << ifun(2, 3) << std::endl;
    std::cout << "ifun(-1, 1) should be 0: " << ifun(-1, 1) << std::endl;
}

void testJfun() {
    std::cout << "Testing jfun..." << std::endl;
    std::cout << "jfun(4.0) should be 2: " << jfun(4.0) << std::endl;
    std::cout << "jfun(9.0) should be 3: " << jfun(9.0) << std::endl;
}

int main() {
    // Run tests
    testIfun();
    testJfun();

    // Run subroutine demonstrations
    subr1(3.0, 4.0);
    subr2();

    return 0;
}