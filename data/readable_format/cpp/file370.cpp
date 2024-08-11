#include <vector>
#include <gtest/gtest.h>
#include <iostream>

// Interchange sort function implementation
template<typename T>
void interchangeSortDecReal(std::vector<T>& vec) {
    int n = vec.size();
    T swapValue;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vec[i] < vec[j]) {
                // Swap elements
                swapValue = vec[i];
                vec[i] = vec[j];
                vec[j] = swapValue;
            }
        }
    }
}

// Unit tests
TEST(InterchangeSortDecRealTest, TestPositiveNumbers) {
    std::vector<double> vec = {5.0, 3.0, 4.0, 1.0, 2.0};
    std::vector<double> expected = {5.0, 4.0, 3.0, 2.0, 1.0};
    interchangeSortDecReal(vec);
    EXPECT_EQ(vec, expected);
}

TEST(InterchangeSortDecRealTest, TestNegativeNumbers) {
    std::vector<double> vec = {-1.0, -3.0, -2.0, -5.0, -4.0};
    std::vector<double> expected = {-1.0, -2.0, -3.0, -4.0, -5.0};
    interchangeSortDecReal(vec);
    EXPECT_EQ(vec, expected);
}

TEST(InterchangeSortDecRealTest, TestMixedNumbers) {
    std::vector<double> vec = {3.0, -2.0, 1.0, -4.0, 0.0};
    std::vector<double> expected = {3.0, 1.0, 0.0, -2.0, -4.0};
    interchangeSortDecReal(vec);
    EXPECT_EQ(vec, expected);
}

TEST(InterchangeSortDecRealTest, TestRepeatingElements) {
    std::vector<double> vec = {2.0, 2.0, 1.0, 3.0, 3.0};
    std::vector<double> expected = {3.0, 3.0, 2.0, 2.0, 1.0};
    interchangeSortDecReal(vec);
    EXPECT_EQ(vec, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}