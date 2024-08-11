#include <vector>
#include <gtest/gtest.h>

// Assuming the size of rls and ils as per the common blocks
const int lenrls = 218;
const int lenils = 39;

// Global variables as a replacement for Fortran common blocks
double rls[lenrls];
int ils[lenils];
int ieh[2];

// The srcom function translated to C++
void srcom(std::vector<double>& rsav, std::vector<int>& isav, int job) {
    if (job == 2) {
        for (int i = 0; i < lenrls; ++i) {
            rls[i] = rsav[i];
        }
        for (int i = 0; i < lenils; ++i) {
            ils[i] = isav[i];
        }
        ieh[0] = isav[lenils]; // Adjusted for 0-based indexing
        ieh[1] = isav[lenils + 1];
    } else {
        for (int i = 0; i < lenrls; ++i) {
            rsav[i] = rls[i];
        }
        for (int i = 0; i < lenils; ++i) {
            isav[i] = ils[i];
        }
        isav[lenils] = ieh[0]; // Adjusted for 0-based indexing
        isav[lenils + 1] = ieh[1];
    }
}

// Unit tests using Google Test
TEST(SrcomTest, Job1) {
    std::vector<double> rsav(218, 0);
    std::vector<int> isav(39 + 2, 0); // +2 for ieh[1] and ieh[2]
    int job = 1;

    // Initialize test data
    for (int i = 0; i < 218; ++i) {
        rsav[i] = i * 0.5;
    }
    for (int i = 0; i < 39 + 2; ++i) {
        isav[i] = -i;
    }

    // Run the function
    srcom(rsav, isav, job);

    // Example check (extend with more comprehensive checks)
    EXPECT_EQ(isav[39], 0);
    EXPECT_EQ(isav[40], 0);
}

TEST(SrcomTest, Job2) {
    std::vector<double> rsav(218, 0);
    std::vector<int> isav(39 + 2, 0);
    int job = 2;

    // Initialize test data similarly...
    // Run the function
    srcom(rsav, isav, job);

    // Example check (extend with more comprehensive checks)
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}