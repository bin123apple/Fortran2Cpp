#include <cmath>
#include <gtest/gtest.h>

// Function declaration and definition
void sla_PV2UE(const double PV[6], const double DATE, const double PMASS, double U[13], int& JSTAT) {
    const double GCON = 0.01720209895;
    const double CD2S = GCON / 86400.0;
    const double RMIN = 1e-3;
    const double VMIN = 1e-3;

    double T0, CM, X, Y, Z, XD, YD, ZD, R, V2, V, ALPHA, RDV;

    T0 = DATE;

    if (PMASS < 0.0) {
        JSTAT = -1;
        return;
    }
    CM = 1.0 + PMASS;

    X = PV[0];
    Y = PV[1];
    Z = PV[2];
    XD = PV[3] / CD2S;
    YD = PV[4] / CD2S;
    ZD = PV[5] / CD2S;

    R = std::sqrt(X*X + Y*Y + Z*Z);
    V2 = XD*XD + YD*YD + ZD*ZD;
    V = std::sqrt(V2);

    if (R < RMIN) {
        JSTAT = -2;
        return;
    }
    if (V < VMIN) {
        JSTAT = -3;
        return;
    }

    ALPHA = V2 - 2.0 * CM / R;
    RDV = X*XD + Y*YD + Z*ZD;

    U[0] = CM;
    U[1] = ALPHA;
    U[2] = T0;
    U[3] = X;
    U[4] = Y;
    U[5] = Z;
    U[6] = XD;
    U[7] = YD;
    U[8] = ZD;
    U[9] = R;
    U[10] = RDV;
    U[11] = T0;
    U[12] = 0.0;

    JSTAT = 0;
}

// Google Test Unit Tests
TEST(SlaPV2UETest, BasicFunctionality) {
    double PV[6] = {1.0, 2.0, 3.0, 0.1, 0.2, 0.3};
    double DATE = 2451545.0;
    double PMASS = 1.0;
    double U[13];
    int JSTAT;

    sla_PV2UE(PV, DATE, PMASS, U, JSTAT);

    EXPECT_EQ(JSTAT, 0); // Expect JSTAT to be 0 indicating success

    // Additional checks for the values in U can be added here
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}