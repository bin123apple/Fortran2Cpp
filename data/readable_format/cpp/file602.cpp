#include <iostream>
#include <cmath>
#include <cassert>

constexpr double one = 1.0;
constexpr double half = 0.5;
constexpr double two = 2.0;

void infel(double v, double va, double& vv, double& dvv, int io) {
    double sgn, fac, fac1;

    vv = half * (one + va * v);
    dvv = half * va;
    if (io == 0) return;

    sgn = one;
    if (io == 1) sgn = -one;

    fac = one - sgn * v;
    fac1 = half * std::abs(va + sgn);
    vv = fac1 + two * v * va / fac;
    dvv = two * va / (fac * fac);
}

void runTest(double v, double va, int io, double expectedVv, double expectedDvv) {
    double vv = 0.0, dvv = 0.0;
    infel(v, va, vv, dvv, io);
    assert(std::abs(vv - expectedVv) < 1e-6 && "VV test failed");
    assert(std::abs(dvv - expectedDvv) < 1e-6 && "DVV test failed");
    std::cout << "Test passed with io=" << io << ", v=" << v << ", va=" << va << ", vv=" << vv << ", dvv=" << dvv << std::endl;
}

int main() {
    // Test case 1: io = 0
    runTest(0.5, 0.5, 0, 0.625, 0.25);

    // Test case 2: io = 1
    runTest(-0.5, 0.5, 1, -0.75, 4.0);

    // Ensure these tests match your Fortran outputs exactly
    return 0;
}