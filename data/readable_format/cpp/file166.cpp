#include <iostream>
#include <cmath>

// Global variables
bool use_gpu = false, noncolin = false, lspinorb = false, tqr = false, spline_ps = false;
int nat = 0, nspin = 1, nhm = 0, nsp = 0, nbetam = 0, nwfcm = 0, nqxq, nqx;
double cell_factor = 1.2, ecutrho = 20.0, qnorm = 1.0, dq = 0.1, ecutwfc = 15.0;
double lmaxq = 0.0, lmaxkb = 0.0, nh = 0.0;

void allocate_nlpot() {
    if (spline_ps && cell_factor <= 1.1) {
        cell_factor = 1.1;
    }
    
    nqxq = static_cast<int>(((std::sqrt(ecutrho) + qnorm) / dq + 4) * cell_factor);
    nqx = static_cast<int>((std::sqrt(ecutwfc) / dq + 4) * cell_factor);
}

int main() {
    allocate_nlpot();
    std::cout << "C++ Stdout: nqxq = " << nqxq << std::endl;
    std::cout << "C++ Stdout: nqx = " << nqx << std::endl;
    return 0;
}