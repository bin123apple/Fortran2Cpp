#include <iostream>
#include <cmath> // For std::pow
#include <cassert> // For assert

// Assuming the CKM functionality is as follows:
class CKM {
public:
    double V_ud, V_us, V_ub, V_cd, V_cs, V_cb, V_td, V_ts, V_tb;
    double V_ud2, V_us2, V_ub2, V_cd2, V_cs2, V_cb2, V_td2, V_ts2, V_tb2;
    std::string InCKM;

    void SetCKM(double Vud, double Vus, double Vub, double Vcd, double Vcs, double Vcb, double Vtd, double Vts, double Vtb) {
        V_ud = Vud; V_us = Vus; V_ub = Vub;
        V_cd = Vcd; V_cs = Vcs; V_cb = Vcb;
        V_td = Vtd; V_ts = Vts; V_tb = Vtb;

        V_ud2 = std::pow(V_ud, 2);
        V_us2 = std::pow(V_us, 2);
        V_ub2 = std::pow(V_ub, 2);
        V_cd2 = std::pow(V_cd, 2);
        V_cs2 = std::pow(V_cs, 2);
        V_cb2 = std::pow(V_cb, 2);
        V_td2 = std::pow(V_td, 2);
        V_ts2 = std::pow(V_ts, 2);
        V_tb2 = std::pow(V_tb, 2);

        InCKM = "done";
    }
};

// Simple test function
void TestCKM() {
    CKM ckm;
    ckm.SetCKM(0.974, 0.225, 0.003, 0.225, 0.973, 0.041, 0.009, 0.040, 0.999);

    assert(ckm.V_ud2 == 0.974 * 0.974);
    assert(ckm.V_us2 == 0.225 * 0.225);
    // Add more assertions as needed to validate functionality
    assert(ckm.InCKM == "done");

    std::cout << "All tests passed." << std::endl;
}

int main() {
    TestCKM(); // Run the test
    return 0;
}