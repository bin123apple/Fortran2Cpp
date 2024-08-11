#include <iostream>
#include <cmath>
#include <vector>

const int NF = 55;
float CIA[7][NF]; // This will be initialized similarly to the Fortran version.
float CPR[NF];
float tempgrid[7] = {100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0};

void interpco2cia(float Temp) {
    float tempr = Temp;
    int MS = 8, MS1;
    float FX, Tnum, Tden;

    for (int M = 0; M < 7; ++M) {
        if (tempr < tempgrid[M]) {
            MS = M + 1;
            break;
        }
    }

    if (MS <= 1) {
        MS1 = MS;
        FX = 1.0f;
    } else if (MS >= 8) {
        MS = MS - 1;
        MS1 = MS;
        FX = 1.0f;
    } else {
        MS1 = MS - 1;
        Tnum = tempr - tempgrid[MS1 - 1];
        Tden = tempgrid[MS - 1] - tempgrid[MS1 - 1];
        FX = Tnum / Tden;
    }

    for (int IK = 0; IK < NF; ++IK) {
        float CIAMS1L = log(CIA[MS1 - 1][IK]);
        float CIAMSL = log(CIA[MS - 1][IK]);
        float CPRL = CIAMS1L + FX * (CIAMSL - CIAMS1L);
        CPR[IK] = exp(CPRL);
    }
}

int main() {
    // Initialize CIA with a simple pattern for testing
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < NF; ++j) {
            CIA[i][j] = 1.0; // Simplified initialization
        }
    }

    std::vector<float> testTemperatures = {100.0, 250.0, 400.0};
    for (float temp : testTemperatures) {
        interpco2cia(temp);
        std::cout << "Temperature = " << temp << std::endl;
        for (int i = 0; i < 5; ++i) {
            std::cout << "CPR[" << i << "] = " << CPR[i] << std::endl;
        }
        std::cout << "----------" << std::endl;
    }

    return 0;
}