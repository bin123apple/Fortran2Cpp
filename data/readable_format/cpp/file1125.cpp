// snafu.cpp
#include <string>
#include <gtest/gtest.h>

void snafu(int i, std::string& c1, std::string& c2) {
    c1 = std::string(i, ' '); // Allocate space and initialize with spaces
    c2 = std::string(i, ' '); // Same as above
    c1.clear(); // Ensure the string is empty
    c2.clear(); // Ensure the string is empty
}

TEST(SnafuTest, HandlesEmptyStringCorrectly) {
    std::string c1 = "initial", c2 = "initial";
    snafu(10, c1, c2);
    EXPECT_EQ(c1.size(), 0);
    EXPECT_EQ(c2.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}