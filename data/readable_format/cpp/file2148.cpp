#include <iostream>
#include <cmath>
#include <array>

void FDEXP(double X, std::array<double, 10>& A, double& Y, std::array<double, 10>& DYDA) {
    const double TINY = 1.0e-10;

    // Ensure A[2] and A[3] are no less than TINY (adjusting for 0-based indexing)
    A[2] = std::max(A[2], TINY);
    A[3] = std::max(A[3], TINY);

    double ARG1 = (X - A[1]) / A[2];
    double ARG2 = (X - A[1]) / A[3];
    double EX1 = std::exp(-ARG1);
    double EX2 = std::exp(ARG2);
    double FAC = EX1 + EX2;
    Y = 2.0 * A[0] / FAC;
    DYDA[0] = 2.0 / FAC;
    DYDA[1] = Y * (EX2 / A[3] - EX1 / A[2]) / FAC;
    DYDA[2] = -Y * ARG1 * EX1 / (FAC * A[2]);
    DYDA[3] = Y * ARG2 * EX2 / (FAC * A[3]);
}

int main() {
    double X = 1.0;
    std::array<double, 10> A = {1.0, 2.0, 3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double Y;
    std::array<double, 10> DYDA;

    FDEXP(X, A, Y, DYDA);

    std::cout << "Y: " << Y << std::endl;
    std::cout << "DYDA: ";
    for (int i = 0; i < 4; ++i) { // Adjust to output only relevant DYDA elements
        std::cout << DYDA[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}