#include <iostream>

void iau_EPJ2JD(double EPJ, double& DJM0, double& DJM) {
    DJM0 = 2400000.5;
    DJM = 51544.5 + (EPJ - 2000.0) * 365.25;
}

int main() {
    double EPJ; // Input: Epoch
    double DJM0, DJM; // Output: Julian Day Number parts
    
    // Example usage
    EPJ = 2023.0; // Example Epoch year
    iau_EPJ2JD(EPJ, DJM0, DJM);
    
    std::cout << "DJM0: " << DJM0 << ", DJM: " << DJM << std::endl;
    
    return 0;
}