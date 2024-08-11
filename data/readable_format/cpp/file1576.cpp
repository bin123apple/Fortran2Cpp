#include <iostream>
#include <vector>
#include <numeric>

class MEANFLUXES__genmod {
public:
    static double MEANFLUXES(const std::vector<double>& fluxes) {
        if(fluxes.empty()) return 0.0; // Handle empty vector case
        double sum = std::accumulate(fluxes.begin(), fluxes.end(), 0.0);
        return sum / fluxes.size();
    }
};

// Simple test function
void testMeanFluxes() {
    std::vector<double> fluxes = {1.0, 2.0, 3.0, 4.0};
    double expectedMean = 2.5;
    double calculatedMean = MEANFLUXES__genmod::MEANFLUXES(fluxes);
    
    if(calculatedMean == expectedMean) {
        std::cout << "Test passed: Mean is " << calculatedMean << std::endl;
    } else {
        std::cout << "Test failed: Expected mean " << expectedMean << ", but got " << calculatedMean << std::endl;
    }
}

int main() {
    testMeanFluxes();
    return 0;
}