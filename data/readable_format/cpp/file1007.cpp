#include <iostream>
#include <vector>

// Function definition
void utemp_ccxlib(double* temp, int msecpt, int kstep, int kinc, double time[2], int node, double coords[3], std::vector<std::vector<double>>& vold, std::vector<int>& mi) {
    // Initialize the first element of `temp` to 293.0
    temp[0] = 293.0; // Note: In C++, array indexing starts at 0
}

// Example usage and a simple test
int main() {
    int msecpt = 1; // Number of temperature points
    double temp[msecpt]; // Temperature array
    int kstep = 1, kinc = 1, node = 1; // Simulation step parameters
    double time[2] = {0.0, 1.0}; // Time array
    double coords[3] = {0.0, 0.0, 0.0}; // Node coordinates
    std::vector<int> mi = {0, 5}; // Mesh information, adjust as needed
    std::vector<std::vector<double>> vold(mi[1] + 1, std::vector<double>(msecpt)); // Previous values, adjust dimensions as needed

    // Call the function
    utemp_ccxlib(temp, msecpt, kstep, kinc, time, node, coords, vold, mi);

    // Simple test to check if the first element of temp is correctly set
    if (temp[0] == 293.0) {
        std::cout << "Test passed: temp[0] is correctly set to 293." << std::endl;
    } else {
        std::cout << "Test failed: temp[0] is not correctly set." << std::endl;
    }

    return 0;
}