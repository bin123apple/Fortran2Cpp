#ifdef SPACE_2D
#include <array>

void BoundaryMassForceMatrix2D(double FiS, double FiN, const std::array<std::array<double, 2>, 2>& TT, std::array<std::array<double, 2>, 2>& RN) {
    // Compute the elements of the RN matrix based on the given logic
    RN[0][0] = FiS * TT[0][0] * TT[0][0] + FiN * TT[1][0] * TT[1][0];
    RN[0][1] = (FiS - FiN) * TT[0][0] * TT[1][0];
    RN[1][0] = RN[0][1];
    RN[1][1] = FiS * TT[1][0] * TT[1][0] + FiN * TT[0][0] * TT[0][0];
}
#endif