#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

// Definition of UHYPER function
void UHYPER(double I1B, double I2B, double JAC, std::vector<double>& U, std::vector<double>& DU,
            std::vector<double>& D2U, std::vector<double>& D3U, double TEMP, int NOEL, const std::string& CMNAME,
            int INCMPFLAG, int NSTATEV, std::vector<double>& STATEV, int NFIELDV, std::vector<double>& FIELDV,
            std::vector<double>& FIELDVINC, int NPROPS, const std::vector<double>& PROPS) {
    // Constants
    const double ZERO = 0.0;
    const double ONE = 1.0;
    const double TWO = 2.0;
    const double THREE = 3.0;

    // Local variables
    double C10, D1, U_VOL, U_DEV;

    C10 = PROPS[0]; // Note: C++ uses 0-based indexing
    D1 = PROPS[1];

    U_VOL = ONE / D1 * std::pow((JAC - ONE), 2);
    U_DEV = C10 * (I1B - THREE);
    U[0] = U_VOL + U_DEV; // Adjusting for 0-based indexing
    U[1] = U_DEV;

    DU[0] = C10;
    DU[1] = ZERO;
    DU[2] = TWO / D1 * (JAC - ONE);

    D2U[0] = ZERO;
    D2U[1] = ZERO;
    D2U[2] = TWO / D1;
    D2U[3] = ZERO;
    D2U[4] = ZERO;
    D2U[5] = ZERO;

    D3U[0] = ZERO;
    D3U[1] = ZERO;
    D3U[2] = ZERO;
    D3U[3] = ZERO;
    D3U[4] = ZERO;
    D3U[5] = ZERO;
}

// Unit test code
void testUHYPER() {
    double I1B = 2.0;
    double I2B = 3.0;
    double JAC = 1.1;
    double TEMP = 298.15;
    int NOEL = 1;
    std::string CMNAME = "TEST";
    int INCMPFLAG = 0;
    int NSTATEV = 1;
    int NFIELDV = 1;
    int NPROPS = 2;
    std::vector<double> PROPS = {1.0, 2.0};
    std::vector<double> U(2), DU(3), D2U(6), D3U(6), STATEV(NSTATEV), FIELDV(NFIELDV), FIELDVINC(NFIELDV);

    // Call the UHYPER function
    UHYPER(I1B, I2B, JAC, U, DU, D2U, D3U, TEMP, NOEL, CMNAME, INCMPFLAG, NSTATEV, STATEV, NFIELDV, FIELDV, FIELDVINC, NPROPS, PROPS);

    std::cout << std::setprecision(5);
    std::cout << "U: " << U[0] << ", " << U[1] << std::endl;
    std::cout << "DU: ";
    for (const auto& val : DU) std::cout << val << " ";
    std::cout << std::endl << "D2U: ";
    for (const auto& val : D2U) std::cout << val << " ";
    std::cout << std::endl << "D3U: ";
    for (const auto& val : D3U) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    testUHYPER();
    return 0;
}