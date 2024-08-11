#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void xpsys(const array<double, 3>& x, array<double, 3>& f) {
    f[0] = 10.0 * (x[1] - x[0]);
    f[1] = 28.0 * x[0] - x[0] * x[2] - x[1];
    f[2] = x[0] * x[1] - (8.0 / 3.0) * x[2];
}

void rk4sys(int n, double& t, array<double, 3>& x, double h, int nstep) {
    array<double, 3> y, f1, f2, f3, f4;

    cout << "C++ Stdout: T,X:" << setprecision(17) << t << " ";
    for (int i = 0; i < n; ++i) {
        cout << setprecision(17) << x[i] << " ";
    }
    cout << endl;

    for (int k = 0; k < nstep; ++k) {
        xpsys(x, f1);
        for (int i = 0; i < n; ++i) {
            y[i] = x[i] + 0.5 * h * f1[i];
        }

        xpsys(y, f2);
        for (int i = 0; i < n; ++i) {
            y[i] = x[i] + 0.5 * h * f2[i];
        }

        xpsys(y, f3);
        for (int i = 0; i < n; ++i) {
            y[i] = x[i] + h * f3[i];
        }

        xpsys(y, f4);
        for (int i = 0; i < n; ++i) {
            x[i] = x[i] + h * (f1[i] + 2.0 * (f2[i] + f3[i]) + f4[i]) / 6.0;
        }
    }

    cout << "T,X:" << setprecision(17) << t << " ";
    for (int i = 0; i < n; ++i) {
        cout << setprecision(17) << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 3;
    double t = 0.0;
    array<double, 3> x = {8.5, 3.1, 1.2};
    double h = 1E-10;
    int nstep = 1; // Adjusted for simple test

    rk4sys(n, t, x, h, nstep);

    return 0;
}