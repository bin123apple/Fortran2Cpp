#include <iostream>
#include <gtest/gtest.h>
#include <sstream>

std::string sub(bool makeVolatileTrue) {
    std::stringstream output;
    volatile bool t1;
    bool t2;
    int i;

    t1 = makeVolatileTrue; // Simulate the volatile effect for testing
    t2 = false;
    
    for (i = 1; i <= 2; ++i) {
        if (t1) output << "VolatileNotOptimizedAway";
        if (t2) output << "NonVolatileNotOptimizedAway";
    }
    
    return output.str();
}

TEST(SubTest, VolatileEffect) {
    std::string expectedOutput = "VolatileNotOptimizedAwayVolatileNotOptimizedAway";
    ASSERT_EQ(sub(true), expectedOutput);
}

TEST(SubTest, NoVolatileEffect) {
    std::string expectedOutput = "";
    ASSERT_EQ(sub(false), expectedOutput);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}