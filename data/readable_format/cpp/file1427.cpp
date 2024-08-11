#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric> // Include for std::inner_product

void morse(const std::vector<double>& X, std::vector<double>& V, double& EMORSE, 
           int natoms, double rho, double R0, double A, 
           bool periodic, const std::vector<double>& boxvec, 
           bool use_cutoff, double rcut) {
    std::vector<double> iboxvec(3), dx(3);
    double dist, R, dummy, xmul2, eshift = 0.0;
    
    if (periodic) {
        for (int i = 0; i < 3; ++i) {
            iboxvec[i] = 1.0 / boxvec[i];
        }
    }
    
    if (use_cutoff) {
        eshift = std::pow(1.0 - std::exp(rho * (R0 - rcut)), 2) - 1.0;
    }
    
    std::fill(V.begin(), V.end(), 0.0);
    EMORSE = 0.0;
    
    for (int J1 = 0; J1 < natoms; ++J1) {
        int J3 = 3 * J1;
        
        for (int J2 = J1 + 1; J2 < natoms; ++J2) {
            int J4 = 3 * J2;
            for (int k = 0; k < 3; ++k) {
                dx[k] = X[J3 + k] - X[J4 + k];
            }
            
            if (periodic) {
                for (int k = 0; k < 3; ++k) {
                    dx[k] -= boxvec[k] * round(dx[k] * iboxvec[k]);
                }
            }
            
            dist = std::max(std::sqrt(std::inner_product(dx.begin(), dx.end(), dx.begin(), 0.0)), 1e-5);
            
            if (use_cutoff && dist >= rcut) continue;
            
            R = std::exp(rho * R0 - rho * dist);
            dummy = R * (R - 2.0);
            EMORSE += dummy - eshift;
            
            if (true) { // Assuming gtest is always true for this example
                xmul2 = rho * 2.0 * R * (R - 1.0) / dist * A;
                for (int k = 0; k < 3; ++k) {
                    V[J3 + k] -= xmul2 * dx[k];
                    V[J4 + k] += xmul2 * dx[k];
                }
            }
        }
    }
    
    EMORSE *= A;
}

int main() {
    const int natoms = 2;
    std::vector<double> X = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
    std::vector<double> V(3*natoms);
    double EMORSE;
    double rho = 1.0, R0 = 1.0, A = 1.0, rcut = 2.5;
    std::vector<double> boxvec = {10.0, 10.0, 10.0};
    bool periodic = false, use_cutoff = true;

    morse(X, V, EMORSE, natoms, rho, R0, A, periodic, boxvec, use_cutoff, rcut);

    std::cout << "EMORSE: " << EMORSE << std::endl;
    std::cout << "Forces: ";
    for (auto& v : V) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}