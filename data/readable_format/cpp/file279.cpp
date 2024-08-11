#include <iostream>
#include <gtest/gtest.h>

// Equivalent to Fortran module 'foo'
namespace foo {
    struct t {
        int i;
        t(int val) : i(val) {}  // Constructor to allow initialization
    };

    // Operator overloading for '*'
    int operator*(const t& lhs, const t& rhs) {
        return lhs.i * rhs.i;
    }
}

// Equivalent to Fortran module 'bar'
namespace bar {
    struct t2 {
        int i;
        t2(int val) : i(val) {}  // Constructor to allow initialization
    };

    // Operator overloading for '>'
    bool operator>(const t2& lhs, const t2& rhs) {
        return lhs.i > rhs.i;
    }
}

// Unit tests
namespace {
    TEST(FooTest, TestMultiplication) {
        foo::t i(2), j(3);
        EXPECT_EQ(i * j, 6);
    }

    TEST(BarTest, TestGreaterThan) {
        bar::t2 k(4), l(5);
        EXPECT_FALSE(k > l);
        EXPECT_TRUE(l > k);
    }
}

// Main function that can run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}