#include <gtest/gtest.h>

// Directly include struct definitions into the same file
struct type1 {
    int v;
};

struct type2 {
    int v;
};

struct type3 {
    int v;
};

struct type4 {
    int v;
};

// Unit Test Code
TEST(TypeTest, CheckValues) {
    type1 a;
    type2 b;
    type3 c;
    type4 d;

    a.v = 1;
    b.v = 2;
    c.v = 3;
    d.v = 4;

    EXPECT_EQ(a.v, 1);
    EXPECT_EQ(b.v, 2);
    EXPECT_EQ(c.v, 3);
    EXPECT_EQ(d.v, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}