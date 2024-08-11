#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

// Assuming the pseudopotential parameters as constants for this example
const std::vector<double> parloc = {1.0, 2.0, 3.0, 4.0}; // Mock values
const std::vector<double> Zps = {1.0}; // Mock value
const std::vector<double> Rcloc = {1.0}; // Mock value

void init_ps_local_gth(double Va, int NMGL, int ielm, const std::vector<double>& GG, std::vector<double>& vqlg) {
    const double pi = acos(-1.0);
    const double constValue = 1.0 / std::abs(Va);
    double rloc, C1, C2, C3, C4, G, v;
    
    vqlg.assign(NMGL, 0.0); // Initialize vqlg with 0s

    rloc = Rcloc[ielm - 1]; // Adjusted for 0-based indexing
    C1 = parloc[0]; // Adjusted for example
    C2 = parloc[1]; // Adjusted for example
    C3 = parloc[2]; // Adjusted for example
    C4 = parloc[3]; // Adjusted for example

    vqlg[0] = constValue * ( 2.0 * pi * Zps[ielm - 1] * pow(rloc, 2) + sqrt(pow(2.0 * pi, 3)) * pow(rloc, 3) * ( C1 + C2 * 3.0 + C3 * 15.0 + C4 * 105.0 ) );

    for (int ig = 1; ig < NMGL; ++ig) {
        G = sqrt( GG[ig] );

        v = -4.0 * pi * Zps[ielm - 1] * exp(-0.5 * pow(G * rloc, 2)) / pow(G, 2);

        v += sqrt(pow(2.0 * pi, 3)) * pow(rloc, 3) * exp(-0.5 * pow(rloc * G, 2)) 
           * ( C1 
             + C2 * (3.0 - pow(rloc * G, 2)) 
             + C3 * (15.0 - 10.0 * pow(rloc * G, 2) + pow(rloc * G, 4)) 
             + C4 * (105.0 - 105.0 * pow(rloc * G, 2) + 21.0 * pow(rloc * G, 4) - pow(rloc * G, 6)) );

        vqlg[ig] = constValue * v;
    }
}

int main() {
    // Example usage and simple check
    double Va = 1.0;
    int NMGL = 5;
    int ielm = 1;
    std::vector<double> GG = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> vqlg(NMGL);

    init_ps_local_gth(Va, NMGL, ielm, GG, vqlg);

    // Simple test - print the results for manual verification
    for (int i = 0; i < NMGL; ++i) {
        std::cout << "vqlg[" << i << "] = " << vqlg[i] << std::endl;
    }

    // Here you could add more sophisticated checks or assertions
    // For a real test, you would compare vqlg to expected values
    // assert(vqlg[0] == expected_value); // Example assertion

    return 0;
}