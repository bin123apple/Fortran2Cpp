#include <vector>

void DLAR2V(int N, std::vector<double>& X, std::vector<double>& Y, std::vector<double>& Z, int INCX, const std::vector<double>& C, const std::vector<double>& S, int INCC) {
    int IX = 0;
    int IC = 0;

    for (int I = 0; I < N; ++I) {
        double XI = X[IX];
        double YI = Y[IX];
        double ZI = Z[IX];
        double CI = C[IC];
        double SI = S[IC];
        
        double T1 = SI * ZI;
        double T2 = CI * ZI;
        double T3 = T2 - SI * XI;
        double T4 = T2 + SI * YI;
        double T5 = CI * XI + T1;
        double T6 = CI * YI - T1;
        
        X[IX] = CI * T5 + SI * T4;
        Y[IX] = CI * T6 - SI * T3;
        Z[IX] = CI * T4 - SI * T5;

        IX += INCX;
        IC += INCC;
    }
}