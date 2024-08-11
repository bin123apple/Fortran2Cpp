// GLQGridCoordTest.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void CalculateGLQGridCoord(std::vector<double>& latglq, std::vector<double>& longlq, int lmax, int& nlat, int& nlong) {
    const double pi = std::acos(-1.0);
    nlat = lmax + 1;
    nlong = 2 * lmax + 1;

    latglq.resize(nlat);
    longlq.resize(nlong);

    for (int i = 0; i < nlat; ++i) {
        latglq[i] = -90.0 + i * 180.0 / (nlat - 1);
    }

    for (int i = 0; i < nlong; ++i) {
        longlq[i] = i * 360.0 / nlong;
    }
}

void TestGLQGridCoord(int lmax) {
    int nlat, nlong;
    std::vector<double> latglq, longlq;

    CalculateGLQGridCoord(latglq, longlq, lmax, nlat, nlong);

    assert(latglq.size() == static_cast<size_t>(nlat) && "Latitude array size mismatch.");
    assert(longlq.size() == static_cast<size_t>(nlong) && "Longitude array size mismatch.");

    std::cout << "Test passed for lmax = " << lmax << std::endl;
}

int main() {
    for (int lmax = 2; lmax <= 5; ++lmax) {
        TestGLQGridCoord(lmax);
    }
    return 0;
}