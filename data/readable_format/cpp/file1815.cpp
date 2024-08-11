#include <iostream>
#include <cmath>
#include <vector>

// Assuming certain global variables based on the Fortran code. Adjust types and names as necessary.
int NK_s, NK_e, NB, NL;
double aLx, aLy, aLz, Hx, Hy, Hz;
std::vector<std::vector<std::vector<double>>> zu_GS; // 3D vector for wave functions
std::vector<double> Lx, Ly, Lz; // position vectors

void quickrnd(int& iseed, double& rnd) {
    const int im = 6075, ia = 106, ic = 1283;
    iseed = (iseed * ia + ic) % im;
    rnd = static_cast<double>(iseed) / static_cast<double>(im);
}

void init_wf() {
    int iseed, ib, ik, i;
    double r2, x1, y1, z1, rnd;

    for (ik = NK_s; ik <= NK_e; ++ik) {
        iseed = 123 + ik;
        for (ib = 0; ib < NB; ++ib) {
            quickrnd(iseed, rnd);
            x1 = aLx * rnd;
            quickrnd(iseed, rnd);
            y1 = aLy * rnd;
            quickrnd(iseed, rnd);
            z1 = aLz * rnd;
            for (i = 0; i < NL; ++i) {
                r2 = pow(Lx[i] * Hx - x1, 2) + pow(Ly[i] * Hy - y1, 2) + pow(Lz[i] * Hz - z1, 2);
                zu_GS[i][ib][ik - NK_s] = exp(-0.5 * r2);
            }
        }
    }
}

int main() {
    // Example initialization of global variables
    NK_s = 1;
    NK_e = 2;
    NB = 2;
    NL = 3;
    aLx = 1.0;
    aLy = 2.0;
    aLz = 3.0;
    Hx = 0.1;
    Hy = 0.2;
    Hz = 0.3;
    Lx = {1.0, 2.0, 3.0};
    Ly = {4.0, 5.0, 6.0};
    Lz = {7.0, 8.0, 9.0};
    zu_GS.resize(NL, std::vector<std::vector<double>>(NB, std::vector<double>(NK_e - NK_s + 1)));

    // Call the function
    init_wf();

    // Example output
    for (int i = 0; i < NL; ++i) {
        for (int ib = 0; ib < NB; ++ib) {
            for (int ik = NK_s; ik <= NK_e; ++ik) {
                std::cout << "zu_GS[" << i << "][" << ib << "][" << ik - NK_s << "] = " << zu_GS[i][ib][ik - NK_s] << std::endl;
            }
        }
    }

    return 0;
}