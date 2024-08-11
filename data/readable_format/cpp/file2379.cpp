#include <iostream>
#include <vector>
#include <cassert>

void OSRCHM(int N, const std::vector<int>& IARRAY, int INC, int ITARGET,
            int MASK, int SHIFT, int& INDEX, int& IWHERE, int& INUM) {
    if (N < 0) {
        INDEX = 0;
        IWHERE = 0;
        return;
    }

    int j = 1;
    if (INC < 0) {
        j = N * (-INC);
    }

    for (int i = 1; i <= N; ++i) {
        int shifted_value = (IARRAY[j - 1] >> SHIFT) & MASK;
        if (shifted_value > ITARGET) {
            INDEX = N + 1;
            IWHERE = i;
            INUM = 0;
            return;
        }
        if (shifted_value == ITARGET) {
            INDEX = i;
            IWHERE = i;
            if (INUM == 0) {
                INUM = 1;
                return;
            }
            INUM = 1;
            for (int k = i + 1; k <= N; ++k) {
                j = j + INC;
                if (j > N) break; // Fix to prevent out-of-bounds access
                shifted_value = (IARRAY[j - 1] >> SHIFT) & MASK;
                if (shifted_value != ITARGET) {
                    return;
                }
                INUM = INUM + 1;
            }
            return;
        }
        j = j + INC;
    }

    INDEX = N + 1;
    IWHERE = N + 1;
    INUM = 0;
}

void test_osrchm() {
    int N = 5;
    std::vector<int> IARRAY = {10, 20, 30, 40, 50};
    int INC = 1;
    int ITARGET = 20;
    int MASK = 0xFFFF;
    int SHIFT = 0;
    int INDEX = 0;
    int IWHERE = 0;
    int INUM = 0;

    OSRCHM(N, IARRAY, INC, ITARGET, MASK, SHIFT, INDEX, IWHERE, INUM);

    // Check results
    assert(INDEX == 2);
    assert(IWHERE == 2);
    assert(INUM == 1);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_osrchm();
    return 0;
}