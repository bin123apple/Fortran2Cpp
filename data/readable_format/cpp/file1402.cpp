#include <cmath> // For comparison
#include <iostream>

bool SB02MR(double REIG, double IEIG) {
    const double ZERO = 0.0;
    return REIG >= ZERO;
}

// Example usage
int main() {
    double REIG = 1.0;
    double IEIG = 2.0; // Note: IEIG is not used in this function, similar to the Fortran version

    bool result = SB02MR(REIG, IEIG);
    std::cout << std::boolalpha << result << std::endl; // Outputs: true

    return 0;
}