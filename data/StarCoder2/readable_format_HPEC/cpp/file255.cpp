#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a floating-point type like double
// and DATA_PRINTF_MODIFIER is a format specifier for std::cout, e.g., "%.2f"

template<typename T>
void print_array(int ni, int nj, T** a, T** r, T** q) {
    // Setting precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << a[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << r[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << q[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int ni = 4, nj = 4;

    // Dynamically allocate arrays
    double** a = new double*[nj];
    double** r = new double*[nj];
    double** q = new double*[nj];

    for (int i = 0; i < nj; ++i) {
        a[i] = new double[ni];
        r[i] = new double[nj];
        q[i] = new double[ni];
    }

    // Initialize arrays with some values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = i * nj + j;
            r[j][i] = i + j;
            q[j][i] = i - j;
        }
    }

    print_array(ni, nj, a, r, q);

    // Clean up
    for (int i = 0; i < nj; ++i) {
        delete[] a[i];
        delete[] r[i];
        delete[] q[i];
    }
    delete[] a;
    delete[] r;
    delete[] q;

    return 0;
}
