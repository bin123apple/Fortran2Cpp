#include <gtest/gtest.h>
#include <vector>

// Directly include the CSLSTPTR function implementation
int CSLSTPTR(int LPL, int NB, const std::vector<int>& LIST, const std::vector<int>& LPTR) {
    int LP = LPTR[LPL - 1]; // Adjust for 0-based indexing
    int ND;

    do {
        ND = LIST[LP - 1]; // Adjust for 0-based indexing
        if (ND == NB) {
            break;
        }
        LP = LPTR[LP - 1]; // Adjust for 0-based indexing
    } while (LP != LPL);

    return LP;
}

// Unit test for the CSLSTPTR function
TEST(CSLSTPTRTest, FindsCorrectNode) {
    std::vector<int> LIST = {1, 3, 5, 7, 9};
    std::vector<int> LPTR = {2, 3, 4, 5, 1};

    EXPECT_EQ(CSLSTPTR(1, 7, LIST, LPTR), 4) << "Should find node with value 7 starting from position 1";
    EXPECT_EQ(CSLSTPTR(3, 1, LIST, LPTR), 1) << "Should find node with value 1 starting from position 3";
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}