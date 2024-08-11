#include <iostream>
#include <iomanip>

// Definition of the dlascl2 function
void dlascl2(int m, int n, double* d, double** x, int ldx) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            x[i][j] = x[i][j] * d[i];
        }
    }
}

int main() {
    const int M = 3; // Number of rows
    const int N = 2; // Number of columns
    double d[M] = {1.0, 2.0, 3.0}; // Scaling factors for each row
    
    // Dynamically allocate 2D array X
    double** x = new double*[M];
    for(int i = 0; i < M; ++i) {
        x[i] = new double[N];
    }

    // Initialize X with some values
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            x[i][j] = (i+1) * (j+1); // Just an example initialization
        }
    }

    // Scale X by D using dlascl2
    dlascl2(M, N, d, x, M);

    // Print scaled X
    std::cout << std::fixed << std::setprecision(1);
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            std::cout << "X(" << i << "," << j << ") = " << x[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Clean up dynamically allocated memory
    for(int i = 0; i < M; ++i) {
        delete[] x[i];
    }
    delete[] x;

    return 0;
}