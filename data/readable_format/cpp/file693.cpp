#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
#include <cmath>
#include <omp.h>

using namespace std;

void initialData(int Nx, int Ny, const vector<double>& x, const vector<double>& y, vector<vector<complex<double>>>& u, vector<vector<complex<double>>>& uold) {
    u.resize(Nx, vector<complex<double>>(Ny));
    uold.resize(Nx, vector<complex<double>>(Ny));

    #pragma omp parallel for collapse(2)
    for (int j = 0; j < Ny; ++j) {
        for (int i = 0; i < Nx; ++i) {
            u[i][j] = 0.5 * exp(-1.0 * (x[i]*x[i] + y[j]*y[j])) * sin(10.0 * x[i] + 12.0 * y[j]);
            uold[i][j] = u[i][j];
        }
    }
}

int main() {
    int Nx = 5, Ny = 4;
    vector<double> x(Nx), y(Ny);
    vector<vector<complex<double>>> u, uold;

    for (int i = 0; i < Nx; ++i) x[i] = static_cast<double>(i + 1);
    for (int j = 0; j < Ny; ++j) y[j] = static_cast<double>(j + 1);

    initialData(Nx, Ny, x, y, u, uold);

    cout << fixed << setprecision(4);
    cout << "Matrix u:" << endl;
    for (int j = 0; j < Ny; ++j) {
        for (int i = 0; i < Nx; ++i) {
            cout << setw(8) << u[i][j].real() << setw(8) << u[i][j].imag() << " ";
        }
        cout << endl;
    }

    cout << "Matrix uold:" << endl;
    for (int j = 0; j < Ny; ++j) {
        for (int i = 0; i < Nx; ++i) {
            cout << setw(8) << uold[i][j].real() << setw(8) << uold[i][j].imag() << " ";
        }
        cout << endl;
    }

    return 0;
}