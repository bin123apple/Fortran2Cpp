#include <iostream>
#include <cstdlib>
#include <gtest/gtest.h>

// MyType class definition
class MyType {
public:
    int i;
    MyType(int x = 0) : i(x) {} // Constructor with default value
};

// Function equivalent to get in Fortran
MyType* get(MyType& a) {
    return &a;
}

// Function equivalent to get2 in Fortran, essentially the same as get in this context
MyType* get2(MyType& a) {
    return &a;
}

// Unit tests using Google Test framework
TEST(MyTypeTest, TestGet) {
    MyType x(42);
    MyType* y = get(x);
    EXPECT_EQ(y->i, 42);
}

TEST(MyTypeTest, TestGet2) {
    MyType x(112);
    MyType* y = get2(x);
    EXPECT_EQ(y->i, 112);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}