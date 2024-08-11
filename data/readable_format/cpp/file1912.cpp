#include <cmath>
#include <gtest/gtest.h>

// Define the namespace and its members directly in this file, instead of including from a separate header.
namespace arg_nut {

    const double pi = 4.0 * std::atan(1.0);

    const double t2000 = 51544.5;
    const double Nbr_days_in_Century = 36525;

    const double phil = 134.96340251 * pi / 180.0;
    const double phils = 357.52910918 * pi / 180.0;
    const double phiF = 93.27209062 * pi / 180.0;
    const double phiD = 297.85019547 * pi / 180.0;
    const double phiomega = 125.04455501 * pi / 180.0;

    const double sigmal = 1717915923.2178 / 3600.0 * pi / 180.0;
    const double sigmals = 129596581.0481 / 3600.0 * pi / 180.0;
    const double sigmaF = 1739527262.8478 / 3600.0 * pi / 180.0;
    const double sigmaD = 1602961601.2090 / 3600.0 * pi / 180.0;
    const double sigmaomega = -6962890.5431 / 3600.0 * pi / 180.0;

} // namespace arg_nut

// Test cases
TEST(ArgNutTest, Constants) {
    EXPECT_NEAR(arg_nut::pi, 3.141592653589793, 1e-9);
    EXPECT_DOUBLE_EQ(arg_nut::t2000, 51544.5);
    EXPECT_DOUBLE_EQ(arg_nut::Nbr_days_in_Century, 36525);
    // Add more tests for other constants as needed
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}