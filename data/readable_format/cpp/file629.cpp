#include <iostream>
#include <gtest/gtest.h>

// Define the class t directly in this file, instead of including it from "t.h"
class t {
public:
    void testsub() const {
        std::cout << "t's test" << std::endl;
    }

    int testfun() const {
        return 1;
    }
};

// Unit tests for class t
TEST(TClassTest, TestSub) {
    t x;
    // Since testsub only prints to the console, you might want to test its side effects instead.
    // Here, we're assuming its success due to the lack of return values or side effects to check.
    // In real scenarios, consider designing your classes for testability.
    EXPECT_NO_THROW(x.testsub());
}

TEST(TClassTest, TestFun) {
    t x;
    EXPECT_EQ(1, x.testfun());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}