#include <iostream>
#include <cmath>
#include <vector>

class RandomNumberGenerator {
public:
    RandomNumberGenerator() : RDM(31), RM1(0), RM2(0), IA1(1279), IC1(351762), M1(1664557),
                              IA2(2011), IC2(221592), M2(1048583), IA3(15091), IC3(6171), M3(29201),
                              IX1(0), IX2(0), IX3(0) {}

    void DRNSET(int ISEED) {
        IX1 = ISEED % M1;
        IX1 = (IA1 * IX1 + IC1) % M1;
        IX2 = IX1 % M2;
        IX1 = (IA1 * IX1 + IC1) % M1;
        IX3 = IX1 % M3;
        RM1 = 1.0 / static_cast<double>(M1);
        RM2 = 1.0 / static_cast<double>(M2);
        for (int J = 0; J < 31; ++J) {
            IX1 = (IA1 * IX1 + IC1) % M1;
            IX2 = (IA2 * IX2 + IC2) % M2;
            RDM[J] = (static_cast<double>(IX1) + static_cast<double>(IX2) * RM2) * RM1;
        }
    }

    double DRN(int& ISEED) {
        IX1 = (IA1 * IX1 + IC1) % M1;
        IX2 = (IA2 * IX2 + IC2) % M2;
        IX3 = (IA3 * IX3 + IC3) % M3;
        int J = 1 + (31 * IX3) / M3;
        double result = RDM[J - 1]; // Adjust for 0-based indexing
        RDM[J - 1] = (static_cast<double>(IX1) + static_cast<double>(IX2) * RM2) * RM1;

        ISEED = IX1;
        return result;
    }

private:
    std::vector<double> RDM;
    double RM1, RM2;
    int IA1, IC1, M1, IX1;
    int IA2, IC2, M2, IX2;
    int IA3, IC3, M3, IX3;
};

void testRandomNumberGenerator() {
    RandomNumberGenerator rng;
    int seed = 123456; // Example seed

    rng.DRNSET(seed);
    
    // Note: Fill in the expectedValues vector based on the output from the Fortran code for an accurate test
    std::vector<double> expectedValues = {/* Expected random values from Fortran output */};

    bool testPassed = true;
    for (size_t i = 0; i < expectedValues.size(); ++i) {
        double generated = rng.DRN(seed);
        if (std::fabs(generated - expectedValues[i]) > 1e-6) { // Allowing some floating point error
            std::cout << "Test failed at " << i + 1 << " Expected: " << expectedValues[i] << ", Got: " << generated << std::endl;
            testPassed = false;
        }
    }

    if (testPassed) {
        std::cout << "All tests passed!" << std::endl;
    }
}

int main() {
    testRandomNumberGenerator();
    return 0;
}