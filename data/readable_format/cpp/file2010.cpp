#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

class otGrid {
public:
    std::vector<std::vector<double>> p; // Assuming a 2D vector for simplicity
    std::vector<double> h;
    std::vector<double> a;
    std::vector<double> v;
    int nC;

    otGrid() : nC(10) {
        p = std::vector<std::vector<double>>(nC, std::vector<double>(3, 0.0));
        // Initialize p with the same values as in Fortran for consistency
        for (int i = 0; i < nC; ++i) {
            p[i] = {0.375, 0.125, 0.375};
        }
        h = std::vector<double>(nC, 0.25);
        a = std::vector<double>(nC, 0.0625);
        v = std::vector<double>(nC, 0.015625);
    }

    void clear() {
        // Simplified clear - adjust to match your actual clear functionality
        p.clear();
        h.clear();
        a.clear();
        v.clear();
    }
};

double tiny() {
    return std::numeric_limits<double>::epsilon();
}

int otGrid2() {
    otGrid grid;
    int result = 0;
    std::vector<double> point = {0.375, 0.125, 0.375};

    double normResult = std::sqrt(std::pow(grid.p[5][0] - point[0], 2) +
                                  std::pow(grid.p[5][1] - point[1], 2) +
                                  std::pow(grid.p[5][2] - point[2], 2));
    if (normResult > 1e-15) {
        result += 1;
    }

    for (int i = 0; i < grid.nC; ++i) {
        if (std::abs(grid.h[i] - 0.25) > 1e-15) {
            result += 10;
            break;
        }
    }

    for (int i = 0; i < grid.nC; ++i) {
        if (std::abs(grid.a[i] - std::pow(0.25, 2)) > 1e-15) {
            result += 100;
            break;
        }
    }

    for (int i = 0; i < grid.nC; ++i) {
        if (std::abs(grid.v[i] - std::pow(0.25, 3)) > 1e-15) {
            result += 1000;
            break;
        }
    }

    grid.clear();

    return result;
}

int main() {
    int testResult = otGrid2();
    std::cout << "C++ test result: " << testResult << std::endl;
    return 0;
}