// grview.cpp
#include <iostream>
#include <array>
#include <cassert>

const int KLFT = 0;
const int KRGT = 1;
const int KBOT = 2;
const int KTOP = 3;

void GRVIEW(float ASPECT, std::array<float, 4>& DVIEW0, std::array<float, 4>& DVIEW) {
    float OS;

    if (ASPECT >= 1.0f) {
        DVIEW[KLFT] = DVIEW0[KLFT];
        DVIEW[KRGT] = DVIEW0[KRGT];
    } else {
        OS = 0.5f * (1.0f - ASPECT) * (DVIEW0[KRGT] - DVIEW0[KLFT]);
        DVIEW[KLFT] = DVIEW0[KLFT] + OS;
        DVIEW[KRGT] = DVIEW0[KRGT] - OS;
    }

    if (ASPECT <= 1.0f) {
        DVIEW[KBOT] = DVIEW0[KBOT];
        DVIEW[KTOP] = DVIEW0[KTOP];
    } else {
        OS = 0.5f * (1.0f - 1.0f / ASPECT) * (DVIEW0[KTOP] - DVIEW0[KBOT]);
        DVIEW[KBOT] = DVIEW0[KBOT] + OS;
        DVIEW[KTOP] = DVIEW0[KTOP] - OS;
    }
}

int main() {
    std::array<float, 4> DVIEW0, DVIEW;

    // Test case 1
    float ASPECT = 1.5f;
    DVIEW0 = {0.0f, 2.0f, 0.0f, 3.0f};
    GRVIEW(ASPECT, DVIEW0, DVIEW);
    std::cout << "DVIEW (Test 1): ";
    for (auto& v : DVIEW) std::cout << v << " ";
    std::cout << std::endl;

    // Test case 2
    ASPECT = 0.75f;
    DVIEW0 = {1.0f, 3.0f, 2.0f, 4.0f};
    GRVIEW(ASPECT, DVIEW0, DVIEW);
    std::cout << "DVIEW (Test 2): ";
    for (auto& v : DVIEW) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}