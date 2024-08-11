// main.cpp
#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct t {
    std::unique_ptr<int> caf;
};

class CodeTest : public ::testing::Test {
protected:
    t x, y;
    int* ptr = nullptr;

    void SetUp() override {
        y.caf = std::make_unique<int>(6);  // Directly assign 6 to y.caf
        ptr = y.caf.get();
    }
};

TEST_F(CodeTest, AllocationAndAssignment) {
    ASSERT_NE(nullptr, y.caf);
    EXPECT_EQ(6, *y.caf);
}

TEST_F(CodeTest, UniqueOwnershipAndPointer) {
    *ptr = 123;
    EXPECT_EQ(123, *y.caf);

    // Simulating Fortran's behavior by manually copying the value, not sharing ownership
    x.caf = std::make_unique<int>(*y.caf);

    *ptr = 456; // This change will not affect x.caf if they do not share the same memory
    EXPECT_EQ(456, *y.caf); // y.caf was changed
    EXPECT_EQ(123, *x.caf); // x.caf should remain unchanged if it doesn't share memory with y.caf
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}