#include <gtest/gtest.h>
#include <vector>

// Assuming the implementation of is_sorted_dble is as follows:
int is_sorted_dble(const std::vector<double>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return i; // Adjusted for 0-based indexing
        }
    }
    return -1; // Indicates that the array is sorted
}

// Unit tests
TEST(IsSortedTest, EmptyArray) {
    std::vector<double> vec = {};
    EXPECT_EQ(-1, is_sorted_dble(vec));
}

TEST(IsSortedTest, SingleElement) {
    std::vector<double> vec = {1.0};
    EXPECT_EQ(-1, is_sorted_dble(vec));
}

TEST(IsSortedTest, SortedArray) {
    std::vector<double> vec = {1.0, 2.0, 3.0, 4.0, 5.0};
    EXPECT_EQ(-1, is_sorted_dble(vec));
}

TEST(IsSortedTest, UnsortedArray) {
    std::vector<double> vec = {1.0, 3.0, 2.0, 4.0, 5.0};
    EXPECT_EQ(2, is_sorted_dble(vec));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}