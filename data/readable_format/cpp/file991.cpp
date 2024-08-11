#include <iostream>
#include <gtest/gtest.h>

// Define the r2w function directly in this file
void r2w(int ldr, int ldw, int l, int m, double** r, double** w) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            w[i][j] = r[i][j];
        }
    }
}

// Test case for the function
TEST(R2WTest, CorrectCopy) {
    const int ldr = 5, ldw = 5, l = 3, m = 4;

    // Allocate and initialize r
    double** r = new double*[ldr];
    for (int i = 0; i < ldr; ++i) {
        r[i] = new double[m];
        for (int j = 0; j < m; ++j) {
            r[i][j] = i * 10 + j; // Example values
        }
    }

    // Allocate w
    double** w = new double*[ldw];
    for (int i = 0; i < ldw; ++i) {
        w[i] = new double[m];
    }

    // Copy from r to w
    r2w(ldr, ldw, l, m, r, w);

    // Check if w was correctly copied from r
    bool test_passed = true;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            if (w[i][j] != r[i][j]) {
                test_passed = false;
                break;
            }
        }
        if (!test_passed) break;
    }

    EXPECT_TRUE(test_passed);

    // Clean up
    for (int i = 0; i < ldr; ++i) {
        delete[] r[i];
    }
    delete[] r;

    for (int i = 0; i < ldw; ++i) {
        delete[] w[i];
    }
    delete[] w;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}