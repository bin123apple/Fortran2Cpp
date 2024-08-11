#include <gtest/gtest.h>
#include <cstdint> // For int64_t

// Simplified version of _JGEMMX function
void _JGEMMX(int64_t m, int64_t n, int64_t k, int64_t alpha, int64_t* a, int64_t inc1a, int64_t inc2a,
             int64_t* b, int64_t inc1b, int64_t inc2b, int64_t beta, int64_t* c, int64_t inc1c, int64_t inc2c) {
    // Assuming 1D array operations for simplicity
    for (int64_t i = 0; i < m * n; ++i) {
        c[i] = alpha * a[i] + beta * b[i];
    }
}

TEST(JGEMMXTest, SimpleAddition) {
    int64_t m = 2, n = 2, k = 2;
    int64_t alpha = 1, beta = 1;
    int64_t a[] = {1, 2, 3, 4};
    int64_t b[] = {5, 6, 7, 8};
    int64_t c[4] = {0}; // Output array
    int64_t inc1a = 1, inc2a = 2, inc1b = 1, inc2b = 2, inc1c = 1, inc2c = 2;

    _JGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c);

    // Expected results based on our simplified operation
    int64_t expected[] = {6, 8, 10, 12};

    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(c[i], expected[i]) << "Vectors c and expected differ at index " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}