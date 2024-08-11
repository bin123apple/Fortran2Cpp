// File: ldaU_hp_test.cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include "gtest/gtest.h" // Assumed to be in your include path

class ldaU_hp {
public:
    double sum_array(const std::vector<double>& arr) const {
        return std::accumulate(arr.begin(), arr.end(), 0.0);
    }
};

// Test case for the sum_array function
TEST(ldaU_hpTest, SumArray) {
    ldaU_hp instance;
    std::vector<double> test_array = {1.0, 2.0, 3.0, 4.0, 5.0};
    double result = instance.sum_array(test_array);
    EXPECT_DOUBLE_EQ(result, 15.0); // Check if the sum is as expected
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}