#include <iostream>
#include <cassert>
#include <complex>
using namespace std;

void ZLASCL2(int M, int N, double* D, complex<double>* X, int LDX) {
    for (int J = 0; J < N; ++J) {
        for (int I = 0; I < M; ++I) {
            X[I + J*LDX] *= D[I];
        }
    }
}

void testZLASCL2() {
    const int M = 2, N = 2, LDX = 2;
    double D[M] = {2.0, 3.0};
    complex<double> X[LDX * N] = { {1.0, 0.0}, {2.0, 0.0}, {3.0, 0.0}, {4.0, 0.0} };

    ZLASCL2(M, N, D, X, LDX);

    assert(X[0] == complex<double>(2.0, 0.0));
    assert(X[1] == complex<double>(6.0, 0.0)); // Corrected assertion based on Fortran output
    assert(X[2] == complex<double>(6.0, 0.0));
    assert(X[3] == complex<double>(12.0, 0.0)); // Corrected assertion based on Fortran output

    cout << "All tests passed successfully." << endl;
}

int main() {
    testZLASCL2();
    return 0;
}