#include <vector>
#include <gtest/gtest.h>

// Function definitions
void loop10_F90(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, double u) {
    for (int i = 0; i < N; ++i) {
        x[i] = u + a[i] + b[i] + c[i];
    }
}

void loop10_F90Overhead(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, double u) {
    // Intentionally left blank
}

// Unit test
TEST(Loop10Test, TestCorrectness) {
    const int N = 5;
    const double u = 2.0;
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> b = {5.0, 4.0, 3.0, 2.0, 1.0};
    std::vector<double> c = {2.0, 2.0, 2.0, 2.0, 2.0};
    std::vector<double> x(N, 0.0); // Initialize x with zeros

    // Call the function under test
    loop10_F90(N, x, a, b, c, u);

    // Check the results
    for (int i = 0; i < N; ++i) {
        EXPECT_DOUBLE_EQ(x[i], u + a[i] + b[i] + c[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}