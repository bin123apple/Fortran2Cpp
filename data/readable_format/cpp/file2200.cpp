#include <iostream>
#include <array>

int main() {
    // Declare a 2D array with dimensions 16x16
    std::array<std::array<float, 16>, 16> a2;

    // Initialize array elements to 0
    for(int j = 0; j < 16; ++j) {
        for(int i = 0; i < 16; ++i) {
            a2[i][j] = 0.0f;
        }
    }

    // Print "PASS"
    std::cout << "PASS" << std::endl;

    return 0;
}