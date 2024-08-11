// ELLEXT.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void ELLEXT(int XEXT, int YEXT, const std::vector<std::vector<float>>& IMAGE, int XBASE, int YBASE, int XTOP, int YTOP,
            int MAXLEV, int MAXPTS, int MAXPAR, int& NLEVEL, std::vector<float>& LOGI, std::vector<std::vector<float>>& INTEN,
            std::vector<std::vector<std::vector<float>>>& ELLARR, std::vector<int>& LEVPT, int& STATUS) {
    std::fill(LEVPT.begin(), LEVPT.end(), 0);
    for (auto& level : ELLARR) {
        for (auto& pt : level) {
            std::fill(pt.begin(), pt.end(), -9990.0f);
        }
    }

    float PIXTHR = INTEN[0][0];
    bool FULFLG = false;
    int RLEVEL = 0;

    for (int J = YBASE; J <= YTOP; ++J) {
        for (int I = XBASE; I <= XTOP; ++I) {
            float PIXVAL = IMAGE[J][I];
            if (PIXVAL >= PIXTHR) {
                for (int K = 0; K < MAXLEV; ++K) {
                    if (PIXVAL >= INTEN[0][K] && PIXVAL <= INTEN[1][K]) {
                        int PTS = LEVPT[K] + 1;
                        if (PTS <= MAXPTS) {
                            ELLARR[K][PTS-1][0] = static_cast<float>(I + 1); // Fortran to C++ index adjustment
                            ELLARR[K][PTS-1][1] = static_cast<float>(J + 1);
                            LEVPT[K] = PTS;
                            RLEVEL = std::max(K + 1, RLEVEL);
                        } else {
                            FULFLG = true;
                        }
                        break; // Match found, no need to check further levels
                    }
                }
            }
        }
    }

    NLEVEL = RLEVEL;
    STATUS = FULFLG ? 1 : 0;
}

int main() {
    int XEXT = 10, YEXT = 10, MAXLEV = 2, MAXPTS = 10, MAXPAR = 2;
    std::vector<std::vector<float>> IMAGE(YEXT, std::vector<float>(XEXT, 0.0f));
    IMAGE[4][4] = 50.0f; // Adjusted for 0-based indexing
    IMAGE[5][5] = 60.0f; // Adjusted for 0-based indexing
    int XBASE = 0, YBASE = 0, XTOP = XEXT-1, YTOP = YEXT-1, NLEVEL = MAXLEV, STATUS;
    std::vector<float> LOGI(MAXLEV, 0.0f);
    std::vector<std::vector<float>> INTEN(2, std::vector<float>(MAXLEV, 0.0f));
    INTEN[0][0] = 40.0f; INTEN[1][0] = 70.0f;
    INTEN[0][1] = 70.0f; INTEN[1][1] = 100.0f;
    std::vector<std::vector<std::vector<float>>> ELLARR(MAXLEV, std::vector<std::vector<float>>(MAXPTS, std::vector<float>(MAXPAR, -9990.0f)));
    std::vector<int> LEVPT(MAXLEV, 0);

    ELLEXT(XEXT, YEXT, IMAGE, XBASE, YBASE, XTOP, YTOP, MAXLEV, MAXPTS, MAXPAR, NLEVEL, LOGI, INTEN, ELLARR, LEVPT, STATUS);

    std::cout << "STATUS: " << STATUS << std::endl;
    std::cout << "NLEVEL: " << NLEVEL << std::endl;
    std::cout << "LEVPT: ";
    for (const auto& l : LEVPT) std::cout << l << " ";
    std::cout << std::endl << "ELLARR: " << std::endl;
    for (int k = 0; k < NLEVEL; ++k) {
        std::cout << "Level " << k + 1 << ":" << std::endl;
        for (int i = 0; i < LEVPT[k]; ++i) {
            std::cout << "(" << ELLARR[k][i][0] << ", " << ELLARR[k][i][1] << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}