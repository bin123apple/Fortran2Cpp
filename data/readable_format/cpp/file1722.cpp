// USRMAT.cpp
#include <iostream>
#include <vector>

void USRMAT(int& I, int& J, double& AIJ, int& INDCAT, const std::vector<double>& PRGOPT, const std::vector<double>& DATTRV, std::vector<int>& IFLAG) {
    if (IFLAG[0] == 1) {
        if (DATTRV[0] == 0.0) {
            I = 0;
            J = 0;
            IFLAG[0] = 3;
        } else {
            IFLAG[1] = -static_cast<int>(DATTRV[0]);
            IFLAG[2] = static_cast<int>(DATTRV[1]);
            IFLAG[3] = 3;
        }
        return;
    } else {
        J = IFLAG[1];
        I = IFLAG[2];
        int L = IFLAG[3];
        if (I == 0) {
            IFLAG[0] = 3;
            return;
        } else if (I < 0) {
            J = -I;
            I = static_cast<int>(DATTRV[L-1]);
            L += 1;
        }
        AIJ = DATTRV[L-1];
        IFLAG[1] = J;
        IFLAG[2] = static_cast<int>(DATTRV[L]);
        IFLAG[3] = L + 1;
        INDCAT = 0;
        return;
    }
}

int main() {
    int I = 0, J = 0, INDCAT = 0;
    double AIJ = 0.0;
    std::vector<double> PRGOPT = {0.0};
    std::vector<double> DATTRV = {2.0, 3.0};
    std::vector<int> IFLAG(10, 0);
    IFLAG[0] = 1;

    USRMAT(I, J, AIJ, INDCAT, PRGOPT, DATTRV, IFLAG);

    std::cout << "I: " << I << std::endl;
    std::cout << "J: " << J << std::endl;
    std::cout << "AIJ: " << AIJ << std::endl;
    std::cout << "INDCAT: " << INDCAT << std::endl;
    std::cout << "IFLAG: ";
    for (const auto& flag : IFLAG) {
        std::cout << flag << " ";
    }
    std::cout << std::endl;

    return 0;
}