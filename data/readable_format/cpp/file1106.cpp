#include <iostream>
#include <array>
#include <numeric>

// Define the drotat function directly in this file
void drotat(int NI, const std::array<double, 3>& XI, const std::array<double, 3>& XJ,
            std::array<double, 10>& E1B, double& ENUC, double RIJ) {
    ENUC = std::accumulate(XI.begin(), XI.end(), 0.0) + 
           std::accumulate(XJ.begin(), XJ.end(), 0.0);
    E1B.fill(10 * RIJ);
}

// Main function to test the drotat function
int main() {
    std::array<double, 3> XI{{1.0, 2.0, 3.0}};
    std::array<double, 3> XJ{{4.0, 5.0, 6.0}};
    std::array<double, 10> E1B;
    double ENUC;
    double RIJ = 2.0;

    drotat(3, XI, XJ, E1B, ENUC, RIJ);

    std::cout << "Test ENUC: " << ENUC << " (Expected: 21.0)" << std::endl;
    for (int i = 0; i < E1B.size(); ++i) {
        std::cout << "E1B[" << i << "]: " << E1B[i] << " (Expected: 20.0)" << std::endl;
    }

    return 0;
}