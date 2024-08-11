#include <vector>
#include <cmath>

void SUBTRACT_MEAN_3D(const std::vector<std::vector<std::vector<float>>>& A_IN,
                      int MAXX_IN, int MAXY_IN, int MAXZ_IN,
                      int NX, int NY, int NZ,
                      float BADDATA,
                      int MAXX_OUT, int MAXY_OUT, int MAXZ_OUT,
                      std::vector<std::vector<std::vector<float>>>& A_OUT) {
    float SUM = 0.0;
    int COUNT = 0;

    // Calculate the sum and count of valid elements
    for (int IZ = 0; IZ < NZ; ++IZ) {
        for (int IY = 0; IY < NY; ++IY) {
            for (int IX = 0; IX < NX; ++IX) {
                if (A_IN[IX][IY][IZ] != BADDATA) {
                    SUM += A_IN[IX][IY][IZ];
                    COUNT++;
                }
            }
        }
    }

    float MEAN = 0.0;
    if (COUNT != 0) {
        MEAN = SUM / static_cast<float>(COUNT);
    }

    // Subtract the mean from each valid element
    for (int IZ = 0; IZ < NZ; ++IZ) {
        for (int IY = 0; IY < NY; ++IY) {
            for (int IX = 0; IX < NX; ++IX) {
                if (A_IN[IX][IY][IZ] != BADDATA) {
                    A_OUT[IX][IY][IZ] = A_IN[IX][IY][IZ] - MEAN;
                } else {
                    A_OUT[IX][IY][IZ] = BADDATA;
                }
            }
        }
    }
}