#include <gtest/gtest.h>
#include <cmath>
#include <cstdlib>

// Define the TestMod class directly in this file
class TestMod {
public:
    static float add(int i, int j, int k) {
        return static_cast<float>(i + j + k) + 1.0f;
    }

    static float add2(int i, int j, int k) {
        return static_cast<float>(i + j + k);
    }

    static void check_err(float a[2][2], float s) {
        float sum = 0.0f;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                sum += a[i][j];
            }
        }
        if (std::abs(sum - s) > 1e-5) {
            exit(1);
        }
    }
};

// Unit tests for TestMod
TEST(TestModTest, AddFunction) {
    EXPECT_FLOAT_EQ(TestMod::add(1, 2, 3), 7.0f);
}

TEST(TestModTest, Add2Function) {
    EXPECT_FLOAT_EQ(TestMod::add2(1, 2, 3), 6.0f);
}

TEST(TestModTest, CheckErrFunction) {
    float a[2][2] = {{6.0f, 6.0f}, {6.0f, 6.0f}};
    // Since check_err uses exit on failure, if it returns, the test is considered to pass.
    TestMod::check_err(a, 24.0f);
    SUCCEED(); // This line is expected to be reached without exiting the program.
}

// Main function that runs the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}