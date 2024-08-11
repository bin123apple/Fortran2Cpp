#include <iostream>
#include <cmath>
#include <vector>

// Forward declaration of fft99a to ensure it's known at the point of its usage in main
void fft99a(double* a, double* work, double* trigs, int inc, int jump, int n, int lot);

int main() {
    const int n = 4;
    const int inc = 1;
    const int jump = 1;
    const int lot = 1;
    std::vector<double> a = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::vector<double> work(n*2, 0.0);
    std::vector<double> trigs = {cos(0.0), sin(0.0), cos(M_PI/4.0), sin(M_PI/4.0), cos(M_PI/2.0), sin(M_PI/2.0), cos(3.0*M_PI/4.0), sin(3.0*M_PI/4.0)};

    fft99a(a.data(), work.data(), trigs.data(), inc, jump, n, lot);

    std::cout << "work =" << std::endl;
    for (double w : work) {
        std::cout << w << std::endl;
    }

    return 0;
}

// Implementation of fft99a
void fft99a(double* a, double* work, double* trigs, int inc, int jump, int n, int lot) {
    int nh = n / 2;
    int nx = n + 1;
    int ink = inc + inc;
    int ia = 0; // Adjusted for 0-based indexing
    int ib = n * inc; // Adjusted for 0-based indexing
    int ja = 0; // Adjusted for 0-based indexing
    int jb = 1; // Adjusted for 0-based indexing

    for (int l = 0; l < lot; ++l) { // Adjusted loop for 0-based indexing
        work[ja] = a[ia] + a[ib];
        work[jb] = a[ia] - a[ib];
        ia += jump;
        ib += jump;
        ja += nx;
        jb += nx;
    }

    int iabase = 2 * inc;
    int ibbase = (n - 2) * inc;
    int jabase = 2; // Adjusted for 0-based indexing
    int jbbase = n - 2; // Adjusted for 0-based indexing

    for (int k = 2; k < nh; k += 2) { // Adjusted loop for 0-based indexing
        ia = iabase;
        ib = ibbase;
        ja = jabase;
        jb = jbbase;
        double c = trigs[n + k];
        double s = trigs[n + k + 1];

        for (int l = 0; l < lot; ++l) { // Adjusted loop for 0-based indexing
            work[ja] = (a[ia] + a[ib]) - (s * (a[ia] - a[ib]) + c * (a[ia + inc] + a[ib + inc]));
            work[jb] = (a[ia] + a[ib]) + (s * (a[ia] - a[ib]) + c * (a[ia + inc] + a[ib + inc]));
            work[ja + 1] = (c * (a[ia] - a[ib]) - s * (a[ia + inc] + a[ib + inc])) + (a[ia + inc] - a[ib + inc]);
            work[jb + 1] = (c * (a[ia] - a[ib]) - s * (a[ia + inc] + a[ib + inc])) - (a[ia + inc] - a[ib + inc]);
            ia += jump;
            ib += jump;
            ja += nx;
            jb += nx;
        }

        iabase += ink;
        ibbase -= ink;
        jabase += 2;
        jbbase -= 2;
    }

    if (iabase == ibbase) {
        ia = iabase;
        ja = jabase;

        for (int l = 0; l < lot; ++l) { // Adjusted loop for 0-based indexing
            work[ja] = 2.0 * a[ia];
            work[ja + 1] = -2.0 * a[ia + inc];
            ia += jump;
            ja += nx;
        }
    }
}