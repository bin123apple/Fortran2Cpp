// RADDDP.cpp
#include <cmath>
#include <iostream>

void radddp(double& rad, char& sgna, int& degs, int& mins, float& secs) {
    const double RADSEC = 206264.806247;
    const double ZERO = 0.0;
    const double TOL = 1.0e-4;
    const char BLANK = ' ';
    const char NEG = '-';

    double con = std::abs(rad) * RADSEC;
    int isec = static_cast<int>(con + TOL);

    sgna = BLANK;
    if (rad < ZERO) sgna = NEG;
    if (con < TOL) {
        degs = 0;
        mins = 0;
        secs = 0.0f;
        return;
    }

    int intg = isec / 3600;
    degs = intg;
    isec -= intg * 3600;

    mins = isec / 60;
    isec -= mins * 60;

    secs = isec;
}

// Main program to test the function
int main() {
    double rad = 0.12345;
    char sgna;
    int degs, mins;
    float secs;

    radddp(rad, sgna, degs, mins, secs);
    std::cout << "Positive radians: " << sgna << " " << degs << " " << mins << " " << secs << std::endl;

    rad = -0.12345;
    radddp(rad, sgna, degs, mins, secs);
    std::cout << "Negative radians: " << sgna << " " << degs << " " << mins << " " << secs << std::endl;

    return 0;
}