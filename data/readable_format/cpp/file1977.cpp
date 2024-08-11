#include <iostream>
#include <cmath>

void sla_S2TP(double RA, double DEC, double RAZ, double DECZ, double& XI, double& ETA, int& J) {
    const double TINY = 1e-6;
    double SDECZ = std::sin(DECZ);
    double SDEC = std::sin(DEC);
    double CDECZ = std::cos(DECZ);
    double CDEC = std::cos(DEC);
    double RADIF = RA - RAZ;
    double SRADIF = std::sin(RADIF);
    double CRADIF = std::cos(RADIF);

    double DENOM = SDEC * SDECZ + CDEC * CDECZ * CRADIF;

    if (DENOM > TINY) {
        J = 0;
    } else if (DENOM >= 0.0) {
        J = 1;
        DENOM = TINY;
    } else if (DENOM > -TINY) {
        J = 2;
        DENOM = -TINY;
    } else {
        J = 3;
    }

    XI = CDEC * SRADIF / DENOM;
    ETA = (SDEC * CDECZ - CDEC * SDECZ * CRADIF) / DENOM;
}

int main() {
    double RA = 1.0, DEC = 0.5, RAZ = 0.3, DECZ = 0.4, XI, ETA;
    int J;
    sla_S2TP(RA, DEC, RAZ, DECZ, XI, ETA, J);
    std::cout << "Test - J: " << J << " XI: " << XI << " ETA: " << ETA << std::endl;

    return 0;
}