#include <gtest/gtest.h>

// Function to be tested
int indxg2l(int indxglob, int nb, int iproc, int isrcproc, int nprocs) {
    return nb * ((indxglob - 1) / (nb * nprocs)) + (indxglob - 1) % nb + 1;
}

// Test cases
TEST(Indxg2lTest, TestCase1) {
    EXPECT_EQ(indxg2l(10, 4, 1, 0, 5), 2);
}

TEST(Indxg2lTest, TestCase2) {
    EXPECT_EQ(indxg2l(20, 4, 2, 0, 5), 4);
}

TEST(Indxg2lTest, TestCase3) {
    EXPECT_EQ(indxg2l(15, 3, 1, 0, 4), 6);
}

TEST(Indxg2lTest, TestCase4) {
    EXPECT_EQ(indxg2l(1, 2, 0, 0, 3), 1);
}

TEST(Indxg2lTest, TestCase5) {
    EXPECT_EQ(indxg2l(25, 5, 3, 0, 6), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}