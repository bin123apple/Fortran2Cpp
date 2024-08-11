#include <gtest/gtest.h>
#include <functional>

// Identity function: lambda x:A. x
auto identity = [](auto x) -> decltype(x) {
    return x;
};

// Higher-order function: lambda f:Rec X.A->A. lambda x:A. f x
auto higher_order = [](const std::function<int(int)>& f) -> std::function<int(int)> {
    return [f](int x) -> int {
        return f(x);
    };
};

// Unit tests
TEST(LambdaFunctionsTest, IdentityFunction) {
    EXPECT_EQ(identity(42), 42);
    EXPECT_EQ(identity(-1), -1);
    EXPECT_EQ(identity(0), 0);
}

TEST(LambdaFunctionsTest, HigherOrderFunction) {
    auto increment_function = higher_order(std::function<int(int)>([](int x) -> int { return x + 1; }));
    EXPECT_EQ(increment_function(41), 42);
    EXPECT_EQ(increment_function(0), 1);
    EXPECT_EQ(increment_function(-1), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}