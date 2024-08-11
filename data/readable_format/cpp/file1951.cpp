#include <gtest/gtest.h>
#include <iostream>
#include <memory>

// Forward declaration for mutual reference in `p`
class d {
public:
    virtual ~d() {} // Ensure proper cleanup of derived classes
};

// Definition of class `p`
class p {
public:
    d* cc; // Pointer to base class for polymorphism
    // Constructor
    p(d* pd) : cc(pd) {}
};

// Function that returns an object of type `p` given a pointer to `d`
p pc(d* pd) {
    return p(pd);
}

// Assuming `d` has a derived class `d_derived` for demonstration
class d_derived : public d {};

// Unit test
TEST(PCFunctionTest, HandlesNonNullPointer) {
    d_derived myDerivedObj;
    p result = pc(&myDerivedObj);

    // Verify that the cc pointer in result points to myDerivedObj
    EXPECT_EQ(result.cc, &myDerivedObj);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}