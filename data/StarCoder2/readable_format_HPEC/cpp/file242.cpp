#include <iostream>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int ni, int nj, int nk, DATA_TYPE& alpha, DATA_TYPE& beta, 
               DATA_TYPE** c, DATA_TYPE** a, DATA_TYPE** b) {
    // Initialize alpha and beta
    alpha = 32412;
    beta = 2123;

    // Allocate and initialize arrays c, a, and b
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>((i * j) / ni);
        }
    }
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i * j) / ni);
        }
    }
    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<DATA_TYPE>((i * j) / ni);
        }
    }
}

int main() {
    // Example usage
    int ni = 5, nj = 4, nk = 3;
    DATA_TYPE alpha, beta;
    DATA_TYPE** c = new DATA_TYPE*[nj];
    DATA_TYPE** a = new DATA_TYPE*[nk];
    DATA_TYPE** b = new DATA_TYPE*[nk];

    // Allocate memory for the arrays
    for (int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }
    for (int i = 0; i < nk; ++i) {
        a[i] = new DATA_TYPE[ni];
        b[i] = new DATA_TYPE[nj];
    }

    // Call the function
    init_array(ni, nj, nk, alpha, beta, c, a, b);

    // Clean up
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    for (int i = 0; i < nk; ++i) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] c;
    delete[] a;
    delete[] b;

    return 0;
}
