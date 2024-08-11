// combined_test.cpp
#include <iostream>
#include <memory>
#include <functional>
#include <gtest/gtest.h>

// Define a function type that returns std::unique_ptr<int>
using AllocIntegerFunc = std::function<std::unique_ptr<int>()>;

// Define a struct equivalent to the Fortran type, including a function pointer
struct ConcreteType {
    AllocIntegerFunc alloc;
};

// Declaration of the function that matches the AllocIntegerFunc signature
std::unique_ptr<int> alloc_integer() {
    return std::make_unique<int>(13);
}

// Unit Tests
TEST(AllocIntegerTest, DirectCall) {
    auto result = alloc_integer();
    ASSERT_NE(result, nullptr); // Ensure the pointer is not null
    EXPECT_EQ(*result, 13);
}

TEST(AllocIntegerTest, FunctionPointerCall) {
    AllocIntegerFunc pp = alloc_integer;
    auto result = pp();
    ASSERT_NE(result, nullptr); // Ensure the pointer is not null
    EXPECT_EQ(*result, 13);
}

TEST(AllocIntegerTest, ConcreteTypeFunctionPointerCall) {
    ConcreteType concrete;
    concrete.alloc = alloc_integer;
    auto result = concrete.alloc();
    ASSERT_NE(result, nullptr); // Ensure the pointer is not null
    EXPECT_EQ(*result, 13);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}