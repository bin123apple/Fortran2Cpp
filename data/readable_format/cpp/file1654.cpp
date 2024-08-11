#include <gtest/gtest.h>
#include <vector>

// Define the function directly in this file
bool is_sorted_asc_real(const std::vector<float>& x) {
    for(size_t i = 1; i < x.size(); ++i) {
        if (x[i - 1] > x[i]) {
            return false;
        }
    }
    return true;
}

// Unit tests
TEST(IsSortedAscRealTest, HandlesEmptyArray) {
    std::vector<float> test_array = {};
    EXPECT_TRUE(is_sorted_asc_real(test_array));
}

TEST(IsSortedAscRealTest, HandlesSingleElement) {
    std::vector<float> test_array = {5.0f};
    EXPECT_TRUE(is_sorted_asc_real(test_array));
}

TEST(IsSortedAscRealTest, HandlesFullySortedArray) {
    std::vector<float> test_array = {1.0f, 2.0f, 3.0f, 4.0f};
    EXPECT_TRUE(is_sorted_asc_real(test_array));
}

TEST(IsSortedAscRealTest, HandlesPartiallySortedArray) {
    std::vector<float> test_array = {1.0f, 3.0f, 2.0f, 4.0f};
    EXPECT_FALSE(is_sorted_asc_real(test_array));
}

TEST(IsSortedAscRealTest, HandlesCompletelyUnsortedArray) {
    std::vector<float> test_array = {4.0f, 3.0f, 2.0f, 1.0f};
    EXPECT_FALSE(is_sorted_asc_real(test_array));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}