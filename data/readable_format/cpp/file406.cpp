#include <iostream>
#include <array>
#include <cmath> // For fabs (floating-point absolute value)

// Assuming kind_rb maps to double in C++
using rb = double;

// Simple manual test framework substitute
#define ASSERT_EQ(val1, val2) if ((val1) != (val2)) std::cerr << "FAIL: " << #val1 << " != " << #val2 << " at " << __LINE__ << std::endl; else std::cout << "PASS: " << #val1 << " == " << #val2 << std::endl;
#define ASSERT_NEAR(val1, val2, abs_error) if (std::fabs((val1) - (val2)) > (abs_error)) std::cerr << "FAIL: " << #val1 << " not within " << #abs_error << " of " << #val2 << " at " << __LINE__ << std::endl; else std::cout << "PASS: " << #val1 << " near " << #val2 << std::endl;

class rrlw_kg02 {
public:
    std::array<rb, 10> test_array;

    void fill_array() {
        for (int i = 0; i < 10; ++i) {
            test_array[i] = static_cast<rb>(i + 1);
        }
    }
};

void test_fill_array() {
    rrlw_kg02 obj;
    obj.fill_array();

    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(obj.test_array[i], static_cast<rb>(i + 1));
    }
}

int main() {
    test_fill_array();
    // You can add more test functions and call them here.
    return 0;
}