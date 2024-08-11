#include <iostream>
#include <cmath>

void iau_JD2CAL(double DJ1, double DJ2, int &IY, int &IM, int &ID, double &FD, int &J) {
    const double DJMIN = -68569.5;
    const double DJMAX = 1e9;

    double DJ = DJ1 + DJ2;
    if (DJ < DJMIN || DJ > DJMAX) {
        J = -1;
        return;
    }

    J = 0;
    double D1 = DJ1 >= DJ2 ? DJ1 : DJ2;
    double D2 = DJ1 < DJ2 ? DJ1 : DJ2;
    D2 = D2 - 0.5;

    double F1 = std::fmod(D1, 1.0);
    double F2 = std::fmod(D2, 1.0);
    double F = std::fmod(F1 + F2, 1.0);
    if (F < 0.0) F += 1.0;
    double D = std::round(D1 - F1) + std::round(D2 - F2) + std::round(F1 + F2 - F);
    int JD = static_cast<int>(std::round(D)) + 1;

    int L = JD + 68569;
    int N = (4 * L) / 146097;
    L = L - (146097 * N + 3) / 4;
    int I = (4000 * (L + 1)) / 1461001;
    L = L - (1461 * I) / 4 + 31;
    int K = (80 * L) / 2447;
    ID = L - (2447 * K) / 80;
    L = K / 11;
    IM = K + 2 - 12 * L;
    IY = 100 * (N - 49) + I + L;

    FD = F;
}

int main() {
    double DJ1 = 2451545.0, DJ2 = 0.5;
    int IY, IM, ID, J;
    double FD;

    iau_JD2CAL(DJ1, DJ2, IY, IM, ID, FD, J);

    std::cout << "Test Case: " << IY << " " << IM << " " << ID << " " << FD << " " << J << std::endl;

    return 0;
}