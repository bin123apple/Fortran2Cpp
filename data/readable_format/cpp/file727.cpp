#include <complex>
using namespace std;

void CLASCL2(int M, int N, float D[], complex<float> X[], int LDX) {
    // Loop over columns
    for (int J = 0; J < N; ++J) {
        // Loop over rows
        for (int I = 0; I < M; ++I) {
            // Update the complex number at X[I, J]
            // Note: Arrays in C++ are 0-based, so we adjust indices accordingly.
            X[I + J * LDX] *= D[I];
        }
    }
}