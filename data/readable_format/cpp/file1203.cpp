#include <iostream>
#include <vector>

bool CSSWPTST(int n1, int n2, int n3, int n4, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& z) {
    double dx1, dx2, dx3, dy1, dy2, dy3, dz1, dz2, dz3, x4, y4, z4;

    n1--; n2--; n3--; n4--;

    x4 = x[n4];
    y4 = y[n4];
    z4 = z[n4];
    dx1 = x[n1] - x4;
    dx2 = x[n2] - x4;
    dx3 = x[n3] - x4;
    dy1 = y[n1] - y4;
    dy2 = y[n2] - y4;
    dy3 = y[n3] - y4;
    dz1 = z[n1] - z4;
    dz2 = z[n2] - z4;
    dz3 = z[n3] - z4;

    return (dx3 * (dy2 * dz1 - dy1 * dz2) - dy3 * (dx2 * dz1 - dx1 * dz2) + dz3 * (dx2 * dy1 - dx1 * dy2)) > 0.0;
}

void testCSSWPTST(int testId, int n1, int n2, int n3, int n4, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& z, bool expected) {
    bool result = CSSWPTST(n1, n2, n3, n4, x, y, z);
    std::cout << "Test " << testId << ((result == expected) ? " passed." : " failed.") << std::endl;
}

int main() {
    std::vector<double> x = {0.0, 1.0, 0.0, -1.0};
    std::vector<double> y = {0.0, 0.0, 1.0, 0.0};
    std::vector<double> z = {1.0, 1.0, 1.0, 1.0};

    testCSSWPTST(1, 1, 2, 3, 4, x, y, z, false); // Adjusted expectation based on Fortran test results
    testCSSWPTST(2, 3, 1, 2, 4, x, y, z, false);

    return 0;
}