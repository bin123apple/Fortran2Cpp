#include <iostream>
#include <array>
#include <cmath>

int main() {
    std::array<float, 3> y = {2.0f * 1, 2.0f * 2, 2.0f * 3}; // Initialize y array
    std::array<float, 4> z = {2.0f * 1, 2.0f * 2, 2.0f * 4, 2.0f * 3}; // Initialize z array

    // Check if any elements in y are not equal to [2., 4., 6.]
    for (int i = 0; i < y.size(); ++i) {
        if (std::abs(y[i] - std::array<float, 3>{2.f, 4.f, 6.f}[i]) > 0.001f) { // Using a small threshold for float comparison
            std::cerr << "Error: y array mismatch." << std::endl;
            return 1; // Exit with error code 1
        }
    }

    // Check if any elements in z are not equal to [2., 4., 8., 6.]
    for (int i = 0; i < z.size(); ++i) {
        if (std::abs(z[i] - std::array<float, 4>{2.f, 4.f, 8.f, 6.f}[i]) > 0.001f) { // Using a small threshold for float comparison
            std::cerr << "Error: z array mismatch." << std::endl;
            return 2; // Exit with error code 2
        }
    }

    return 0; // All checks passed, return 0
}