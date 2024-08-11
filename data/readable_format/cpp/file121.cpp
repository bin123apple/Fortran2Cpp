#include <iostream>
#include <array>
#include <vector>
#include <gtest/gtest.h>

class esp_C {
public:
    int nesp, idip, iz, ipx, isc, is_esp, icd, ipe, npr, ic, ip, ncc;
    double dens, scale, cf, rms, rrms, dx, dy, dz, den;
    std::array<std::array<double, 822>, 9> fv;
    std::array<double, 98> dex; // Adjusted for C++ 0-based indexing
    std::array<double, 3> tf = {33.0, 37.0, 41.0};

    std::vector<int> ind, itemp, ird, indc;
    std::vector<std::vector<int>> iam;

    std::vector<double> cc, ex, temp, rad, es, b_esp, esp_array, cesp, cespml, al, qesp, td, dx_array, dy_array, dz_array;
    std::vector<double> ptd, pexs, pce, pexpn, pewcx, pewcy, pewcz, pf0, pf1, pf2, pmtd, fc, qsc;

    std::vector<std::vector<double>> cespm, cen, potpc, co, potpt, ovl, cespm2, a2, exs, ce, expn, ewcx, ewcy, ewcz;
    std::vector<std::vector<double>> f0, f1, u_esp, rnai, rnai1, rnai2, espi, exsr;

    std::vector<std::vector<bool>> cequiv;
};

// Test Fixture for Google Test
class EspCTest : public ::testing::Test {
protected:
    esp_C obj;
};

TEST_F(EspCTest, VariableTest) {
    obj.nesp = 10;
    EXPECT_EQ(obj.nesp, 10);
}

TEST_F(EspCTest, StaticArrayInitialization) {
    EXPECT_DOUBLE_EQ(obj.tf[0], 33.0);
    EXPECT_DOUBLE_EQ(obj.tf[1], 37.0);
    EXPECT_DOUBLE_EQ(obj.tf[2], 41.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}