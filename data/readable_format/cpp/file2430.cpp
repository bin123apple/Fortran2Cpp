#include <cmath>

double RL(double Q) {
    double P = std::pow(Q, 1.0/3.0);
    double RL = 0.49 * P * P / (0.6 * P * P + std::log(1.0 + P));
    return RL;
}

int main() {
    double Q = 8.0; // Example input
    double result = RL(Q);
    // Print the result to see the output
    std::cout << "RL(" << Q << ") = " << result << std::endl;
    return 0;
}