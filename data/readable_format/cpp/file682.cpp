#include <iostream>
#include <cmath>
#include <iomanip> // For setting precision of the output

// Assume recCell code is in this same file for simplicity
void recCell(float cell[6], float rCell[6]) {
    float casq, cbsq, ccsq, cba, albtgm, volume, xnum, den, temp;

    casq = std::pow(std::cos(cell[3]), 2);
    cbsq = std::pow(std::cos(cell[4]), 2);
    ccsq = std::pow(std::cos(cell[5]), 2);
    cba = cell[0] * cell[1] * cell[2];
    albtgm = std::cos(cell[3]) * std::cos(cell[4]) * std::cos(cell[5]);
    volume = cba * (std::sqrt(1.0 - casq - cbsq - ccsq + 2.0 * albtgm));

    rCell[0] = cell[1] * cell[2] * std::sin(cell[3]) / volume;
    rCell[1] = cell[0] * cell[2] * std::sin(cell[4]) / volume;
    rCell[2] = cell[0] * cell[1] * std::sin(cell[5]) / volume;

    xnum = std::cos(cell[4]) * std::cos(cell[5]) - std::cos(cell[3]);
    den = std::sin(cell[4]) * std::sin(cell[5]);
    temp = xnum / den;
    rCell[3] = std::acos(temp);

    xnum = std::cos(cell[3]) * std::cos(cell[5]) - std::cos(cell[4]);
    den = std::sin(cell[3]) * std::sin(cell[5]);
    temp = xnum / den;
    rCell[4] = std::acos(temp);

    xnum = std::cos(cell[3]) * std::cos(cell[4]) - std::cos(cell[5]);
    den = std::sin(cell[3]) * std::sin(cell[4]);
    temp = xnum / den;
    rCell[5] = std::acos(temp);
}

// Main function to test the recCell function
int main() {
    float cell[6] = {90.0, 90.0, 90.0, 1.57079632679, 1.57079632679, 1.57079632679}; // Example values
    float rCell[6];

    // Call recCell with the test data
    recCell(cell, rCell);

    // Output the results
    std::cout << std::fixed << std::setprecision(5); // Set precision for better readability
    std::cout << "rCell values:";
    for (int i = 0; i < 6; i++) {
        std::cout << " " << rCell[i];
    }

    std::cout << std::endl; // Ensures there's a newline at the end of the output

    return 0;
}