#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main() {
    const int N = 120;
    vector<vector<complex<double>>> a(N, vector<complex<double>>(N)),
                                    b(N, vector<complex<double>>(N)),
                                    c(N, vector<complex<double>>(N));

    // Initialize matrices
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            a[i][j] = complex<double>(i + 1, j + 1); // Use 1-based indexing for comparison with Fortran
            b[i][j] = complex<double>(4.0, 4.0);
            c[i][j] = complex<double>(1.0, 1.0);
        }
    }

    // Simulate conditional execution based on "process rank"
    int me = 3; // Assuming the "rank" is 3 for this sequential example
    if (me == 3) {
        for (int j = 40; j < 80; ++j) {
            for (int i = 40; i < 80; ++i) {
                b[i][j] = a[i][j] * 2.0;
            }
        }
        for (int j = 40; j < 80; ++j) {
            for (int i = 0; i < N; ++i) {
                c[i][j] = b[i][j];
            }
        }
    }

    // Check results
    int errors = 0;
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            complex<double> expected;
            if (j >= 40 && j < 80) {
                expected = (i >= 40 && i < 80) ? a[i][j] * 2.0 : complex<double>(4.0, 4.0);
            } else {
                expected = complex<double>(1.0, 1.0);
            }
            if (c[i][j] != expected) {
                // Corrected line continuation
                cout << "Mismatch at [" << i << "][" << j << "]: got (" 
                     << c[i][j].real() << "," << c[i][j].imag() << ") expected (" 
                     << expected.real() << "," << expected.imag() << ")";
                errors++;
            }
        }
    }

    if (errors == 0) {
        cout << "All tests passed." << endl;
    } else {
        cout << "There were " << errors << " errors." << endl;
    }

    return 0;
}