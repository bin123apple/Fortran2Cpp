#include <iostream>
#include <algorithm>

// Assuming P, Q, W, NDS have predefined values
const int P = 2, Q = 2, W = 2, NDS = 2;

void ASSEMBLYBBAR(int NZE, double* MA, int ma_dim, double* MC, int mc_dim, double* MV, int mv_dim) {
    double sumMA = 0, sumMC = 0, sumMV = 0;
    for (int i = 0; i < ma_dim; ++i) sumMA += MA[i];
    for (int i = 0; i < mc_dim; ++i) sumMC += MC[i];
    for (int i = 0; i < mv_dim; ++i) sumMV += MV[i];
    std::cout << "Sum of MA: " << sumMA << std::endl;
    std::cout << "Sum of MC: " << sumMC << std::endl;
    std::cout << "Sum of MV: " << sumMV << std::endl;
}

int main() {
    const int NZE = 10;
    const int ma_dim = (P+1)*(Q+1)*(W+1)*NDS * ((P+1)*(Q+1)*(W+1)*NDS);
    const int mc_dim = ((P+1)*(Q+1)*(W+1)*NDS) * (P*Q*W);
    const int mv_dim = (P*Q*W) * (P*Q*W);

    double* MA = new double[ma_dim];
    double* MC = new double[mc_dim];
    double* MV = new double[mv_dim];

    std::fill_n(MA, ma_dim, 1.0);
    std::fill_n(MC, mc_dim, 2.0);
    std::fill_n(MV, mv_dim, 3.0);

    ASSEMBLYBBAR(NZE, MA, ma_dim, MC, mc_dim, MV, mv_dim);

    delete[] MA;
    delete[] MC;
    delete[] MV;

    return 0;
}