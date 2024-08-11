#include <iostream>
#include <gtest/gtest.h>

// Define the PpmModuleTreeCutpos class directly in this file
class PpmModuleTreeCutpos {
public:
    // Template method for cutpos operation
    template<typename T>
    static T ppm_tree_cutpos();

    // Specializations for float and double
};

// Specialization for float (single precision)
template<>
float PpmModuleTreeCutpos::ppm_tree_cutpos<float>() {
    std::cout << "Executing single precision operation" << std::endl;
    // Example computation for single precision
    return 1.23f;
}

// Specialization for double (double precision)
template<>
double PpmModuleTreeCutpos::ppm_tree_cutpos<double>() {
    std::cout << "Executing double precision operation" << std::endl;
    // Example computation for double precision
    return 1.2345678901234567;
}

// Test cases
TEST(PpmModuleTreeCutposTest, SinglePrecision) {
    float result = PpmModuleTreeCutpos::ppm_tree_cutpos<float>();
    EXPECT_FLOAT_EQ(result, 1.23f); // Check if the result matches the expected single precision value
}

TEST(PpmModuleTreeCutposTest, DoublePrecision) {
    double result = PpmModuleTreeCutpos::ppm_tree_cutpos<double>();
    EXPECT_DOUBLE_EQ(result, 1.2345678901234567); // Check if the result matches the expected double precision value
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}