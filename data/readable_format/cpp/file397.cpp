#include <cmath> // For sqrt()

void machpi(double& MACH, double PI, double kappa, double rgas) {
    double kappax, KAPPAM, PIKRIT, MA2;

    kappax = (kappa - 1) / kappa;
    KAPPAM = 2.0 / (kappa - 1.0);
    PIKRIT = std::pow((2.0 / (kappa + 1.0)), (kappa / (kappa - 1.0)));

    if (PI >= 1.0) {
        MACH = 0.0;
    } else if (PI > PIKRIT) {
        MA2 = KAPPAM * (std::pow(PI, -kappax) - 1.0);
        if (MA2 > 0.0) {
            MACH = std::sqrt(MA2);
        } else {
            MACH = 0.0;
        }
    } else if (PI > 0.0) {
        MACH = 1.0;
    } else {
        MACH = std::pow(10.0, 20.0); // Equivalent to 1.d20 in Fortran
    }
}