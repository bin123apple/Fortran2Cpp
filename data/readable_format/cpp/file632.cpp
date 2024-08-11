#include <cstdint>
#include <iostream>

int64_t i8_bit_hi1(int64_t n);

// Test function
void test_i8_bit_hi1(int64_t input, int64_t expected) {
    int64_t result = i8_bit_hi1(input);
    if (result == expected) {
        std::cout << "Test passed for input " << input << "." << std::endl;
    } else {
        std::cout << "Test failed for input " << input << ". Expected " << expected << ", got " << result << "." << std::endl;
    }
}

int main() {
    // Test 1: Test with 0, expecting 0
    test_i8_bit_hi1(0, 0);

    // Test 2: Test with 1, expecting 1
    test_i8_bit_hi1(1, 1);

    // Test 3: Test with 2, expecting 2
    test_i8_bit_hi1(2, 2);

    // Test 4: Test with 1023, expecting 10
    test_i8_bit_hi1(1023, 10);

    // Add more tests as needed

    return 0;
}

// Place the translated C++ function here
int64_t i8_bit_hi1(int64_t n) {
    int64_t bit = 0;
    int64_t i = n;

    while (i > 0) {
        bit++;
        i = i / 2;
    }

    return bit;
}