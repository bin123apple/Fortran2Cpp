#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

class Propagate {
public:
    using Complex = std::complex<double>;

    static void calculatePotential(std::vector<Complex>& V) {
        for (size_t i = 0; i < V.size(); ++i) {
            V[i] = Complex((i+1) * 0.01, -(i+1) * 0.01);
        }
    }
};

void testCalculatePotential() {
    std::vector<Propagate::Complex> V(100);
    Propagate::calculatePotential(V);
    
    bool passed = true;
    for (size_t i = 0; i < V.size(); ++i) {
        if (V[i] != Propagate::Complex((i+1) * 0.01, -(i+1) * 0.01)) {
            std::cerr << "Test failed at index " << i << ": Expected " 
                      << (i+1) * 0.01 << " got " << V[i].real() << std::endl;
            passed = false;
            break;
        }
    }
    
    if (passed) {
        std::cout << "Test calculatePotential passed." << std::endl;
    } else {
        std::cout << "Test calculatePotential failed." << std::endl;
    }
}

int main() {
    // Run the tests
    testCalculatePotential();
    
    return 0;
}