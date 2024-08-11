#include <iostream>
#include <cmath>

// Assuming the necessary variables are defined globally for simplicity
namespace MOD_EOS_Vars {
    const double mu0 = 1.0;
    const double Tref = 1.0;
    const double Ts = 2.0;
    const double ExpoSuth = 0.5;
    const double cSuth = 0.5;
}

// The muSuth function definition
double muSuth(double T) {
    using namespace MOD_EOS_Vars;
    double TnoDim = T * Tref;
    if (TnoDim >= Ts) {
        return mu0 * std::pow(TnoDim, ExpoSuth) * (1 + Ts) / (TnoDim + Ts);
    } else {
        return mu0 * TnoDim * cSuth;
    }
}

// Function to test the muSuth function
void testMuSuth(double testTemperature, double expected) {
    double result = muSuth(testTemperature);
    std::cout << "Testing at T=" << testTemperature << " - Expected: " << expected << ", Got: " << result;
    if (std::abs(result - expected) < 0.0001) {
        std::cout << " [PASS]" << std::endl;
    } else {
        std::cout << " [FAIL]" << std::endl;
    }
}

int main() {
    // Example test cases for the muSuth function
    std::cout << "muSuth Function Tests" << std::endl;

    // Test case 1: TnoDim < Ts
    double testTemperature = 1.5;
    double expected = MOD_EOS_Vars::mu0 * testTemperature * MOD_EOS_Vars::Tref * MOD_EOS_Vars::cSuth;
    testMuSuth(testTemperature, expected);

    // Test case 2: TnoDim >= Ts
    testTemperature = 3.0;
    expected = MOD_EOS_Vars::mu0 * std::pow(testTemperature * MOD_EOS_Vars::Tref, MOD_EOS_Vars::ExpoSuth) * (1 + MOD_EOS_Vars::Ts) / (testTemperature * MOD_EOS_Vars::Tref + MOD_EOS_Vars::Ts);
    testMuSuth(testTemperature, expected);

    return 0;
}