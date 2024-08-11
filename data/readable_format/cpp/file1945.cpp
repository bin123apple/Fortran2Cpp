#include <gtest/gtest.h>
#include <vector>

void btn(int& n, const std::vector<bool>& b) {
    n = 0;
    for (int i = static_cast<int>(b.size()) - 1; i >= 0; --i) {
        n = n * 2;
        if (b[i]) {
            n = n + 1;
        }
    }
}

TEST(BtnTest, AllTrue) {
    std::vector<bool> test_case1 = {true, true, true};
    int result = 0;
    btn(result, test_case1);
    EXPECT_EQ(result, 7);
}

TEST(BtnTest, MixedValues) {
    std::vector<bool> test_case2 = {true, false, true, true};
    int result = 0;
    btn(result, test_case2);
    EXPECT_EQ(result, 13);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}