#include <gtest/gtest.h>
#include <vector>

// Define the loop8_F77 function directly in this file
void loop8_F77(int N, std::vector<double>& a, std::vector<double>& x, double u) {
    for (int i = 0; i < N; ++i) {
        x[i] = u / a[i];
    }
}

// Unit test for the loop8_F77 function
TEST(Loop8_F77Test, CorrectDivision) {
    int N = 5;
    std::vector<double> a = {1.0, 2.0, 4.0, 5.0, 10.0};
    std::vector<double> x(N);
    double u = 20.0;

    loop8_F77(N, a, x, u);

    std::vector<double> expectedResults = {20.0, 10.0, 5.0, 4.0, 2.0};
    for (int i = 0; i < N; ++i) {
        EXPECT_NEAR(expectedResults[i], x[i], 1e-9);
    }
}

// Main function that runs all the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}