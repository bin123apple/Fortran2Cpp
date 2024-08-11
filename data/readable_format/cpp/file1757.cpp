#include <gtest/gtest.h>
#include <array>

void assignValues(std::array<int, 9>& a, std::array<int, 9>& b, std::array<int, 9>& c) {
    for (int i = 0; i < 9; ++i) {
        if (a[i] == 0) {
            if (b[i] == 0) c[i] = 1;
            else if (b[i] == 1) c[i] = 2;
            else c[i] = 3;
        }
        else if (a[i] == 1) {
            if (b[i] == 0) c[i] = 4;
            else if (b[i] == 1) c[i] = 5;
            else c[i] = 6;
        }
        else {
            if (b[i] == 0) c[i] = 7;
            else if (b[i] == 1) c[i] = 8;
            else c[i] = 9;
        }
    }
}

TEST(ArrayAssignmentTest, CorrectAssignment) {
    std::array<int, 9> a = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    std::array<int, 9> b = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    std::array<int, 9> c = {}; // Initialize with zeros
    std::array<int, 9> expected_c = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    assignValues(a, b, c);

    for (int i = 0; i < 9; ++i) {
        EXPECT_EQ(c[i], expected_c[i]) << "Arrays differ at index " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}