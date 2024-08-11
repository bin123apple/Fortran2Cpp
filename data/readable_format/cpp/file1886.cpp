#include <gtest/gtest.h>

// Declaration of foo without parameters, as originally designed
int foo();

class FooTest : public ::testing::Test {
protected:
    // Note: Removed resetFoo() method because it's not compatible with foo's declaration
};

// Test to ensure foo increments correctly
TEST_F(FooTest, IncrementsCorrectly) {
    int firstCall = foo();
    int secondCall = foo();

    EXPECT_EQ(firstCall + 1, secondCall) << "foo did not increment by 1 as expected.";
}

// Definition of foo with a static variable to maintain state between calls
int foo() {
    static int i = 0;
    i = i + 1;
    return i;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}