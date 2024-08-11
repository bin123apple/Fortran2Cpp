#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

// Define the rect_norm function
void rect_norm(int ntpol, float xscal, float yscal, float zscal, 
               const std::vector<int>& lstpx, const std::vector<int>& lstpy, 
               const std::vector<int>& lstpz, std::vector<float>& bnorm) {
    
    float ilxyz = xscal * yscal * zscal * 0.125f;
    
    for (int n = 0; n < ntpol; ++n) {
        bnorm[n] = std::sqrt((2.0f * lstpx[n] + 1.0f) * 
                             (2.0f * lstpy[n] + 1.0f) * 
                             (2.0f * lstpz[n] + 1.0f) * ilxyz);
    }
}

int main() {
    std::vector<int> lstpx = {1, 2, 3};
    std::vector<int> lstpy = {2, 3, 4};
    std::vector<int> lstpz = {3, 4, 5};
    std::vector<float> bnorm(3); // Automatically initialized to 0.0f

    float xscal = 1.0f, yscal = 2.0f, zscal = 3.0f;

    // Call the function
    rect_norm(3, xscal, yscal, zscal, lstpx, lstpy, lstpz, bnorm);

    // Output the test results
    std::cout << "Test case results:" << std::endl;
    for (size_t i = 0; i < bnorm.size(); ++i) {
        std::cout << "bnorm[" << i << "] = " << bnorm[i] << std::endl;
        // Example assertion - here you would replace with actual checks
        assert(bnorm[i] > 0.0f); // Simple check to ensure values are computed
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}