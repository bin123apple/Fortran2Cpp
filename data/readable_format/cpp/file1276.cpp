#include <gtest/gtest.h>
#include <iostream>

// Mock functions to simulate memory allocation and deallocation
void allocateMemory(int& allocBytes, int& garbageBytes) {
    // Mock increase in allocated bytes and garbage bytes
    allocBytes += 10;
    garbageBytes += 5;
}

void deallocateMemory(int& allocBytes, int& garbageBytes) {
    // Mock decrease in allocated and garbage bytes
    allocBytes -= 10;
    garbageBytes -= 5;
}

TEST(MemoryManagementTest, AllocationAndDeallocation) {
    int allocBytes = 100; // Initial mock allocated bytes
    int garbageBytes = 50; // Initial mock garbage bytes

    allocateMemory(allocBytes, garbageBytes);
    EXPECT_EQ(allocBytes, 110);
    EXPECT_EQ(garbageBytes, 55);

    deallocateMemory(allocBytes, garbageBytes);
    EXPECT_EQ(allocBytes, 100);
    EXPECT_EQ(garbageBytes, 50);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}