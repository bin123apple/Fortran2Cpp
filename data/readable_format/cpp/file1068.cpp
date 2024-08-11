#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Define the FittingMod class directly in this file instead of a separate header.
class FittingMod {
public:
    int* ntrace2 = nullptr;
    int* nfit2 = nullptr;
    int* ilinkpsf2 = nullptr;
    int* nline2 = nullptr;
    std::vector<int> isol2;
    std::vector<double> line2;
    std::vector<double> sol2;

    FittingMod() = default;

    ~FittingMod() {
        delete ntrace2;
        delete nfit2;
        delete ilinkpsf2;
        delete nline2;
    }

    // Other member functions for manipulating the data can be added here.
};

// This test case assumes you have Google Test set up in your project.
TEST(FittingModTest, BasicTest) {
    FittingMod fm;

    // Directly assigning the values to the pointers and vectors.
    fm.ntrace2 = new int(5);
    fm.nfit2 = new int(10);
    fm.ilinkpsf2 = new int(2);
    fm.nline2 = new int(3);

    fm.isol2 = {1, 2, 3, 4, 5};
    fm.line2 = {1.0, 2.0, 3.0};
    fm.sol2 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    EXPECT_EQ(*fm.ntrace2, 5);
    EXPECT_EQ(*fm.nfit2, 10);
    EXPECT_EQ(*fm.ilinkpsf2, 2);
    EXPECT_EQ(*fm.nline2, 3);
    EXPECT_EQ(fm.isol2.size(), 5);
    EXPECT_EQ(fm.line2.size(), 3);
    EXPECT_EQ(fm.sol2.size(), 10);

    // Cleanup is handled by the destructor.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}