#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <gtest/gtest.h>

// Base class t1
class t1 {
public:
    int i;
    virtual ~t1() {} // Ensure polymorphic behavior
};

// Derived class t2
class t2 : public t1 {
public:
    int j;
};

// Helper function to perform type checks similar to SAME_TYPE_AS in Fortran
template<typename T, typename U>
bool same_type_as(T* a, U* b) {
    return typeid(*a) == typeid(*b);
}

// Test suite for the SameTypeAs functionality
TEST(SameTypeAsTest, CheckTypeCompatibility) {
    t1* c1 = nullptr;
    t1* c2 = nullptr;
    t1 x1;
    t2 x2;

    // Check types when both are of the same type
    EXPECT_TRUE(same_type_as(&x1, &x1));

    // Check types when they are of different types
    EXPECT_FALSE(same_type_as(&x1, &x2));

    // Point c1 to x1
    c1 = &x1;
    EXPECT_TRUE(same_type_as(c1, &x1));
    EXPECT_FALSE(same_type_as(c1, &x2));

    // Point both c1 and c2 to x2
    c1 = &x2;
    c2 = &x2;
    EXPECT_TRUE(same_type_as(c1, c2));

    // Point c1 to x1 and c2 to x2
    c1 = &x1;
    c2 = &x2;
    EXPECT_FALSE(same_type_as(c1, c2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}