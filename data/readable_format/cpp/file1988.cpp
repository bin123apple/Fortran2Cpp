#include <iostream>

// Function definition
int i4_bit_hi1(int n) {
    if (n <= 0) {
        return 0;
    }
    int bit = 0;
    int i = n;
    while (i > 0) {
        bit += 1;
        i = i / 2; // Right shift the bits of i
    }
    return bit;
}

int main() {
    // Array of test values
    int test_vals[] = {0, 1, 2, 3, 1024};
    int num_tests = sizeof(test_vals) / sizeof(test_vals[0]);
    int result;

    // Loop through test values, call i4_bit_hi1, and print the result
    for (int i = 0; i < num_tests; ++i) {
        result = i4_bit_hi1(test_vals[i]);
        std::cout << "i4_bit_hi1(" << test_vals[i] << ") = " << result << std::endl;
    }

    return 0;
}