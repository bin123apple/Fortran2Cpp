#include <iostream>
#include <complex>
using namespace std;

void ZLAR2V(int N, complex<double>* X, complex<double>* Y, complex<double>* Z, int INCX, double* C, complex<double>* S, int INCC) {
    int IX = 0; // Adjusted for C++ 0-based indexing
    int IC = 0; // Adjusted for C++ 0-based indexing
    for (int I = 0; I < N; ++I) {
        double XI = real(X[IX]);
        double YI = real(Y[IX]);
        complex<double> ZI = Z[IX];
        double ZIR = real(ZI);
        double ZII = imag(ZI);
        double CI = C[IC];
        complex<double> SI = S[IC];
        double SIR = real(SI);
        double SII = imag(SI);
        double T1R = SIR*ZIR - SII*ZII;
        double T1I = SIR*ZII + SII*ZIR;
        complex<double> T2 = CI*ZI;
        complex<double> T3 = T2 - conj(SI)*XI;
        complex<double> T4 = conj(T2) + SI*YI;
        double T5 = CI*XI + T1R;
        double T6 = CI*YI - T1R;
        X[IX] = CI*T5 + (SIR*real(T4) + SII*imag(T4));
        Y[IX] = CI*T6 - (SIR*real(T3) - SII*imag(T3));
        Z[IX] = CI*T3 + conj(SI)*complex<double>(T6, T1I);
        IX += INCX;
        IC += INCC;
    }
}

int main() {
    const int N = 3;
    int INCX = 1, INCC = 1;
    double C[N] = {1.0, 2.0, 3.0};
    complex<double> S[N] = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}};
    complex<double> X[N] = {{1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}};
    complex<double> Y[N] = {{4.0, 4.0}, {5.0, 5.0}, {6.0, 6.0}};
    complex<double> Z[N] = {{7.0, 7.0}, {8.0, 8.0}, {9.0, 9.0}};

    // Call the function
    ZLAR2V(N, X, Y, Z, INCX, C, S, INCC);

    // Print output arrays
    cout << "X:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << X[i] << endl;
    }

    cout << "Y:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << Y[i] << endl;
    }

    cout << "Z:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << Z[i] << endl;
    }

    return 0;
}