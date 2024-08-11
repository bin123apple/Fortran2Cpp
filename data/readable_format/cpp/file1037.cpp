#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Definition of MXCOPY directly in this file
void MXCOPY(int N, const std::vector<std::vector<float>>& MAT1, std::vector<std::vector<float>>& MAT2) {
    if (N == 4) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                MAT2[i][j] = MAT1[i][j];
            }
        }
    } else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                MAT2[i][j] = MAT1[i][j];
            }
        }
    }
}

// Test cases using Google Test
TEST(MXCOPYTest, TestNEquals4) {
    int N = 4;
    std::vector<std::vector<float>> MAT1(N, std::vector<float>(N, 0)); 
    std::vector<std::vector<float>> MAT2(N, std::vector<float>(N)); 
    
    // Initialize MAT1 with some values for demonstration
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            MAT1[i][j] = static_cast<float>(i * N + j + 1); 
        }
    }

    MXCOPY(N, MAT1, MAT2);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            EXPECT_FLOAT_EQ(MAT2[i][j], MAT1[i][j]);
        }
    }
}

TEST(MXCOPYTest, TestNNotEquals4) {
    int N = 5;
    std::vector<std::vector<float>> MAT1(N, std::vector<float>(N, 0)); 
    std::vector<std::vector<float>> MAT2(N, std::vector<float>(N)); 
    
    // Initialize MAT1 with some values for demonstration
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            MAT1[i][j] = static_cast<float>(i * N + j + 1); 
        }
    }

    MXCOPY(N, MAT1, MAT2);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            EXPECT_FLOAT_EQ(MAT2[i][j], MAT1[i][j]);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}