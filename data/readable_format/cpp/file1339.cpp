#include <gtest/gtest.h>
#include <string>

// Definition of the Injection struct
struct Injection {
    // Double precision variables
    double RCM_injection = 0.0;
    double ZCM_injection = 0.0;
    double Rwidth_injection = 0.0;
    double Zwidth_injection = 0.0;
    double XCM_injection = 0.0;
    double YCM_injection = 0.0;
    double Xwidth_injection = 0.0;
    double Ywidth_injection = 0.0;
    double alpha0 = 0.0;
    double beta0 = 0.0;
    double V0 = 0.0;
    double devalpha = 0.0;
    double devbeta = 0.0;
    double devV = 0.0;

    // Character variables
    std::string inject_type_pos = "pointlike";
    std::string inject_type_vel = "stationary";

    // Logical variables
    bool inject_coord_cart = false;
    bool inject_coord_cyl = false;
    bool inject_coord_tilt = false;
    bool rand_seed = true;
};

// Test Fixture for Injection struct
class InjectionTest : public ::testing::Test {
protected:
    Injection injection; // Test fixture for the Injection struct
};

// Test case for Initialization
TEST_F(InjectionTest, Initialization) {
    // Test double initializations
    EXPECT_DOUBLE_EQ(0.0, injection.RCM_injection);
    EXPECT_DOUBLE_EQ(0.0, injection.ZCM_injection);
    EXPECT_DOUBLE_EQ(0.0, injection.alpha0);

    // Test string initializations
    EXPECT_EQ("pointlike", injection.inject_type_pos);
    EXPECT_EQ("stationary", injection.inject_type_vel);

    // Test boolean initializations
    EXPECT_FALSE(injection.inject_coord_cart);
    EXPECT_TRUE(injection.rand_seed);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}