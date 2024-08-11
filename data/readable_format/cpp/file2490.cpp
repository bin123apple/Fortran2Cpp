#include <complex>
#include <iostream>

// Define constants
const double ZERO = 0.0;
const std::complex<double> CZERO = std::complex<double>(0.0, 0.0);

// Define global variables
int M, N, MPLUSN, I;
bool FS;

// Define the function
bool CLCTSX(std::complex<double> ALPHA, std::complex<double> BETA) {
    bool result;

    if (FS) {
        I = I + 1;
        if (I <= M) {
            result = false;
        } else {
            result = true;
        }
        if (I == MPLUSN) {
            FS = false;
            I = 0;
        }
    } else {
        I = I + 1;
        if (I <= N) {
            result = true;
        } else {
            result = false;
        }
        if (I == MPLUSN) {
            FS = true;
            I = 0;
        }
    }
    return result;
}

int main() {
    // Initialize the common block variables
    M = 5;  // Example value
    N = 3;  // Example value
    MPLUSN = M + N;
    I = 0;
    FS = true;

    // Example usage of the function
    std::complex<double> ALPHA(1.0, 1.0);
    std::complex<double> BETA(2.0, 2.0);

    bool result = CLCTSX(ALPHA, BETA);
    std::cout << "CLCTSX result: " << result << std::endl;

    return 0;
}