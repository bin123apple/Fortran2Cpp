#include <iostream>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int ni, int nj, DATA_TYPE& alpha, DATA_TYPE& beta, DATA_TYPE** c, DATA_TYPE** a, DATA_TYPE** b) {
    alpha = 32412.0;
    beta = 2123.0;

    // Dynamic allocation for 2D arrays
    c = new DATA_TYPE*[nj];
    a = new DATA_TYPE*[nj];
    b = new DATA_TYPE*[nj];
    for (int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
        a[i] = new DATA_TYPE[ni];
        b[i] = new DATA_TYPE[ni];
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = ((static_cast<DATA_TYPE>((i) * (j))) / static_cast<DATA_TYPE>(ni));
            b[j][i] = ((static_cast<DATA_TYPE>((i) * (j))) / static_cast<DATA_TYPE>(ni));
        }
    }

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = ((static_cast<DATA_TYPE>((i) * (j))) / static_cast<DATA_TYPE>(ni));
        }
    }
}

int main() {
    int ni = 10; // Example values
    int nj = 10; // Example values
    DATA_TYPE alpha, beta;
    DATA_TYPE** c, **a, **b;

    init_array(ni, nj, alpha, beta, c, a, b);

    // Example of printing the arrays to verify the initialization
    std::cout << "alpha: " << alpha << ", beta: " << beta << std::endl;
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << "c[" << j << "][" << i << "] = " << c[j][i] << ", ";
            std::cout << "b[" << j << "][" << i << "] = " << b[j][i] << std::endl;
        }
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
        delete[] a[i];
        delete[] b[i];
    }
    delete[] c;
    delete[] a;
    delete[] b;

    return 0;
}
