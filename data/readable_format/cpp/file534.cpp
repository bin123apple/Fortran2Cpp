#include <gtest/gtest.h>
#include <iostream>

// Define the GRMCUR function directly in this file
void GRMCUR(int& ICH, int& ICX, int& ICY) {
    static int STEP = 4; // Equivalent to SAVE STEP and DATA STEP /4/ in Fortran

    if (ICH == -1 || ICH == -28) {
        ICY += STEP;
    } else if (ICH == -2 || ICH == -22) {
        ICY -= STEP;
    } else if (ICH == -3 || ICH == -26) {
        ICX += STEP;
    } else if (ICH == -4 || ICH == -24) {
        ICX -= STEP;
    } else if (ICH == -27) {
        ICX -= STEP;
        ICY += STEP;
    } else if (ICH == -29) {
        ICX += STEP;
        ICY += STEP;
    } else if (ICH == -23) {
        ICX += STEP;
        ICY -= STEP;
    } else if (ICH == -21) {
        ICX -= STEP;
        ICY -= STEP;
    } else if (ICH == -11) {
        STEP = 1;
    } else if (ICH == -12) {
        STEP = 4;
    } else if (ICH == -13) {
        STEP = 16;
    } else if (ICH == -14) {
        STEP = 64;
    }
}

// Unit tests for the GRMCUR function
TEST(GRMCURTest, MovesICYUp) {
    int ICH = -1;
    int ICX = 10;
    int ICY = 20;
    GRMCUR(ICH, ICX, ICY);
    EXPECT_EQ(ICY, 24);
}

TEST(GRMCURTest, MovesICYDown) {
    int ICH = -2;
    int ICX = 10;
    int ICY = 20;
    GRMCUR(ICH, ICX, ICY);
    EXPECT_EQ(ICY, 16);
}

// Add more tests for different values of ICH...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}