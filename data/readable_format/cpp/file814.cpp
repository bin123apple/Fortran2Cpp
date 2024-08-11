#include <gtest/gtest.h>
#include <cstdint> // For std::int32_t

// Directly include the get_loop_index function in this file
void get_loop_index(int instr_index, int& index, bool& subrange_flag) {
    const std::int32_t in_index_mask = 65536;
    std::int32_t mask_val = instr_index & in_index_mask;

    if (mask_val == 0) {
        subrange_flag = false;
        index = instr_index;
    } else {
        subrange_flag = true;
        index = instr_index ^ in_index_mask;
    }
}

// Unit tests using Google Test
TEST(GetLoopIndexTest, HandlesZeroInput) {
    int index;
    bool subrange_flag;
    
    get_loop_index(0, index, subrange_flag);
    
    EXPECT_FALSE(subrange_flag);
    EXPECT_EQ(0, index);
}

TEST(GetLoopIndexTest, HandlesMaskedValue) {
    int index;
    bool subrange_flag;
    
    get_loop_index(65536, index, subrange_flag);
    
    EXPECT_TRUE(subrange_flag);
    EXPECT_EQ(0, index);
}

// Main function that runs the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}