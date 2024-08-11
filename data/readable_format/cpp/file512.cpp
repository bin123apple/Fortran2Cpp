#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Define the DSRoutines class directly in this file
class DSRoutines {
public:
    void dsget(std::vector<float>& rstore, std::vector<std::vector<float>>& vertic) {
        int nrvert = 4;
        int point = 26;
        // Ensure vertic has the correct size
        vertic.resize(1);
        vertic[0].resize(nrvert);
        // Adjusting for 0-based indexing in C++
        for (int i = 0; i < nrvert; ++i) {
            vertic[0][i] = rstore[point + i]; // point+i adjusts for 0-based indexing
        }
    }
};

// Unit test for DSRoutines
TEST(DSRoutinesTest, BasicTest) {
    DSRoutines routines;
    std::vector<float> rstore(30);
    std::vector<std::vector<float>> vertic;

    // Initialize rstore with test data
    for (int i = 0; i < 30; ++i) {
        rstore[i] = i + 1; // 1-based to match Fortran example
    }

    // Call the function
    routines.dsget(rstore, vertic);

    // Expected values for vertic[0] would be {27, 28, 29, 30}
    ASSERT_EQ(vertic[0].size(), 4);
    EXPECT_FLOAT_EQ(vertic[0][0], 27);
    EXPECT_FLOAT_EQ(vertic[0][1], 28);
    EXPECT_FLOAT_EQ(vertic[0][2], 29);
    EXPECT_FLOAT_EQ(vertic[0][3], 30);
}

// Main function to run the unit tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}