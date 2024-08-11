#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>

void sncndn(double UU, double EMMC, double& SN, double& CN, double& DN) {
    const double CA = .0003;
    double EMC = EMMC;
    double U = UU;
    bool BO = false;
    std::array<double, 13> EM, EN;
    double D, A, C, B;
    int L;

    if (EMC != 0.0) {
        BO = (EMC < 0.0);
        if (BO) {
            D = 1.0 - EMC;
            EMC = -EMC / D;
            D = sqrt(D);
            U *= D;
        }
        A = 1.0;
        DN = 1.0;
        for (int I = 0; I < 13; ++I) {
            L = I;
            EM[I] = A;
            EMC = sqrt(EMC);
            EN[I] = EMC;
            C = 0.5 * (A + EMC);
            if (fabs(A - EMC) <= CA * A) break;
            EMC *= A;
            A = C;
        }
        U *= C;
        SN = sin(U);
        CN = cos(U);
        if (SN != 0.0) {
            A = CN / SN;
            C *= A;
            for (int II = L; II >= 0; --II) {
                B = EM[II];
                A *= C;
                C *= DN;
                DN = (EN[II] + A) / (B + A);
                A = C / B;
            }
            A = 1.0 / sqrt(C * C + 1.0);
            if (SN < 0.0) {
                SN = -A;
            } else {
                SN = A;
            }
            CN = C * SN;
        }
        if (BO) {
            A = DN;
            DN = CN;
            CN = A;
            SN /= D;
        }
    } else {
        CN = 1.0 / cosh(U);
        DN = CN;
        SN = tanh(U);
    }
}

void testSNCNDN(double UU, double EMMC) {
    double SN, CN, DN;
    sncndn(UU, EMMC, SN, CN, DN);
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Testing with UU = " << UU << ", EMMC = " << EMMC << std::endl;
    std::cout << "Results: SN = " << SN << ", CN = " << CN << ", DN = " << DN << std::endl;
    std::cout << "---------------------------" << std::endl;
}

int main() {
    // Define test cases
    testSNCNDN(0.0, 0.0);
    testSNCNDN(1.0, 0.5);
    testSNCNDN(1.57, -0.5);

    return 0;
}