#include <iostream>
#include <vector>

// Define the OCTANT1 function directly in this file
void OCTANT1(const std::vector<std::vector<float>>& A_IN,
             const std::vector<std::vector<float>>& SD_A_IN,
             int MAXX_IN, int MAXY_IN, int NX, int NY, float BADDATA,
             int MAX_SEARCH_RADIUS, int MAX_VALUES_PER_OCTANT,
             int IX, int IY, int& POINTS_FOUND,
             std::vector<int>& IX_FOUND, std::vector<int>& IY_FOUND) {
    POINTS_FOUND = 0;
    for (int IY_SEARCH = IY + 1; IY_SEARCH <= IY + MAX_SEARCH_RADIUS && IY_SEARCH <= NY; ++IY_SEARCH) {
        for (int IX_SEARCH = IX; IX_SEARCH <= IX + IY_SEARCH - IY - 1 && IX_SEARCH <= NX; ++IX_SEARCH) {
            if (A_IN[IX_SEARCH - 1][IY_SEARCH - 1] != BADDATA && SD_A_IN[IX_SEARCH - 1][IY_SEARCH - 1] != BADDATA) {
                if (POINTS_FOUND < MAX_VALUES_PER_OCTANT) {
                    IX_FOUND.push_back(IX_SEARCH);
                    IY_FOUND.push_back(IY_SEARCH);
                    POINTS_FOUND++;
                } else {
                    return;
                }
            }
        }
    }
}

int main() {
    const int MAXX_IN = 10, MAXY_IN = 10;
    std::vector<std::vector<float>> A_IN(MAXX_IN, std::vector<float>(MAXY_IN));
    std::vector<std::vector<float>> SD_A_IN(MAXX_IN, std::vector<float>(MAXY_IN));
    float BADDATA = -999.0f;
    int IX = 1, IY = 1;
    int POINTS_FOUND;
    std::vector<int> IX_FOUND, IY_FOUND; // No need for pre-sizing

    // Initialize data and parameters
    for (int i = 0; i < MAXX_IN; ++i) {
        for (int j = 0; j < MAXY_IN; ++j) {
            A_IN[i][j] = static_cast<float>(i + j + 2); // +2 to adjust for 0-based indexing
            SD_A_IN[i][j] = static_cast<float>(i + j + 2);
        }
    }
    A_IN[2][3] = BADDATA; // Adjusted for 0-based indexing
    SD_A_IN[4][4] = BADDATA;

    OCTANT1(A_IN, SD_A_IN, MAXX_IN, MAXY_IN, MAXX_IN, MAXY_IN, BADDATA, 5, 5, IX, IY, POINTS_FOUND, IX_FOUND, IY_FOUND);

    // Output results
    std::cout << "Points found: " << POINTS_FOUND << std::endl;
    for (int i = 0; i < POINTS_FOUND; ++i) {
        std::cout << "Point: " << IX_FOUND[i] << ", " << IY_FOUND[i] << std::endl;
    }

    return 0;
}