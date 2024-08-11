#include <complex>
#include <cmath>
#include <algorithm>

void CLAESY(std::complex<double> A, std::complex<double> B, std::complex<double> C, 
            std::complex<double>& RT1, std::complex<double>& RT2, 
            std::complex<double>& EVSCAL, std::complex<double>& CS1, std::complex<double>& SN1) {
    const double ZERO = 0.0;
    const double ONE = 1.0;
    const std::complex<double> CONE(1.0, 0.0);
    const double HALF = 0.5;
    const double THRESH = 0.1;

    double BABS, EVNORM, TABS, Z;
    std::complex<double> S, T, TMP;

    if (std::abs(B) == ZERO) {
        RT1 = A;
        RT2 = C;
        if (std::abs(RT1) < std::abs(RT2)) {
            TMP = RT1;
            RT1 = RT2;
            RT2 = TMP;
            CS1 = ZERO;
            SN1 = ONE;
        } else {
            CS1 = ONE;
            SN1 = ZERO;
        }
    } else {
        S = (A + C) * HALF;
        T = (A - C) * HALF;
        BABS = std::abs(B);
        TABS = std::abs(T);
        Z = std::max(BABS, TABS);
        if (Z > ZERO)
            T = Z * std::sqrt(std::pow(T / Z, 2) + std::pow(B / Z, 2));
        RT1 = S + T;
        RT2 = S - T;
        if (std::abs(RT1) < std::abs(RT2)) {
            TMP = RT1;
            RT1 = RT2;
            RT2 = TMP;
        }
        SN1 = (RT1 - A) / B;
        TABS = std::abs(SN1);
        if (TABS > ONE) {
            T = TABS * std::sqrt(std::pow(ONE / TABS, 2) + std::pow(SN1 / TABS, 2));
        } else {
            T = std::sqrt(CONE + SN1 * SN1);
        }
        EVNORM = std::abs(T);
        if (EVNORM >= THRESH) {
            EVSCAL = CONE / T;
            CS1 = EVSCAL;
            SN1 = SN1 * EVSCAL;
        } else {
            EVSCAL = ZERO;
        }
    }
}

int main() {
    // Example usage
    std::complex<double> A(1.0, 2.0);
    std::complex<double> B(2.0, 3.0);
    std::complex<double> C(3.0, 4.0);
    std::complex<double> RT1, RT2, EVSCAL, CS1, SN1;

    CLAESY(A, B, C, RT1, RT2, EVSCAL, CS1, SN1);

    return 0;
}