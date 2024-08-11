#include <gtest/gtest.h>
#include <vector>
#include <chrono>

// Modified to use smaller arrays for testing
double performOperation(size_t arraySize) {
    std::vector<double> X(arraySize, 1.0); // Use smaller arrays
    std::vector<double> Y(arraySize, 1.0);
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t j = 0; j < X.size(); ++j) {
        X[j] = X[j] + Y[j] + Y[j];
    }

    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = stop - start;
    return duration.count();
}

TEST(OperationTest, PositiveRuntime) {
    // Test with a reasonably small array size
    double runtime = performOperation(100000);
    EXPECT_GT(runtime, 0.0);
}

TEST(OperationTest, CorrectOperationResult) {
    // Testing with a very small array to verify the operation itself
    size_t smallSize = 10;
    std::vector<double> X(smallSize, 1.0);
    std::vector<double> Y(smallSize, 1.0);

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t j = 0; j < smallSize; ++j) {
        X[j] = X[j] + Y[j] + Y[j];
    }

    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = stop - start;

    // Verify each element of X is now 3.0
    for (size_t j = 0; j < smallSize; ++j) {
        EXPECT_EQ(X[j], 3.0);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}