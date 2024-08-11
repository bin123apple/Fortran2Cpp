#include <iostream>
#include <complex>

void CLAR2V(int N, std::complex<float>* X, std::complex<float>* Y, std::complex<float>* Z, int INCX, float* C, std::complex<float>* S, int INCC) {
    int IX = 0;
    int IC = 0;
    for (int I = 0; I < N; I++) {
        float XI = std::real(X[IX]);
        float YI = std::real(Y[IX]);
        std::complex<float> ZI = Z[IX];
        float ZIR = std::real(ZI);
        float ZII = std::imag(ZI);
        float CI = C[IC];
        std::complex<float> SI = S[IC];
        float SIR = std::real(SI);
        float SII = std::imag(SI);
        float T1R = SIR * ZIR - SII * ZII;
        float T1I = SIR * ZII + SII * ZIR;
        std::complex<float> T2 = CI * ZI;
        std::complex<float> T3 = T2 - std::conj(SI) * XI;
        std::complex<float> T4 = std::conj(T2) + SI * YI;
        float T5 = CI * XI + T1R;
        float T6 = CI * YI - T1R;
        X[IX] = CI * T5 + (SIR * std::real(T4) + SII * std::imag(T4));
        Y[IX] = CI * T6 - (SIR * std::real(T3) - SII * std::imag(T3));
        Z[IX] = CI * T3 + std::conj(SI) * std::complex<float>(T6, T1I);
        IX += INCX;
        IC += INCC;
    }
}

int main() {
    const int N = 3;
    std::complex<float> X[N] = { {1, 2}, {2, 4}, {3, 6} };
    std::complex<float> Y[N] = { {2, 1}, {4, 2}, {6, 3} };
    std::complex<float> Z[N] = { {3, 2}, {6, 4}, {9, 6} };
    float C[N] = { 1.0f, 0.5f, 0.25f };
    std::complex<float> S[N] = { {0.5, 0.5}, {0.5, 0.5}, {0.5, 0.5} };
    int INCX = 1, INCC = 1;

    CLAR2V(N, X, Y, Z, INCX, C, S, INCC);

    for (int i = 0; i < N; ++i) {
        std::cout << "X[" << i << "] = " << X[i] << std::endl;
        std::cout << "Y[" << i << "] = " << Y[i] << std::endl;
        std::cout << "Z[" << i << "] = " << Z[i] << std::endl;
    }

    return 0;
}