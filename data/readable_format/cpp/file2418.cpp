#include <vector>
#include <gtest/gtest.h>

// Assuming vast_kind_param::DOUBLE is equivalent to double in C++
namespace vast_kind_param {
    using DOUBLE = double;
}

// C++ version of the Fortran subroutine
void hplusf(std::vector<std::vector<vast_kind_param::DOUBLE>>& F, const std::vector<std::vector<vast_kind_param::DOUBLE>>& H, int NORBS) {
    for (int i = 0; i < NORBS; ++i) {
        for (int j = 0; j < NORBS; ++j) {
            F[i][j] += H[i][j];
        }
    }
}

// Test case for the hplusf function
TEST(HplusfTest, BasicTest) {
    int NORBS = 3;
    std::vector<std::vector<vast_kind_param::DOUBLE>> F(NORBS, std::vector<vast_kind_param::DOUBLE>(NORBS, 0.0));
    std::vector<std::vector<vast_kind_param::DOUBLE>> H = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    // Expected result
    std::vector<std::vector<vast_kind_param::DOUBLE>> expected_F = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    // Call the function
    hplusf(F, H, NORBS);

    // Check the results
    for (int i = 0; i < NORBS; ++i) {
        for (int j = 0; j < NORBS; ++j) {
            EXPECT_DOUBLE_EQ(F[i][j], expected_F[i][j]);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}