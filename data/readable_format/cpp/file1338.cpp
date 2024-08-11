#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <gtest/gtest.h>

// Define a class equivalent to the Fortran type
class T {
public:
    // Procedure pointer equivalent in C++, using std::function
    std::function<std::shared_ptr<std::string>(std::shared_ptr<std::string>)> ptr;
};

// Function that behaves similarly to the Fortran function abc
std::shared_ptr<std::string> abc(std::shared_ptr<std::string> arg) {
    // Simply return the shared_ptr arg in this case
    return arg;
}

// Test Fixture for T
class TTest : public ::testing::Test {
protected:
    T x;
    std::shared_ptr<std::string> str;

    void SetUp() override {
        str = std::make_shared<std::string>("abcde");
        x.ptr = abc;
    }
};

TEST_F(TTest, TestFunctionPointer) {
    auto strptr = x.ptr(str);
    EXPECT_EQ(*strptr, "abcde");
    
    *str = "fghij";
    EXPECT_EQ(*strptr, "fghij");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}