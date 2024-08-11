#include <iostream>
#include <cmath>
#include <algorithm>

void SLAS2(float F, float G, float H, float &SSMIN, float &SSMAX) {
    const float ZERO = 0.0f;
    const float ONE = 1.0f;
    const float TWO = 2.0f;
    float AS, AT, AU, C, FA, FHMN, FHMX, GA, HA;
    
    FA = std::abs(F);
    GA = std::abs(G);
    HA = std::abs(H);
    FHMN = std::min(FA, HA);
    FHMX = std::max(FA, HA);
    
    if (FHMN == ZERO) {
        SSMIN = ZERO;
        if (FHMX == ZERO) {
            SSMAX = GA;
        } else {
            SSMAX = std::max(FHMX, GA) * std::sqrt(ONE + std::pow(std::min(FHMX, GA) / std::max(FHMX, GA), 2));
        }
    } else {
        if (GA < FHMX) {
            AS = ONE + FHMN / FHMX;
            AT = (FHMX - FHMN) / FHMX;
            AU = std::pow(GA / FHMX, 2);
            C = TWO / (std::sqrt(AS*AS + AU) + std::sqrt(AT*AT + AU));
            SSMIN = FHMN * C;
            SSMAX = FHMX / C;
        } else {
            AU = FHMX / GA;
            if (AU == ZERO) {
                SSMIN = (FHMN * FHMX) / GA;
                SSMAX = GA;
            } else {
                AS = ONE + FHMN / FHMX;
                AT = (FHMX - FHMN) / FHMX;
                C = ONE / (std::sqrt(ONE + std::pow(AS * AU, 2)) + std::sqrt(ONE + std::pow(AT * AU, 2)));
                SSMIN = (FHMN * C) * AU;
                SSMIN += SSMIN;
                SSMAX = GA / (C + C);
            }
        }
    }
}

void Test(float F, float G, float H) {
    float SSMIN, SSMAX;
    SLAS2(F, G, H, SSMIN, SSMAX);
    std::cout << "F=" << F << " G=" << G << " H=" << H << std::endl;
    std::cout << "SSMIN=" << SSMIN << " SSMAX=" << SSMAX << std::endl;
    std::cout << "-------------------" << std::endl;
}

int main() {
    // Test 1: All zeros
    Test(0.0f, 0.0f, 0.0f);

    // Test 2: One significantly larger
    Test(100.0f, 0.1f, 0.1f);

    // Test 3: Similar magnitude, different signs
    Test(-1.0f, 1.0f, -1.0f);

    return 0;
}