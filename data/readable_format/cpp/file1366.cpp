#include <iostream>
#include <gtest/gtest.h>

// Forward declarations
void work(int i, int j);
void a6_wrong();

// Definition of work
void work(int i, int j) {
    std::cout << "WORK called with I=" << i << " and J=" << j << std::endl;
}

// Definition of a6_wrong
void a6_wrong() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            work(i, j);
        }
    }
}

// Unit test for a6_wrong using Google Test
TEST(A6WrongTest, CallsWorkCorrectly) {
    // The test simply calls a6_wrong. Due to the nature of the work function, 
    // which only prints to the console, this test does not assert anything.
    // To make this test more meaningful, consider modifying 'work' to have
    // observable side effects (like modifying a static variable) that can be checked.
    a6_wrong();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}