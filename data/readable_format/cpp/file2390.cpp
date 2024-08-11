#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>

void PAKDSP(double PAK, char &SGNA, int &DEGS, int &MINS, double &SECS) {
    const double ZERO = 0.0;
    const double CON1 = 1000000.0;
    const double CON2 = 1000.0;
    const double TOL = 1.0e-4;
    const char IBLANK = ' ';
    const char NEG = '-';
    
    SGNA = IBLANK;
    if (PAK < ZERO) SGNA = NEG;
    
    double CON = std::abs(PAK);
    DEGS = static_cast<int>((CON / CON1) + TOL);
    CON = std::fmod(CON, CON1);
    MINS = static_cast<int>((CON / CON2) + TOL);
    SECS = std::fmod(CON, CON2);
}

int main() {
    double PAK = -123456789.0;
    char SGNA;
    int DEGS, MINS;
    double SECS;

    PAKDSP(PAK, SGNA, DEGS, MINS, SECS);

    std::cout << "Test case: PAK = " << PAK << std::endl;
    std::cout << "SGNA: " << SGNA << std::endl;
    std::cout << "DEGS: " << DEGS << std::endl;
    std::cout << "MINS: " << MINS << std::endl;
    std::cout << "SECS: " << std::fixed << std::setprecision(4) << SECS << std::endl;

    return 0;
}