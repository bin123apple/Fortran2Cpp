#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>

enum ModuleDefs { SEASINIT = 1, RATE = 2 };

struct MulchType {
    float MULCHMASS = 0.0;
    float MULCHCOVER = 0.0;
    float MULCHTHICK = 0.0;
    float MULCHWAT = 0.0;
    float MULCH_AM = 0.0;
    float MUL_EXTFAC = 0.0;
    float MULCHEVAP = 0.0; // Assuming this is the target variable to store the result
};

class ModuleData {
public:
    void MulchEvap(int DYNAMIC, MulchType& MULCH, float EOS, float& EM) {
        float AM, EOM, EXTFAC, MAI;
        float MULCHCOVER, MULCHMASS, MULCHTHICK, MULCHWAT;
        float EM2, EOS2, EOS3;

        if (DYNAMIC == SEASINIT) {
            EM = 0.0;
        } else if (DYNAMIC == RATE) {
            MULCHMASS = MULCH.MULCHMASS;
            MULCHCOVER = MULCH.MULCHCOVER;
            MULCHTHICK = MULCH.MULCHTHICK;
            MULCHWAT = MULCH.MULCHWAT;
            AM = MULCH.MULCH_AM;
            EXTFAC = MULCH.MUL_EXTFAC;

            if (MULCHCOVER > 1.E-6f) {
                MAI = (AM * 1.E-5f * MULCHMASS) / MULCHCOVER;
            } else {
                MAI = 0.0f;
            }

            EOM = EOS * (1.0f - exp(-EXTFAC * MAI));
            EM2 = std::min(EOM, MULCHWAT * 0.85f);
            EM2 = std::max(EM2, 0.0f) * MULCHCOVER;
            EOS2 = EOS - EM2;
            EOS3 = EOS * exp(-EXTFAC * MAI) * MULCHCOVER + EOS * (1.0f - MULCHCOVER);
            EOS3 = std::min(EOS2, EOS3);

            EM = EM2;
            EOS = EOS3;
        }

        MULCH.MULCHEVAP = EM;
    }
};

void testEvaporation() {
    ModuleData moduleData;
    MulchType mulch;
    float EM, EOS = 5.0;
    int DYNAMIC = RATE;

    // Set up a test case
    mulch.MULCHMASS = 2.0f;
    mulch.MULCHCOVER = 0.5f;
    mulch.MULCHTHICK = 0.1f;
    mulch.MULCHWAT = 1.0f;
    mulch.MULCH_AM = 0.05f;
    mulch.MUL_EXTFAC = 2.0f;

    // Perform the test
    moduleData.MulchEvap(DYNAMIC, mulch, EOS, EM);

    // Simple assertion to check if the function potentially gives expected behavior
    std::cout << "Evaporation (EM): " << EM << std::endl;
    assert(EM >= 0.0f);  // A basic check to ensure EM is calculated to a non-negative value
    
    // Note: For a thorough test, compare EM with an expected value based on manual calculations or known results.
}

int main() {
    testEvaporation();
    std::cout << "All tests passed." << std::endl;
    return 0;
}