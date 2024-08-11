#include <iostream>
#include <vector>
#include <gtest/gtest.h>

void loop22_Cpp(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    for (int i = 0; i < N; ++i) {
        x[i] = x[i] + a[i] * b[i] + c[i] * d[i];
    }
}

void loop22_CppOverhead(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    // This function intentionally left blank, similar to the Fortran version.
}

TEST(Loop22Test, BasicTest) {
    int N = 5;
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> a = {2.0, 2.0, 2.0, 2.0, 2.0};
    std::vector<double> b = {1.0, 1.0, 1.0, 1.0, 1.0};
    std::vector<double> c = {0.5, 0.5, 0.5, 0.5, 0.5};
    std::vector<double> d = {2.0, 2.0, 2.0, 2.0, 2.0};

    loop22_Cpp(N, x, a, b, c, d);

    std::vector<double> expected = {4.0, 5.0, 6.0, 7.0, 8.0};
    for (int i = 0; i < N; ++i) {
        EXPECT_DOUBLE_EQ(x[i], expected[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}