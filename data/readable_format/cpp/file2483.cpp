#include <array>

void phixyzp(int is, int ic, int& ixp, int& iyp, int& izp, int level) {
    std::array<std::array<int, 12>, 8> icstate = {{
        {{0, 0, 0, 2, 4, 6, 4, 6, 2, 6, 2, 4}},
        {{1, 3, 7, 3, 3, 5, 7, 7, 5, 1, 1, 5}},
        {{2, 4, 6, 0, 2, 2, 0, 4, 4, 0, 6, 6}},
        {{3, 7, 1, 1, 5, 1, 3, 5, 3, 7, 5, 7}},
        {{4, 6, 2, 6, 6, 0, 2, 4, 0, 4, 4, 0}},
        {{5, 5, 5, 7, 1, 3, 1, 1, 3, 3, 7, 1}},
        {{6, 2, 4, 4, 4, 4, 6, 0, 6, 2, 0, 6}},
        {{7, 1, 3, 5, 7, 7, 5, 1, 1, 5, 3, 3}}
    }};

    std::array<int, 8> ixind = {0, 0, 1, 1, 1, 1, 0, 0};
    std::array<int, 8> iyind = {0, 0, 0, 0, 1, 1, 1, 1};
    std::array<int, 8> izind = {0, 1, 1, 0, 0, 1, 1, 0};

    int icp;
    if (level == 1) {
        icp = ic;
    } else {
        icp = icstate[ic][is];
    }
    ixp = ixind[icp];
    iyp = iyind[icp];
    izp = izind[icp];
}