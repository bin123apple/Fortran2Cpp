#include <gtest/gtest.h>
#include <vector>

// Define a simple matrix multiplication function for testing purposes
void matrix_multiply(const std::vector<std::vector<float>>& a,
                     const std::vector<std::vector<float>>& b,
                     std::vector<std::vector<float>>& c, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0.0f; // Make sure to clear previous values
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Test case for the matrix multiplication
TEST(MatrixMultiplicationTest, Correctness) {
    const int test_n = 4;
    std::vector<std::vector<float>> test_a(test_n, std::vector<float>(test_n, 1.0f));
    std::vector<std::vector<float>> test_b(test_n, std::vector<float>(test_n, 1.0f));
    std::vector<std::vector<float>> test_c(test_n, std::vector<float>(test_n));

    // Initialize test matrices
    for (int i = 0; i < test_n; ++i) {
        for (int j = 0; j < test_n; ++j) {
            test_a[i][j] = 1.0f * (i + 1);
            test_b[i][j] = 1.0f * (j + 1);
        }
    }

    // Perform matrix multiplication
    matrix_multiply(test_a, test_b, test_c, test_n);

    // Check the result
    bool result_correct = true;
    for (int i = 0; i < test_n; ++i) {
        for (int j = 0; j < test_n; ++j) {
            float expected_value = 1.0f * (i + 1) * (j + 1) * test_n;
            if (test_c[i][j] != expected_value) {
                result_correct = false;
                break;
            }
        }
        if (!result_correct) {
            break;
        }
    }

    ASSERT_TRUE(result_correct);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}