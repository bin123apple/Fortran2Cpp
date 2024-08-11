#include <iostream>

int main() {
    const int N = 10000;  // Example value for N
    int sum = 0;
    int total_sum = 0;

    // Emulate a "parallel" loop in a serial manner
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }

    total_sum = sum;

    std::cout << "Total Sum: " << total_sum << std::endl;

    // Check if the computed sum matches the expected result
    if (total_sum == (N * (N + 1)) / 2) {
        std::cout << "Test PASSED." << std::endl;
    } else {
        std::cout << "Test FAILED." << std::endl;
    }

    return 0;
}