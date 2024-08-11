#include <gtest/gtest.h>
#include <vector>

// Assuming these are the dimensions you want for the test
const int dimx = 8;
const int dimy = 6;

// Declaration of the filltab function
void filltab(std::vector<std::vector<float>>& ftab) {
    for (int x = 0; x < dimx; ++x) {
        for (int y = 0; y < dimy; ++y) {
            ftab[x][y] = (x + 1) * 100 + (y + 1); // Adjusted for 0-based indexing
        }
    }
}

// Test fixture for setup and teardown
class ArrayTest : public ::testing::Test {
protected:
    std::vector<std::vector<float>> ftab;

    void SetUp() override {
        ftab.resize(dimx, std::vector<float>(dimy));
        filltab(ftab);
    }
};

// Test the filltab function
TEST_F(ArrayTest, FillTabCorrectlyFillsArray) {
    for (int x = 0; x < dimx; ++x) {
        for (int y = 0; y < dimy; ++y) {
            EXPECT_EQ(ftab[x][y], (x + 1) * 100 + (y + 1));
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}