// meshfem3d_models_broadcast.cpp
#include <iostream>
#include <string>
#include <array>

namespace MESHFEM3D_MODELS_BROADCAST__genmod {

    void MESHFEM3D_MODELS_BROADCAST(int MYRANK, const std::array<int, 3>& NSPEC,
                                    int MIN_ATTENUATION_PERIOD, int MAX_ATTENUATION_PERIOD,
                                    double R80, double R220, double R670, double RCMB, double RICB,
                                    const std::string& LOCAL_PATH) {
        std::cout << "Function MESHFEM3D_MODELS_BROADCAST called with MYRANK: " << MYRANK << std::endl
                  << "NSPEC: " << NSPEC[0] << " " << NSPEC[1] << " " << NSPEC[2] << std::endl
                  << "Period Range: " << MIN_ATTENUATION_PERIOD << " - " << MAX_ATTENUATION_PERIOD << std::endl
                  << "R Values: " << R80 << " " << R220 << " " << R670 << " " << RCMB << " " << RICB << std::endl
                  << "Local Path: " << LOCAL_PATH << std::endl;
    }

}

int main() {
    int MYRANK = 1;
    std::array<int, 3> NSPEC = {10, 20, 30};
    int MIN_ATTENUATION_PERIOD = 5;
    int MAX_ATTENUATION_PERIOD = 50;
    double R80 = 1.0, R220 = 2.2, R670 = 6.7, RCMB = 3.4, RICB = 5.6;
    std::string LOCAL_PATH = "test_path";

    MESHFEM3D_MODELS_BROADCAST__genmod::MESHFEM3D_MODELS_BROADCAST(
        MYRANK, NSPEC, MIN_ATTENUATION_PERIOD, MAX_ATTENUATION_PERIOD,
        R80, R220, R670, RCMB, RICB, LOCAL_PATH
    );

    std::cout << "C++ test completed." << std::endl;
    return 0;
}