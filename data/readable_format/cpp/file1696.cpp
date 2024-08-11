#include <gtest/gtest.h>
#include <array>

std::array<std::array<int, 10>, 10> initialize_and_manipulate_array(bool manipulate = true) {
    const int n = 10, k = 3-1; // Adjusting k for zero-based indexing
    std::array<std::array<int, n>, n> y; // 2D array
    std::array<int, n> res1, res2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            y[i][j] = n * (i + 1) + (j + 1);
        }
    }

    res2 = y[k];
    if (manipulate) {
        for (int j = 3; j < n; ++j) {
            y[k][j] = y[k][j - 1];
        }
        y[k][2] = 0;
        res1 = y[k];

        y[k] = res2;
        for (int j = 0; j < n - 3; ++j) {
            y[k][n - 1 - j] = y[k][n - 2 - j];
        }
        y[k][2] = 0;
        res2 = y[k];
    }

    return y; // Returning the manipulated array for testing
}

TEST(Prgm3Test, ArrayManipulationTest) {
    auto y = initialize_and_manipulate_array();
    const int n = 10, k = 3-1;
    std::array<int, n> expected_res2 = {31, 32, 0, 33, 34, 35, 36, 37, 38, 39}; // Correct expected result after manipulation
    
    for (int j = 0; j < n; ++j) {
        EXPECT_EQ(y[k][j], expected_res2[j]) << "Arrays differ at index " << j;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}