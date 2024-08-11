#include <iostream>
#include <cmath> // For fabs function
#include <cassert>

double PYGAMM(double X) {
    double B[] = {-0.577191652, 0.988205891, -0.897056937, 0.918206857,
                  -0.756704078, 0.482199394, -0.193527818, 0.035868343};
    int NX = static_cast<int>(std::floor(X));
    double DX = X - NX;
    double result = 1.0;
    double DXP = 1.0;

    for (int i = 0; i < 8; ++i) {
        DXP *= DX;
        result += B[i] * DXP;
    }

    if (X < 1.0) {
        result /= X;
    } else {
        for (int IX = 1; IX <= NX - 1; ++IX) {
            result *= (X - IX);
        }
    }

    return result;
}

int main() {
    double testValues[] = {0.5, 1.0, 1.5, 2.0, 10.0};
    double expectedResults[] = {1.7724539918359374, 1.0, 0.88622699591796872, 1.0, 362880.0};
    
    for (int i = 0; i < 5; ++i) {
        double result = PYGAMM(testValues[i]);
        std::cout << "PYGAMM(" << testValues[i] << ") = " << result << " Expected: " << expectedResults[i] << std::endl;
        assert(std::fabs(result - expectedResults[i]) < 1e-6);
    }
    
    std::cout << "All tests passed." << std::endl;
    return 0;
}