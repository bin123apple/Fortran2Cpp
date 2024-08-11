#include <iostream>
#include <cassert>

struct SharedMemory {
    union {
        int nums[2];
        int numse[4];
    };
    int& numx = nums[1];
};

SharedMemory scr;

void simulateMainLogic() {
    for (int i = 0; i < 4; ++i) {
        scr.numse[i] = 10 + i + 1;
    }
}

void runTest() {
    int expectedNums[2] = {11, 12};
    int expectedNumse[4] = {11, 12, 13, 14};
    int expectedNumx = 12; // Correct expectation based on Fortran's behavior and memory layout

    simulateMainLogic();

    for (int i = 0; i < 2; ++i) {
        assert(scr.nums[i] == expectedNums[i]);
    }

    for (int i = 0; i < 4; ++i) {
        assert(scr.numse[i] == expectedNumse[i]);
    }

    assert(scr.numx == expectedNumx);

    std::cout << "C++ tests passed." << std::endl;
}

int main() {
    runTest();
    return 0;
}