#include <iostream>
#include <cstdlib> // For std::abort()
#include <gtest/gtest.h>

// Define the DBaseSparseMat class directly in this file
class DBaseSparseMat {
public:
    int v[10] = {0}; // Initialize all elements to 0

    DBaseSparseMat() = default;
    virtual ~DBaseSparseMat() = default;

    virtual void checkSize() {
        if (sizeof(v) / sizeof(v[0]) != 10) {
            std::abort();
        }
        std::cout << "NV = " << sizeof(v) / sizeof(v[0]) << std::endl;
    }
};

// Test for checking array size
TEST(DBaseSparseMatTest, ArraySizeCheck) {
    DBaseSparseMat mat; // Stack allocation
    EXPECT_NO_THROW(mat.checkSize()); // Expect no abort call
}

// Example of a test for a derived class, if polymorphism is used
class DerivedSparseMat : public DBaseSparseMat {
public:
    void checkSize() override {
        DBaseSparseMat::checkSize();
    }
};

TEST(DerivedSparseMatTest, ArraySizeCheck) {
    DerivedSparseMat mat; // Stack allocation
    EXPECT_NO_THROW(mat.checkSize()); // Still expect no abort
}

// Main function for Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}