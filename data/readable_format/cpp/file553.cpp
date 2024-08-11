#include <vector>
#include <iostream>
#include <gtest/gtest.h>

// Function definitions
void loop15_F90(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c) {
    for (int i = 0; i < N; ++i) {
        x[i] = c[i] + a[i] * b[i];
    }
}

// Test case
TEST(Loop15F90Test, CorrectComputation) {
    int N = 5;
    std::vector<double> x(N), a(N), b(N), c(N);

    // Initialize vectors
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;  // 1, 2, 3, 4, 5
        b[i] = 2.0 * (i + 1);  // 2, 4, 6, 8, 10
        c[i] = (i + 1) + 0.5;  // 1.5, 2.5, 3.5, 4.5, 5.5
    }

    // Call the function
    loop15_F90(N, x, a, b, c);

    // Check results
    for (int i = 0; i < N; ++i) {
        EXPECT_DOUBLE_EQ(x[i], c[i] + a[i] * b[i]);
    }
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}