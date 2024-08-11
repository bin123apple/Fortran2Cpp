#include <iostream>
#include <array>

// Assuming the existence of the namespace coe_I from previous context
namespace coe_I {

    // Declaration of coe function inside the namespace
    void coe(double X2, double Y2, double Z2, int NORBI, int NORBJ, std::array<double, 75>& C, double& R) {
        // Example functionality for the function
        R = X2 + Y2 + Z2;
        for(size_t i = 0; i < C.size(); i += 2) {
            C[i] = NORBI;
            if (i + 1 < C.size()) {
                C[i+1] = NORBJ;
            }
        }
    }

} // namespace coe_I

// Simple test function to verify the functionality of coe
void test_coe() {
    double X2 = 1.0, Y2 = 2.0, Z2 = 3.0;
    int NORBI = 4, NORBJ = 5;
    std::array<double, 75> C;
    double R = 0.0;

    coe_I::coe(X2, Y2, Z2, NORBI, NORBJ, C, R);

    // Simple checks to verify the functionality
    bool test_passed = true;

    if (R != 6.0) {
        std::cout << "Test failed for R calculation." << std::endl;
        test_passed = false;
    }

    for (size_t i = 0; i < C.size(); i += 2) {
        if (C[i] != NORBI || (i + 1 < C.size() && C[i+1] != NORBJ)) {
            std::cout << "Test failed for C array filling at index: " << i << std::endl;
            test_passed = false;
            break;
        }
    }

    if (test_passed) {
        std::cout << "All tests passed." << std::endl;
    }
}

int main() {
    test_coe();
    return 0;
}