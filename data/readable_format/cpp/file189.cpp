#include <cmath>
#include <gtest/gtest.h>

// Define the PhysConstants class directly in this file
class PhysConstants {
public:
    static constexpr double h = 6.626e-27;
    static constexpr double k = 1.38e-16;
    static constexpr double c = 2.99792458e10;
    static constexpr double e = 4.8032e-10;
    static constexpr double G = 6.67e-8;
    static constexpr double m = 9.10938188e-28;
    static constexpr double mp = 1.67262158e-24;
    static constexpr double pi = M_PI; // M_PI is from <cmath>, representing pi
    static constexpr double c2 = c * c;
    static constexpr double sigb = 5.6704e-5;
    static constexpr double msun = 1.998e33;
    static constexpr double sigt = 6.6523e-25;

    // Dummy member function
    static void physConstantsDummy() {
        // Does nothing
    }
};

// Unit tests
TEST(PhysConstantsTest, ConstantsCheck) {
    EXPECT_DOUBLE_EQ(PhysConstants::h, 6.626e-27);
    EXPECT_DOUBLE_EQ(PhysConstants::k, 1.38e-16);
    EXPECT_DOUBLE_EQ(PhysConstants::pi, M_PI);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}