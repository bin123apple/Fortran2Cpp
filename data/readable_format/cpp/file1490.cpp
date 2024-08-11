#include <gtest/gtest.h>
#include <cstdlib> // For setenv and getenv

// Define the function that sets the environment variable
void SetUVMTestName() {
    // Set the environment variable UVM_TESTNAME
    // The '1' argument means overwrite if the environment variable already exists
    setenv("UVM_TESTNAME", "wb_periph_subsys_test_base", 1);
}

// Test case to verify the environment variable is correctly set
TEST(EnvironmentVariableTest, UVMTestNameIsCorrect) {
    SetUVMTestName(); // Call the function to set the environment variable

    // Get the environment variable
    const char* value = getenv("UVM_TESTNAME");

    // Check if the environment variable is correctly set
    ASSERT_STREQ(value, "wb_periph_subsys_test_base");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}