#include <iostream>
#include <vector>

void TCOPY(const std::vector<std::vector<short>>& KWHOLE, 
           std::vector<std::vector<float>>& PART, 
           int IX1, int IY1, int IX2, int IY2, 
           float BS, float BZ, int INVAL, int& NINVAL, int KADD) {

    int J1 = 0;
    for (int J = IY1; J <= IY2; ++J) {
        int I1 = 0;
        for (int I = IX1; I <= IX2; ++I) {
            short L = KWHOLE[J][I];
            float S = static_cast<float>(L) * BS + BZ;
            if (L == INVAL) {
                NINVAL++;
            }
            if (KADD == 0) {
                PART[J1][I1] = S;
            } else {
                PART[J1][I1] += S;
            }
            I1++;
        }
        J1++;
    }
}

int main() {
    const int n = 5, m = 5, n1 = 3, m1 = 3;
    std::vector<std::vector<short>> KWHOLE = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    std::vector<std::vector<float>> PART(n1, std::vector<float>(m1, 0.0f));
    int IX1 = 1, IY1 = 1, IX2 = 3, IY2 = 3; // Adjusted for 0-based index
    float BS = 1.5, BZ = 2.0;
    int INVAL = 13, NINVAL = 0, KADD = 0;

    TCOPY(KWHOLE, PART, IX1, IY1, IX2, IY2, BS, BZ, INVAL, NINVAL, KADD);

    std::cout << "PART:" << std::endl;
    for (const auto& row : PART) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "NINVAL: " << NINVAL << std::endl;

    return 0;
}