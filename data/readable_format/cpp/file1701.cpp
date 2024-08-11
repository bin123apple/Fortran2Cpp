#include <iostream>
#include <vector>
#include <complex>
#include <cmath> // For std::abs

// Function to check if two floating-point numbers are "close enough"
bool approxEqual(float a, float b, float epsilon = 0.001f) {
    return std::abs(a - b) < epsilon;
}

int main() {
    // Correctly setup test data with nested vectors
    std::vector<std::vector<std::vector<int>>> intVla(11, std::vector<std::vector<int>>(22, std::vector<int>(33, 1)));
    std::vector<std::vector<std::vector<float>>> realVla(11, std::vector<std::vector<float>>(22, std::vector<float>(33, 3.14f)));
    std::vector<std::vector<std::vector<std::complex<float>>>> complexVla(11, std::vector<std::vector<std::complex<float>>>(22, std::vector<std::complex<float>>(33, std::complex<float>(2.0, -3.0))));
    std::vector<std::vector<std::vector<bool>>> logicalVla(11, std::vector<std::vector<bool>>(22, std::vector<bool>(33, true)));
    std::vector<std::vector<std::vector<char>>> charactervla(11, std::vector<std::vector<char>>(22, std::vector<char>(33, 'K')));

    // Specific assignments
    intVla[4][4][4] = 42;
    realVla[4][4][4] = 4.13f;
    complexVla[4][4][4] = std::complex<float>(-3.0, 2.0);
    logicalVla[4][4][4] = false;
    charactervla[4][4][4] = 'X';

    // Assertions
    if (intVla[4][4][4] != 42) std::cerr << "Failed: intVla incorrect value." << std::endl;
    if (!approxEqual(realVla[4][4][4], 4.13f)) std::cerr << "Failed: realVla incorrect value." << std::endl;
    if (complexVla[4][4][4] != std::complex<float>(-3.0, 2.0)) std::cerr << "Failed: complexVla incorrect value." << std::endl;
    if (logicalVla[4][4][4] != false) std::cerr << "Failed: logicalVla incorrect value." << std::endl;
    if (charactervla[4][4][4] != 'X') std::cerr << "Failed: charactervla incorrect value." << std::endl;

    std::cout << "All tests passed." << std::endl;

    return 0;
}