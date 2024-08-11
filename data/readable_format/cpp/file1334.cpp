#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

// Equivalent of Fortran TYPE
struct type1 {
    int i1;
};

// Equivalent of MODULE bar
namespace bar {
    void sub1(type1& x, std::vector<int>& y) {
        y.assign(x.i1, 1);  // Assign '1' to all elements
    }

    void sub2(type1& u, std::vector<int>& v) {
        v.assign(u.i1, 2);  // Assign '2' to all elements
    }
}

// Equivalent of MODULE foobar
namespace foobar {
    void sub3(type1& s, std::vector<int>& t) {
        t.assign(s.i1, 3);  // Assign '3' to all elements
    }
}

// Unit Tests
TEST(SubroutineTest, Sub1Test) {
    type1 z;
    std::vector<int> j(3, 0);
    z.i1 = 3;  // Test with i1 = 3
    bar::sub1(z, j);
    EXPECT_EQ(j, std::vector<int>({1, 1, 1}));
}

TEST(SubroutineTest, Sub2Test) {
    type1 z;
    std::vector<int> j(2, 0);
    z.i1 = 2;  // Test with i1 = 2
    bar::sub2(z, j);
    EXPECT_EQ(j, std::vector<int>({2, 2}));
}

TEST(SubroutineTest, Sub3Test) {
    type1 z;
    std::vector<int> j(1, 0);
    z.i1 = 1;  // Test with i1 = 1
    foobar::sub3(z, j);
    EXPECT_EQ(j, std::vector<int>({3}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}