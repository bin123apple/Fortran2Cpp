#include <gtest/gtest.h>
#include <vector>

// Assuming the i2torl function is defined as follows
void i2torl(const std::vector<std::vector<short>>& iin, int npix, int nlin, float scale, float zero, short inval, float rinval, std::vector<std::vector<float>>& rout) {
    for (int lin = 0; lin < nlin; ++lin) {
        for (int pix = 0; pix < npix; ++pix) {
            if (iin[pix][lin] != inval) {
                rout[pix][lin] = scale * iin[pix][lin] + zero;
            } else {
                rout[pix][lin] = rinval;
            }
        }
    }
}

// Unit test for the i2torl function
TEST(I2TorlTest, HandlesBasicInput) {
    std::vector<std::vector<short>> iin = {{1, -1}, {0, 2}};
    std::vector<std::vector<float>> rout(2, std::vector<float>(2, 0));
    int npix = 2, nlin = 2;
    float scale = 2.0, zero = 1.0, rinval = -1.0;
    short inval = 0;

    i2torl(iin, npix, nlin, scale, zero, inval, rinval, rout);

    EXPECT_FLOAT_EQ(rout[0][0], 3.0); // Expect scale * 1 + zero = 3
    EXPECT_FLOAT_EQ(rout[1][0], -1.0); // Expect inval substitution
    EXPECT_FLOAT_EQ(rout[0][1], rinval); // Adjusted based on the input condition, expecting rinval
    EXPECT_FLOAT_EQ(rout[1][1], 5.0); // Expect scale * 2 + zero = 5
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}