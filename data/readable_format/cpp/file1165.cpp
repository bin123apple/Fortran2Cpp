#include <vector>
#include <numeric>
#include <iostream>
#include <gtest/gtest.h>

// Defining the namespace and structures in place of the Fortran module and type
namespace pdt_m {
    
    template <size_t K>
    struct vec {
        static constexpr size_t k = K;
        std::vector<int> foo = std::vector<int>(K, 0);
    };

    template <size_t K>
    int total(const vec<K>& a) {
        return std::accumulate(a.foo.begin(), a.foo.end(), 0);
    }
}

// Unit test using Google Test
TEST(VecTotalTest, CorrectTotal) {
    pdt_m::vec<5> test_vec;
    std::fill(test_vec.foo.begin(), test_vec.foo.end(), 1); // Initialize all elements to 1
    EXPECT_EQ(pdt_m::total(test_vec), 5); // Expect the sum to be 5

    pdt_m::vec<10> test_vec2;
    std::fill(test_vec2.foo.begin(), test_vec2.foo.end(), 2); // Initialize all elements to 2
    EXPECT_EQ(pdt_m::total(test_vec2), 20); // Expect the sum to be 20
}

// Main function for running the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}