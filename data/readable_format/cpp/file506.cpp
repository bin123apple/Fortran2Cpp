// dcopy_test.cpp
#include <gtest/gtest.h>
#include <vector>

// Assuming the existence of a DCOPY function; let's define it
template<typename T>
void DCOPY(int N, const T* DX, int INCX, T* DY, int INCY) {
    for (int ix = 0, iy = 0; N > 0; N--, ix += INCX, iy += INCY) {
        DY[iy] = DX[ix];
    }
}

// Wrapper function for convenience
void dcopy_wrapper(int N, const std::vector<double>& dx, int INCX, std::vector<double>& dy, int INCY) {
    if(dy.size() < static_cast<size_t>((N-1) * INCY + 1)){
        dy.resize((N-1) * INCY + 1);
    }
    DCOPY<double>(N, dx.data(), INCX, dy.data(), INCY);
}

// Unit test
TEST(DCOPYTest, BasicTest) {
    std::vector<double> dx = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> dy;
    int N = 3;
    int INCX = 2;
    int INCY = 1;

    dcopy_wrapper(N, dx, INCX, dy, INCY);

    std::vector<double> expected_dy = {1.0, 3.0, 5.0};

    ASSERT_EQ(dy.size(), expected_dy.size()) << "Vectors dy and expected_dy are of unequal length";

    for (size_t i = 0; i < expected_dy.size(); ++i) {
        EXPECT_DOUBLE_EQ(dy[i], expected_dy[i]) << "Vectors dy and expected_dy differ at index " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}