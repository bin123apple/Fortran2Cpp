#include <iostream>
#include <vector>
#include <cstdlib>
#include <gtest/gtest.h>

struct A {
    int* p = nullptr;
    int i = 3;
};

A f() {
    A fr;
    return fr;
}

void sub1(int n, std::vector<A>& x) {
    for (int j = 0; j < n; ++j) {
        x[j].p = nullptr;
        x[j].i = 3;
    }
}

void sub2(std::vector<A>& x) {
    for (auto& elem : x) {
        elem.p = nullptr;
        elem.i = 3;
    }
}

TEST(TestF, ReturnsAWithNullPAndI3) {
    A result = f();
    EXPECT_EQ(result.p, nullptr);
    EXPECT_EQ(result.i, 3);
}

TEST(TestSub1, ResetsYToDefault) {
    int tgt;
    std::vector<A> arr(3);
    arr[0].p = &tgt;
    sub1(3, arr);
    bool testPassed = true;
    for (auto& elem : arr) {
        if (elem.p != nullptr || elem.i != 3) {
            testPassed = false;
            break;
        }
    }
    EXPECT_TRUE(testPassed);
}

TEST(TestSub2, ResetsYToDefault) {
    int tgt;
    std::vector<A> arr(3);
    arr[0].p = &tgt;
    sub2(arr);
    bool testPassed = true;
    for (auto& elem : arr) {
        if (elem.p != nullptr || elem.i != 3) {
            testPassed = false;
            break;
        }
    }
    EXPECT_TRUE(testPassed);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}