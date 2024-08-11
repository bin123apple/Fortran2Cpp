#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class base_mat {
private:
    int m, n; // Dimensions of the matrix

public:
    // Constructor to initialize matrix dimensions
    base_mat(int m, int n) : m(m), n(n) {}

    // Method to swap dimensions (transpose)
    void transp() {
        int temp = m;
        m = n;
        n = temp;
    }

    // Method to perform transpose operation and further actions if needed (demonstration)
    void transc() {
        transp(); // Currently, this just calls transp() but can be extended.
    }

    // Getters for testing purposes
    int getM() const { return m; }
    int getN() const { return n; }
};

// Unit tests using Google Test framework

TEST(BaseMatTest, TranspTest) {
    base_mat mat(3, 2);
    mat.transp();
    EXPECT_EQ(mat.getM(), 2);
    EXPECT_EQ(mat.getN(), 3);
}

TEST(BaseMatTest, TranscTest) {
    base_mat mat(3, 2);
    mat.transc();
    EXPECT_EQ(mat.getM(), 2);
    EXPECT_EQ(mat.getN(), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}