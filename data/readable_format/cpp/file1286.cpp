#include <gtest/gtest.h>

// Directly define the functions in this file
int foo1() {
    static int j = 0; // Static variable with initial value 0
    j = j + 1;
    return j;
}

int foo2() {
    static int j = 0;
    j = j + 1;
    return j;
}

int foo3() {
    static int j = 0;
    j = j + 1;
    return j;
}

int foo4() {
    static int j = 0;
    j = j + 1;
    return j;
}

// Unit tests for the functions
TEST(FooFunctionsTest, IncrementingValues) {
    for (int i = 1; i <= 10; ++i) {
        EXPECT_EQ(foo1(), i) << "foo1 failed at i = " << i;
        EXPECT_EQ(foo2(), i) << "foo2 failed at i = " << i;
        EXPECT_EQ(foo3(), i) << "foo3 failed at i = " << i;
        EXPECT_EQ(foo4(), i) << "foo4 failed at i = " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}