#include <cmath>

// Assuming the use of `float` for the real type to match the Fortran REAL type.
// Adjust the type if necessary (e.g., use `double` for higher precision).
int PT2SAM(float PT, int BITS) {
    // Check if PT exceeds absolute value of 1 and normalize if so
    if (std::abs(PT) > 1.0) {
        PT = PT / std::abs(PT);
    }

    if (BITS != 8) {
        // Calculate using the first formula
        return static_cast<int>(PT * (std::pow(2, BITS - 1) - 1) + 0.5);
    } else {
        // Calculate using the second formula for BITS == 8
        return static_cast<int>((PT * 0.5 + 0.5) * (std::pow(2, BITS) - 1) + 0.5);
    }
}