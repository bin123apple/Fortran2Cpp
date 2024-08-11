#include <iostream>
#include <vector>
#include <cmath> // For std::fabs

// The translated calcpel function
void calcPel(int ne, std::vector<std::vector<double>>& vel, const std::vector<double>& b, int nef) {
    for (int i = 0; i < ne; ++i) {
        vel[i][4] += b[i];
    }
}

// A simple function to test the calcPel function
void testCalcPel() {
    const int ne = 3;
    const int nef = 6;
    std::vector<std::vector<double>> vel(ne, std::vector<double>(nef, 0.0));
    std::vector<double> b(ne);

    // Initialize test data
    for (int i = 0; i < ne; ++i) {
        for (int j = 0; j < nef; ++j) {
            vel[i][j] = static_cast<double>(j);
        }
        b[i] = static_cast<double>(i + 1);
    }

    // Call the function under test
    calcPel(ne, vel, b, nef);

    // Check the results
    bool success = true;
    for (int i = 0; i < ne; ++i) {
        double expected = 4.0 + static_cast<double>(i + 1);
        if (std::fabs(vel[i][4] - expected) > 1e-6) {
            std::cerr << "Test failed for vel[" << i << "][4], expected " << expected << ", got " << vel[i][4] << std::endl;
            success = false;
        }
    }

    if (success) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    // Run the test
    testCalcPel();
    return 0;
}