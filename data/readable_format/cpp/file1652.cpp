#include <iostream>
#include <cmath>
#include <cassert>

double distance(double asep, double eccn, double Tanom) {
    return asep * (1.0 - eccn * eccn) / (1 + eccn * std::cos(Tanom));
}

double trueanomaly(double eccn, double Eanom) {
    double temp1 = std::sqrt((1.0 + eccn) / (1.0 - eccn));
    double temp2 = std::tan(Eanom / 2.0);
    return 2.0 * std::atan(temp1 * temp2);
}

void kepler(double Manom, double& Eanom, double eccn) {
    const int itmax = 100;
    double Eold, diff, thres = 1.0e-8;
    int i = 0;

    do {
        Eold = Eanom;
        Eanom = Manom + eccn * std::sin(Eold); // Corrected to use Eold for the calculation
        diff = std::abs(Eanom - Eold);
        i++;
    } while (diff > thres && i < itmax);
}

void invkepler(double Eanom, double& Manom, double eccn) {
    const int itmax = 100;
    double Mold, diff, thres = 1.0e-6;
    int i = 0;

    do {
        Mold = Manom;
        Manom = Eanom - eccn * std::sin(Mold); // Corrected to use Mold for the calculation
        diff = std::abs(Manom - Mold);
        i++;
    } while (diff > thres && i < itmax);
}

// Helper function to compare double values
bool areClose(double a, double b, double tolerance = 1e-8) {
    return std::abs(a - b) < tolerance;
}

int main() {
    double asep = 1.0, eccn = 0.1, Tanom = 0.5;
    assert(areClose(distance(asep, eccn, Tanom), 0.91012869299513888));

    eccn = 0.1; double Eanom = 0.5;
    assert(areClose(trueanomaly(eccn, Eanom), 0.55026397471366328));

    double Manom = 0.5; Eanom = 0.1; eccn = 0.1;
    kepler(Manom, Eanom, eccn);
    assert(areClose(Eanom, 0.55247998678778321));

    Eanom = 0.5; Manom = 0.1; eccn = 0.1;
    invkepler(Eanom, Manom, eccn);
    assert(areClose(Manom, 0.45596695102025764));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}