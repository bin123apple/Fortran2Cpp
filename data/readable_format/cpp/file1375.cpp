#include <cstdint>
#include <cstring>
#include <gtest/gtest.h>

// Definitions of the global variables
int32_t myF90Int = 0;
float myF90Real = 0.0f;
int32_t c2 = 0;
int32_t c3 = 0;
int32_t c4 = 0;
int32_t myF90Array3D[18][5][10] = {}; // Adjusted to match C++ indexing and dimensions
int32_t myF90Array2D[3][2] = {};

extern "C" {
    // Ensures name mangling is avoided for interoperability
    void changeF90Globals() {
        myF90Int += 1;
        myF90Real *= 3.0f;
        c2 *= 2;
        c3 += 3;
        c4 /= 2;
        myF90Array3D[4][2][2] += 1; // Adjusting indices for 0-based indexing
        myF90Array2D[2][1] += 1;
    }
}

// Unit tests
class BindCVarsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize or reset global variables before each test
        myF90Int = 0;
        myF90Real = 1.0f;
        c2 = 1;
        c3 = 1;
        c4 = 4;
        std::memset(myF90Array3D, 0, sizeof(myF90Array3D));
        std::memset(myF90Array2D, 0, sizeof(myF90Array2D));

        // Call the function to modify the globals
        changeF90Globals();
    }
};

TEST_F(BindCVarsTest, TestChanges) {
    EXPECT_EQ(myF90Int, 1);
    EXPECT_FLOAT_EQ(myF90Real, 3.0);
    EXPECT_EQ(c2, 2);
    EXPECT_EQ(c3, 4);
    EXPECT_EQ(c4, 2);
    EXPECT_EQ(myF90Array3D[4][2][2], 1); // Adjusted for 0-based indexing
    EXPECT_EQ(myF90Array2D[2][1], 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}