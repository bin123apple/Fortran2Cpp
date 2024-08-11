#include <vector>
#include <cmath>
#include <iostream>
#include <cassert>

// Define the SDAWTS function as translated to C++
void SDAWTS(int NEQ, int IWT, const std::vector<float>& RTOL, const std::vector<float>& ATOL, const std::vector<float>& Y, std::vector<float>& WT, const std::vector<float>& RPAR, const std::vector<int>& IPAR) {
    float ATOLI, RTOLI;
    RTOLI = RTOL[0];
    ATOLI = ATOL[0];
    for (int I = 0; I < NEQ; ++I) {
        if (IWT != 0) {
            RTOLI = RTOL[I];
            ATOLI = ATOL[I];
        }
        WT[I] = RTOLI * std::abs(Y[I]) + ATOLI;
    }
}

// Unit test function
void testSDAWTS() {
    int NEQ = 3;
    int IWT = 0;
    std::vector<float> RTOL = {0.1f, 0.1f, 0.1f};
    std::vector<float> ATOL = {1.0f, 1.0f, 1.0f};
    std::vector<float> Y = {10.0f, 20.0f, 30.0f};
    std::vector<float> WT(NEQ);
    std::vector<float> RPAR = {0};
    std::vector<int> IPAR = {0};

    SDAWTS(NEQ, IWT, RTOL, ATOL, Y, WT, RPAR, IPAR);

    // Output the results
    std::cout << "WT for test case:" << std::endl;
    for (auto w : WT) {
        std::cout << w << std::endl;
    }

    // Assertions to verify correctness
    assert(std::fabs(WT[0] - (RTOL[0] * std::abs(Y[0]) + ATOL[0])) < 1e-5);
    assert(std::fabs(WT[1] - (RTOL[1] * std::abs(Y[1]) + ATOL[1])) < 1e-5);
    assert(std::fabs(WT[2] - (RTOL[2] * std::abs(Y[2]) + ATOL[2])) < 1e-5);
}

int main() {
    testSDAWTS();
    std::cout << "All tests passed." << std::endl;
    return 0;
}