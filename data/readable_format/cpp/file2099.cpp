#include <iostream>
#include <cstdint>
#include <gtest/gtest.h>

class Fibonacci {
public:
    static int64_t fib_naive(int n) {
        if (n < 2) {
            return n;
        } else {
            return fib_naive(n - 2) + fib_naive(n - 1);
        }
    }

    static int64_t fib_iter(int n) {
        int64_t a = 0;
        int64_t b = 1;
        for (int i = 1; i <= n; ++i) {
            int64_t tmp = b;
            b = a + b;
            a = tmp;
        }
        return a;
    }
};

TEST(FibonacciTest, TestNaiveAndIter) {
    std::pair<int, int64_t> test_cases[] = {
        {0, 0}, {1, 1}, {2, 1}, {3, 2}, {4, 3},
        {5, 5}, {10, 55}, {20, 6765}, {30, 832040}, {40, 102334155}
    };

    for (auto& test_case : test_cases) {
        EXPECT_EQ(Fibonacci::fib_naive(test_case.first), test_case.second)
            << "Failed at fib_naive with n = " << test_case.first;
        EXPECT_EQ(Fibonacci::fib_iter(test_case.first), test_case.second)
            << "Failed at fib_iter with n = " << test_case.first;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}