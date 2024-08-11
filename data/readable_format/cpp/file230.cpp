#include <iostream>
#include <complex>
#include <cmath>

// Declaration of ZROTG function
void ZROTG(std::complex<double>& CA, std::complex<double>& CB, double& C, std::complex<double>& S) {
    std::complex<double> ALPHA;
    double NORM, SCALE;
    
    if (std::abs(CA) == 0.0) {
        C = 0.0;
        S = std::complex<double>(1.0, 0.0);
        CA = CB;
    } else {
        SCALE = std::abs(CA) + std::abs(CB);
        NORM = SCALE * std::sqrt(std::pow(std::abs(CA / std::complex<double>(SCALE, 0.0)), 2) +
                                 std::pow(std::abs(CB / std::complex<double>(SCALE, 0.0)), 2));
        ALPHA = CA / std::abs(CA);
        C = std::abs(CA) / NORM;
        S = ALPHA * std::conj(CB) / NORM;
        CA = ALPHA * NORM;
    }
}

int main() {
    std::complex<double> CA, CB, S;
    double C;

    // Test case 1
    CA = std::complex<double>(1.0, 2.0);
    CB = std::complex<double>(3.0, 4.0);
    ZROTG(CA, CB, C, S);
    std::cout << "Test 1 - CA: " << CA << " CB: " << CB << " C: " << C << " S: " << S << std::endl;

    // Feel free to add more tests as needed

    return 0;
}