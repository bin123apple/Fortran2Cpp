#include <iostream>
#include <gtest/gtest.h>

// Define a structure that will mimic the Fortran namelist
struct MyNml {
    float x;
    
    // Constructor to initialize the variables
    MyNml() : x(1.0f) {}

    // Function to print the values of the variables in the namelist
    void print() {
        std::cout << "x = " << x << std::endl;
    }
};

// Test fixture for MyNml
class MyNmlTest : public ::testing::Test {
protected:
    MyNml mynml; // Use the MyNml structure from the translated code

    // SetUp() and TearDown() can be used if needed
    void SetUp() override {
        // Code to set up test environment, if necessary
    }

    void TearDown() override {
        // Code to clean up after tests, if necessary
    }
};

// Test case for verifying the initialization of x
TEST_F(MyNmlTest, InitializationTest) {
    EXPECT_FLOAT_EQ(mynml.x, 1.0f); // Check if x is initialized to 1
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}