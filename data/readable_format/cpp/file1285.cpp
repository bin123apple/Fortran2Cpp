#include <gtest/gtest.h>
#include <iostream>
#include <vector>

// Function prototypes
void initializeArrays(int* a, int* b, const int n);
void computeC(const int* a, const int* b, int* c, const int n);

// Original logic functions
void initializeArrays(int* a, int* b, const int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i * 2;
        b[i] = i * 4;
    }
}

void computeC(const int* a, const int* b, int* c, const int n) {
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
}

// Unit tests
TEST(ArrayOperationTest, ArrayInitialization) {
    const int n = 1024;
    std::vector<int> a(n), b(n);
    
    initializeArrays(a.data(), b.data(), n);
    
    for (int i = 0; i < n; ++i) {
        EXPECT_EQ(a[i], i * 2);
        EXPECT_EQ(b[i], i * 4);
    }
}

TEST(ArrayOperationTest, ArraySummation) {
    const int n = 1024;
    std::vector<int> a(n), b(n), c(n);
    
    initializeArrays(a.data(), b.data(), n);
    computeC(a.data(), b.data(), c.data(), n);
    
    for (int i = 0; i < n; ++i) {
        EXPECT_EQ(c[i], a[i] + b[i]);
    }
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}