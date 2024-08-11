#include <iostream>
#include <algorithm>
#include <cmath>

// Mocking external linkage or definitions for these values and functions
double rytoev = 13.605693009; // Example value
double ef = 10.0;
double degauss = 0.0;
int nelec = 10;
bool noncolin = false;

void compute_eref_band(const double* e, int nbnd, double& eref, bool& print_eref) {
    print_eref = false;
    eref = -1e20;
    if (degauss > 0.0) {
        eref = ef * rytoev;
        print_eref = true;
    } else {
        int nband_occ = std::round(nelec / 2.0);
        if (noncolin) nband_occ *= 2;
        for (int ibnd = 0; ibnd < nband_occ; ++ibnd) {
            eref = std::max(eref, e[ibnd]);
        }
    }
}

int main() {
    const int nbnd = 5;
    double e[nbnd] = {5.0, 10.0, 15.0, 20.0, 25.0};
    double eref;
    bool print_eref;

    compute_eref_band(e, nbnd, eref, print_eref);

    std::cout << "Computed eref: " << eref << std::endl;
    std::cout << "Should print eref: " << print_eref << std::endl;

    return 0;
}