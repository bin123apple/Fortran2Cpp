#include <iostream>
#include <complex>

// Function declaration
void CLAPMT(bool forwrd, int m, int n, std::complex<float>* X, int ldx, int* K) {
    if (n <= 1) {
        return;
    }

    // Negating the elements of K
    for (int i = 0; i < n; ++i) {
        K[i] = -K[i];
    }

    if (forwrd) {
        for (int i = 0; i < n; ++i) {
            if (K[i] > 0) continue;

            int j = i;
            K[j] = -K[j];
            int in = K[j] - 1; // Adjusting for 0-based indexing

            while (true) {
                if (K[in] > 0) break;

                for (int ii = 0; ii < m; ++ii) {
                    std::complex<float> temp = X[ii + j * ldx];
                    X[ii + j * ldx] = X[ii + in * ldx];
                    X[ii + in * ldx] = temp;
                }

                K[in] = -K[in];
                j = in;
                in = K[in] - 1; // Adjusting for 0-based indexing
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (K[i] > 0) continue;

            K[i] = -K[i];
            int j = K[i] - 1; // Adjusting for 0-based indexing

            while (true) {
                if (j == i) break;

                for (int ii = 0; ii < m; ++ii) {
                    std::complex<float> temp = X[ii + i * ldx];
                    X[ii + i * ldx] = X[ii + j * ldx];
                    X[ii + j * ldx] = temp;
                }

                K[j] = -K[j];
                j = K[j] - 1; // Adjusting for 0-based indexing
            }
        }
    }
}

// Main function for testing
int main() {
    const int m = 2, n = 3, ldx = 2;
    std::complex<float> X[ldx*n] = { {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0} };
    int K[n] = {3, 1, 2};

    CLAPMT(true, m, n, X, ldx, K);

    std::cout << "Permuted X:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << X[j + i*ldx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}