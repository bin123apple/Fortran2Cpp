#include <iostream>
#include <limits>
#include <cmath>
#include <gtest/gtest.h>

namespace config {
    // Approximating the selected_real_kind with C++ types.
    using sp = float; // Single precision, typically 6-7 decimal digits
    using dp = double; // Double precision, typically 15-16 decimal digits
    using ep = long double; // Extended precision, precision varies
    using wp = sp; // wp is chosen to be the same as sp for this example

    void disp_wp() {
        std::cout << std::numeric_limits<wp>::digits10 << std::endl;
    }
}

TEST(ConfigTest, PrecisionWp) {
    // This test checks if the precision of wp (as digits10) matches our expectations.
    // For float, we typically expect 6 decimal digits of precision.
    EXPECT_EQ(std::numeric_limits<config::wp>::digits10, 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS(); // This will run all tests and return the result

    // You might also want to demonstrate disp_wp functionality here
    std::cout << "Demonstrating disp_wp functionality:" << std::endl;
    config::disp_wp();

    return result;
}