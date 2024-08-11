#include <gtest/gtest.h>

// Define the namespace and constants directly in this file
namespace corr_parms {
    constexpr int ilg = 3750;
    constexpr int jlg = 3750;
    constexpr int kz = 21;
    constexpr int ci = 1440;
    constexpr int cj = 720;
}

// Unit test code using Google Test
TEST(CorrParmsTest, Constants) {
    EXPECT_EQ(3750, corr_parms::ilg);
    EXPECT_EQ(3750, corr_parms::jlg);
    EXPECT_EQ(21, corr_parms::kz);
    EXPECT_EQ(1440, corr_parms::ci);
    EXPECT_EQ(720, corr_parms::cj);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}