#include <iostream>
#include <gtest/gtest.h>

// Define the loop3_F77 function directly in this file
void loop3_F77(int N, double* x, double* y, double a) {
    for (int i = 0; i < N; ++i) {
        y[i] = y[i] + a * x[i];
    }
}

// Google Test fixture for testing loop3_F77 function
class Loop3F77Test : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize test data
        N = 5;
        a = 2.5;
        x = new double[N]{1.0, 2.0, 3.0, 4.0, 5.0};
        y = new double[N]{5.0, 4.0, 3.0, 2.0, 1.0};
        expectedY = new double[N]{7.5, 9.0, 10.5, 12.0, 13.5};
    }

    void TearDown() override {
        // Clean up
        delete[] x;
        delete[] y;
        delete[] expectedY;
    }

    int N;
    double a;
    double* x;
    double* y;
    double* expectedY;
};

TEST_F(Loop3F77Test, CorrectlyUpdatesY) {
    loop3_F77(N, x, y, a);

    for (int i = 0; i < N; ++i) {
        EXPECT_NEAR(expectedY[i], y[i], 1e-6);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}