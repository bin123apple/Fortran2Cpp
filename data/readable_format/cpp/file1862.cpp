#include <gtest/gtest.h>
#include <vector>

// Forward declaration of the function to test the assignment logic.
bool testSubmatrixAssignment(std::vector<std::vector<int>>& A, int n);

// Test case for submatrix assignment.
TEST(MainTest, SubmatrixAssignment) {
    const int n = 5; // Matrix size
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1)); // Initialize matrix with 1's.
    
    // Invoke the function with the matrix and its size.
    bool result = testSubmatrixAssignment(A, n);

    // Assert the result is true, meaning the test passed.
    ASSERT_TRUE(result);
}

// Function to test the submatrix assignment logic.
bool testSubmatrixAssignment(std::vector<std::vector<int>>& A, int n) {
    int startRow = 2, endRow = 4;
    int startCol = 2, endCol = 4;

    // Assigning 2's to a submatrix within A.
    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            A[i-1][j-1] = 2; // Adjust for 0-based indexing.
        }
    }

    // Verify the entire matrix A for correct values.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (2 <= i && i <= 4 && 2 <= j && j <= 4) {
                // Inside the submatrix, expect 2.
                if (A[i-1][j-1] != 2) {
                    return false; // Test failed.
                }
            } else {
                // Outside the submatrix, expect 1.
                if (A[i-1][j-1] != 1) {
                    return false; // Test failed.
                }
            }
        }
    }

    return true; // Test passed.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}