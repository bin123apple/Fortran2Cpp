#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void ZMEDGE(float XZMMIN, float XZMMAX, float YZMMIN, float YZMMAX,
           std::vector<float>& XN, std::vector<float>& YN,
           std::vector<std::vector<int>>& IEDSET, int NEDGES, 
           const std::string& cdebug, int idebug) {
    int nhid = 0;

    for (int IEDG = 0; IEDG < NEDGES; ++IEDG) {
        if (IEDSET[0][IEDG] == 0) continue;

        int N1 = IEDSET[1][IEDG];
        float X1 = XN[N1];
        float Y1 = YN[N1];

        if ((X1 <= XZMMIN) || (X1 >= XZMMAX) || 
            (Y1 <= YZMMIN) || (Y1 >= YZMMAX)) {
            int N2 = IEDSET[2][IEDG];
            float X2 = XN[N2];
            float Y2 = YN[N2];

            if (((X1 <= XZMMIN) && (X2 <= XZMMIN)) ||
                ((X1 >= XZMMAX) && (X2 >= XZMMAX)) ||
                ((Y1 <= YZMMIN) && (Y2 <= YZMMIN)) ||
                ((Y1 >= YZMMAX) && (Y2 >= YZMMAX))) {
                IEDSET[0][IEDG] = 0;
                nhid++;
            }
        }
    }

    if (cdebug == "HIDDEN" && idebug >= 1) {
        std::cout << "edges outside zoom window = " << nhid << std::endl;
    }
}

int main() {
    // Example usage
    std::vector<float> XN = {0.0, 1.0, 2.0, 3.0}; // Dummy data
    std::vector<float> YN = {0.0, 1.0, 2.0, 3.0}; // Dummy data
    std::vector<std::vector<int>> IEDSET = {
        {1, 1, 1}, // Example data
        {0, 1, 2},
        {1, 2, 3}
    };
    int NEDGES = 3;
    std::string cdebug = "HIDDEN";
    int idebug = 1;

    ZMEDGE(0.5, 2.5, 0.5, 2.5, XN, YN, IEDSET, NEDGES, cdebug, idebug);

    return 0;
}