#include <gtest/gtest.h>
#include <vector>

// Definition of sla_PERMUT directly in this file
void sla_PERMUT(int N, std::vector<int>& ISTATE, std::vector<int>& IORDER, int& J) {
    int I, IP1, ISLOT, ISKIP;

    if (N < 1) {
        J = -1;
        return;
    } else {
        J = 0;
    }

    if (ISTATE[0] < 0) {
        ISTATE[0] = -1;
        for (I = 1; I < N; ++I) {
            ISTATE[I] = 0;
        }
    }

    ISTATE[0] += 1;

    for (I = 0; I < N; ++I) {
        if (ISTATE[I] >= I + 1) {
            ISTATE[I] = 0;
            if (I >= N - 1) {
                J = 1;
            } else {
                IP1 = I + 1;
                ISTATE[IP1] += 1;
            }
        }
    }

    for (I = 0; I < N; ++I) {
        IORDER[I] = 1;
    }

    for (I = N - 1; I >= 1; --I) {
        ISLOT = 0;
        for (ISKIP = 0; ISKIP <= ISTATE[I]; ++ISKIP) {
            ISLOT += 1;
            while (IORDER[ISLOT] > 1) {
                ISLOT += 1;
            }
        }
        IORDER[ISLOT] = I + 1;
    }
}

// Unit Test using Google Test
TEST(SlaPermutTest, BasicTest) {
    int N = 4;
    std::vector<int> ISTATE(N, -2); // Initialize ISTATE to trigger initialization
    std::vector<int> IORDER(N);
    int J;

    sla_PERMUT(N, ISTATE, IORDER, J);
    
    // Example assertion, needs to be adjusted based on the expected outcome
    ASSERT_EQ(J, 0); // This is a placeholder, adjust the expected value accordingly
    // Add more assertions here to check the contents of ISTATE and IORDER
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}