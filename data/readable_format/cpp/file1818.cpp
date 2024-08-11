#include <gtest/gtest.h>
#include <vector>

// Function definitions
void loop12_F77(int N, std::vector<double>& y, std::vector<double>& x, 
                const std::vector<double>& a, const std::vector<double>& b, 
                const std::vector<double>& c, const std::vector<double>& d, double u) {
    for (int i = 0; i < N; ++i) {
        y[i] = u + a[i];
        x[i] = a[i] + b[i] + c[i] + d[i];
    }
}

void loop12_F77Overhead(int N, std::vector<double>& y, std::vector<double>& x, 
                        const std::vector<double>& a, const std::vector<double>& b, 
                        const std::vector<double>& c, const std::vector<double>& d, double u) {
    // This function is a placeholder according to the original Fortran code
}

// Unit test
TEST(Loop12F77Test, CorrectComputation) {
    const int N = 5;
    std::vector<double> y(N), x(N), a(N), b(N), c(N), d(N);
    double u = 2.0;

    // Initialize test data
    for (int i = 0; i < N; ++i) {
        a[i] = (i + 1) * 1.0;
        b[i] = (i + 1) * 2.0;
        c[i] = (i + 1) * 3.0;
        d[i] = (i + 1) * 4.0;
    }

    // Call the function
    loop12_F77(N, y, x, a, b, c, d, u);

    // Verify results
    for (int i = 0; i < N; ++i) {
        EXPECT_DOUBLE_EQ(y[i], u + a[i]);
        EXPECT_DOUBLE_EQ(x[i], a[i] + b[i] + c[i] + d[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}