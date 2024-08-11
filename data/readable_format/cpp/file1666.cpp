#include <iostream>
#include <cmath>

namespace segment {
    int whichSegment(double x, double xLower, double xUpper, int iLower, int iUpper) {
        if (x <= xLower) return iLower;
        else if (x >= xUpper) return iUpper;
        else return iLower + static_cast<int>(std::floor(0.5 + (x - xLower) / (xUpper - xLower) * (iUpper - iLower)));
    }
}

void testWhichSegment(double x, double xLower, double xUpper, int iLower, int iUpper, int expected) {
    int result = segment::whichSegment(x, xLower, xUpper, iLower, iUpper);
    std::cout << "For input (" << x << ", " << xLower << ", " << xUpper << ", " << iLower << ", " << iUpper << "), "
              << "expected " << expected << " and got " << result << ". "
              << (result == expected ? "PASS" : "FAIL") << std::endl;
}

int main() {
    testWhichSegment(5.5, 1.0, 10.0, 1, 10, 6);
    testWhichSegment(1.0, 1.0, 10.0, 1, 10, 1);
    testWhichSegment(10.0, 1.0, 10.0, 1, 10, 10);
    testWhichSegment(0.0, 1.0, 10.0, 1, 10, 1);
    testWhichSegment(11.0, 1.0, 10.0, 1, 10, 10);
    return 0;
}