#include <iostream>

void LOADF(float* A, float* B, float* R, int N1, int N2, int N3, int N4, int N5) {
    // Assuming A is a 2D array with dimensions [N1][N2]
    // Assuming B is a 2D array with dimensions [N3][N4]
    // Assuming R is a 3D array with dimensions [3][2][N5]
    for(int i = 0; i < N5; i++) {
        *(R + 0 * 2 * N5 + 0 * N5 + i) = *(B + 0 * N4 + i); // R[0][0][i] = B[0][i]
        *(R + 1 * 2 * N5 + 0 * N5 + i) = *(B + 1 * N4 + i); // R[1][0][i] = B[1][i]
        *(R + 2 * 2 * N5 + 0 * N5 + i) = *(B + 2 * N4 + i); // R[2][0][i] = B[2][i]
        
        *(R + 0 * 2 * N5 + 1 * N5 + i) = *(A + 0 * N2 + i); // R[0][1][i] = A[0][i]
        *(R + 1 * 2 * N5 + 1 * N5 + i) = *(A + 1 * N2 + i); // R[1][1][i] = A[1][i]
        *(R + 2 * 2 * N5 + 1 * N5 + i) = *(A + 2 * N2 + i); // R[2][1][i] = A[2][i]
    }
}

int main() {
    // Example usage
    const int N1 = 3, N2 = 5, N3 = 3, N4 = 5, N5 = 5;
    float A[N1][N2] = {/* initialize with your values */};
    float B[N3][N4] = {/* initialize with your values */};
    float R[3][2][N5] = {{{0}}};

    // Call the function
    LOADF(&A[0][0], &B[0][0], &R[0][0][0], N1, N2, N3, N4, N5);

    // Do something with R
    // ...

    return 0;
}