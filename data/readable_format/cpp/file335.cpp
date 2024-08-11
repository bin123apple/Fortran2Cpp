#include <iostream>
using namespace std;

void matrixTranspose(double** A, double** AT, int NR, int NC, int NTR, int NTC) {
    for (int i = 0; i < NTR; ++i) {
        for (int j = 0; j < NTC; ++j) {
            AT[j][i] = A[i][j];
        }
    }
}

int main() {
    // Example usage
    int NR = 3; // Number of rows in A
    int NC = 2; // Number of columns in A (and rows in AT)
    int NTR = 3; // Number of rows to actually transpose
    int NTC = 2; // Number of columns to actually transpose (and columns in AT)

    // Allocate memory for A and AT (using dynamic arrays for demonstration)
    double** A = new double*[NR];
    for(int i = 0; i < NR; ++i)
        A[i] = new double[NC];

    double** AT = new double*[NC];
    for(int i = 0; i < NC; ++i)
        AT[i] = new double[NR];

    // Example initialization for A
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    A[2][0] = 5; A[2][1] = 6;

    // Call the transpose function
    matrixTranspose(A, AT, NR, NC, NTR, NTC);

    // Output the transposed matrix
    for (int i = 0; i < NC; ++i) {
        for (int j = 0; j < NR; ++j) {
            cout << AT[i][j] << " ";
        }
        cout << endl;
    }

    // Cleanup
    for(int i = 0; i < NR; ++i)
        delete[] A[i];
    delete[] A;

    for(int i = 0; i < NC; ++i)
        delete[] AT[i];
    delete[] AT;

    return 0;
}