#include <iostream>
#include <memory>
#include <gtest/gtest.h>

// Base class 'parent'
class parent {
public:
    virtual int sum(const parent& op) const { return 0; } // virtual function for sum
    friend int operator+(const parent& op1, const parent& op2); // friend function for operator overloading
};

// Operator overloading using friend function
int operator+(const parent& op1, const parent& op2) {
    return op1.sum(op2);
}

// Derived class 'child' from 'parent'
class child : public parent {
public:
    int sum(const parent& op) const override { return 1; } // override sum function for 'child'
};

// Unit Test Cases
TEST(ParentChildTest, TestParentAddition) {
    parent m1, m2;
    EXPECT_EQ(0, m1 + m2);
}

TEST(ParentChildTest, TestChildParentAddition) {
    child h1;
    parent m2;
    EXPECT_EQ(1, h1 + m2);
}

TEST(ParentChildTest, TestChildSumMethod) {
    child h1, h2;
    EXPECT_EQ(1, h1.sum(h2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}