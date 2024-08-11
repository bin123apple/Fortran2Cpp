#include <iostream>
#include <array>

// Define the x_dot function directly in this file
std::array<float, 4> x_dot(float kon_1, float koff_1, float kon_2, float koff_2,
                           float f_plus, float g_minus, float g_plus, float Ca,
                           const std::array<float, 4>& x) {
    std::array<float, 4> f;

    f[0] = -kon_1 * Ca * x[0] + koff_1 * x[1] + g_minus * x[3];
    f[1] =  kon_1 * Ca * x[0] - (koff_1 + f_plus) * x[1] + g_plus * x[2];
    f[2] =  f_plus * x[1] - (g_plus + koff_2) * x[2] + kon_2 * Ca * x[3];
    f[3] =  koff_2 * x[2] - (g_minus + kon_2 * Ca) * x[3];

    return f;
}

// Main function to test the x_dot function
int main() {
    std::array<float, 4> x = {0.1f, 0.2f, 0.3f, 0.4f};
    float kon_1 = 1.0f, koff_1 = 2.0f, kon_2 = 1.5f, koff_2 = 2.5f;
    float f_plus = 0.5f, g_minus = 0.2f, g_plus = 0.3f, Ca = 1.0f;

    auto result = x_dot(kon_1, koff_1, kon_2, koff_2, f_plus, g_minus, g_plus, Ca, x);

    // Print the result to verify correctness
    std::cout << "Results: ";
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}