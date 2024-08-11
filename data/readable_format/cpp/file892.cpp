#include <iostream>
#include <vector>
#include <cassert> // For assert()
#include <cmath>    // For std::pow()

// Function to calculate factorial
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to generate the sequence of digits of a number
std::vector<int> digit_sequence(int n) {
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

// Solver function implementing the logic to find and sum the special numbers
void solver() {
    int max_digit = 7; // Arbitrary choice for max digits
    int p = factorial(9);
    int n = 1;
    while (p * n > std::pow(10, n - 1)) {
        n = n + 1;
    }
    max_digit = n;

    int sum = 0;
    for (int i = 10; i <= p * max_digit; ++i) { // Starting from 10, as single-digit numbers are not considered
        auto digits = digit_sequence(i);
        int digit_sum = 0;
        for (auto digit : digits) {
            digit_sum += factorial(digit);
        }
        if (digit_sum == i) {
            sum += i;
            std::cout << i << std::endl;
        }
    }
    std::cout << "Result = " << sum << std::endl;
}

// Test function for factorial
void test_factorial() {
    assert(factorial(5) == 120);
    std::cout << "Factorial test passed." << std::endl;
}

// Test function for digit sequence
void test_digit_sequence() {
    auto seq = digit_sequence(145); // Modified to remove unnecessary parameter
    assert(seq.size() == 3 && seq[0] == 5 && seq[1] == 4 && seq[2] == 1);
    std::cout << "Digit sequence test passed." << std::endl;
}

int main() {
    test_factorial();
    test_digit_sequence();
    solver();
    return 0;
}