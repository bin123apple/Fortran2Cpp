#include <iostream>
#include <iomanip>
#include <cmath>

const int nskdim = 2; // Adjust based on your specific scenario
const double zero = 0.0;

// Define the formrt function directly in this file
void formrt(const double skew[], double rot[3][3]) {
    double sina = std::sin(skew[0]);
    double cosa = std::cos(skew[0]);
    double sinb = std::sin(skew[1]);
    double cosb = std::cos(skew[1]);

    rot[0][0] = cosa * cosb;
    rot[1][0] = sina * cosb;
    rot[2][0] = -sinb;
    rot[0][1] = -sina;
    rot[1][1] = cosa;
    rot[2][1] = zero;
    rot[0][2] = cosa * sinb;
    rot[1][2] = sina * sinb;
    rot[2][2] = cosb;
}

// Main function to demonstrate the usage of formrt
int main() {
    double skew[nskdim] = {0.5, 0.6}; // Example skew values
    double rot[3][3];

    // Call the formrt function with skew as input and rot as output
    formrt(skew, rot);

    std::cout << "Rotation Matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << std::fixed << std::setprecision(5) << rot[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}