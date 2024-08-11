#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <limits>

typedef double DP;

void entropy(const std::vector<DP>& f, DP temp, int nx, DP& ent) {
    const DP eps = 1.0e-10;
    ent = 0.0;
    
    for (int i = 0; i < nx; ++i) {
        DP fm = 0.5 * f[i];
        ent += fm * std::log(eps + fm) + (1.0 - fm) * std::log(eps + 1.0 - fm);
    }
    
    ent = -2.0 * temp * ent;
}

int main() {
    int nx = 5;
    std::vector<DP> f = {0.1, 0.2, 0.3, 0.4, 0.5};
    DP temp = 300.0;
    DP ent;
    
    entropy(f, temp, nx, ent);
    std::cout << "Entropy: " << ent << std::endl;

    return 0;
}