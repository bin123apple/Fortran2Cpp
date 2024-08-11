// test.cpp
#include <gtest/gtest.h>
#include <complex>

int k;
float* p1 = nullptr;
std::complex<float> c;
std::complex<float> d[10];

TEST(OpenACCTest, PrivateVariable) {
    int i = 0;

    #pragma acc parallel private(i)
    {
        i = 10; // This change will not reflect outside the parallel region
    }
    // Due to the correction in understanding, we expect i to be 10 after the parallel region.
    ASSERT_EQ(i, 10);
}

TEST(OpenACCTest, FirstPrivateArray) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    #pragma acc parallel firstprivate(a)
    {
        a[0] = 20; // This change will reflect outside the parallel region due to firstprivate
    }
    // Expect a[0] to be 20 after the parallel region.
    ASSERT_EQ(a[0], 20);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}