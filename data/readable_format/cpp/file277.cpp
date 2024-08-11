#include <vector>
#include <cstdint>
#include <iostream>
#include <gtest/gtest.h>

// Directly include the class definition in the .cpp file
class Mod_MBVariables {
public:
    int32_t incp;

    std::vector<double> Nslv, dNslvdxi, dNslv2dxi2;
    std::vector<double> Mslv, dMslvdeta, dMslv2deta2;
    std::vector<double> R1;
    std::vector<std::vector<double>> dR1, ddR1;
    std::vector<double> Rslv, gap;
    std::vector<std::vector<double>> dRslv, ddRslv;
    std::vector<double> Rmst;
    std::vector<std::vector<double>> dRmst, ddRmst;
    std::vector<int32_t> PTS_Active;

    std::vector<std::vector<double>> N, Na, Nb, Ta, tb;
    std::vector<std::vector<double>> Nhat, That, D, Nbar;
    std::vector<std::vector<double>> Kgeo, KG1, KG2, KG3, KG4;

    std::vector<std::vector<double>> KLM, FLM, GLM;
    std::vector<int32_t> disptempLM;
    std::vector<std::vector<double>> KeqLM, FeqLM, DispeqLM;

    std::vector<int32_t> PTS_conn;
};

// If you're using Google Test for unit testing, include the tests directly
TEST(Mod_MBVariablesTest, InitializationAndManipulation) {
    Mod_MBVariables mbVars;

    // Test simple variable initialization
    mbVars.incp = 5;

    // Test resizing and setting values for vectors
    mbVars.Nslv = {1.0, 2.0, 3.0};
    mbVars.R1.resize(2);
    mbVars.R1[0] = 0.5;
    mbVars.R1[1] = 1.5;

    EXPECT_EQ(mbVars.incp, 5);
    EXPECT_EQ(mbVars.Nslv.size(), 3);
    EXPECT_DOUBLE_EQ(mbVars.Nslv[2], 3.0);
    EXPECT_DOUBLE_EQ(mbVars.R1[1], 1.5);

    // Test resizing and setting values for vector of vectors
    mbVars.dR1.resize(2, std::vector<double>(2));
    mbVars.dR1[0][0] = 1.0;
    mbVars.dR1[1][1] = 4.0;

    mbVars.dRslv = {{0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}};

    EXPECT_DOUBLE_EQ(mbVars.dR1[1][1], 4.0);
    EXPECT_DOUBLE_EQ(mbVars.dRslv[1][2], 0.6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}