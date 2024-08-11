#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>
#include <cassert>

// Define a struct to mimic the Fortran common block
struct DATTRF {
    float HP1;
    std::array<float, 48> TT123;
    std::array<float, 48> PT123;
    std::array<float, 48> WG123;
    std::array<float, 48> ETAS123;
    std::array<float, 48> ETAR123;
    int KS1;
};

// Global instance of the common block struct
DATTRF dattrf;

void TEMPDATA(float HP, const std::vector<float>& TT2A, const std::vector<float>& PT2A,
              const std::vector<float>& WG2A, const std::vector<float>& ETAS, const std::vector<float>& ETAR, int KS) {
    dattrf.KS1 = KS;
    dattrf.HP1 = HP;

    if (TT2A.size() < KS || PT2A.size() < KS || WG2A.size() < KS || ETAS.size() < KS || ETAR.size() < KS) {
        throw std::runtime_error("Input vectors are not large enough.");
    }

    for (int i = 0; i < KS; ++i) {
        dattrf.ETAS123[i] = ETAS[i];
        dattrf.ETAR123[i] = ETAR[i];
    }
}

void testTEMPDATA() {
    float HP = 1.23f;
    std::vector<float> TT2A(10), PT2A(10), WG2A(10), ETAS(10), ETAR(10);
    int KS = 10;

    for (int i = 0; i < KS; ++i) {
        TT2A[i] = static_cast<float>(i + 1);
        PT2A[i] = static_cast<float>(i + 1) + 0.1f;
        WG2A[i] = static_cast<float>(i + 1) + 0.2f;
        ETAS[i] = static_cast<float>(i + 1) + 0.3f;
        ETAR[i] = static_cast<float>(i + 1) + 0.4f;
    }

    TEMPDATA(HP, TT2A, PT2A, WG2A, ETAS, ETAR, KS);

    assert(dattrf.HP1 == HP);
    assert(dattrf.KS1 == KS);

    for (int i = 0; i < KS; ++i) {
        assert(dattrf.ETAS123[i] == ETAS[i]);
        assert(dattrf.ETAR123[i] == ETAR[i]);
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testTEMPDATA();
    return 0;
}