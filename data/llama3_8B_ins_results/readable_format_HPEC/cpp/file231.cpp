#include <cmath>
#include <iostream>

using namespace std;

const double M_PI = 3.14159265358979323846;

template <typename DATA_TYPE>
void init_array(int nx, int ny, DATA_TYPE a[][ny], DATA_TYPE r[], DATA_TYPE p[]) {
    for (int i = 0; i < ny; i++) {
        p[i] = (i - 1) * M_PI;
    }

    for (int i = 0; i < nx; i++) {
        r[i] = (i - 1) * M_PI;
        for (int j = 0; j < ny; j++) {
            a[j][i] = (i - 1) * (j - 1) / static_cast<double>(nx);
        }
    }
}

int main() {
    int nx = 10;
    int ny = 10;
    double a[ny][nx];
    double r[nx];
    double p[ny];

    init_array(nx, ny, a, r, p);

    // Print the initialized arrays
    for (int i = 0; i < ny; i++) {
        cout << "p[" << i << "] = " << p[i] << endl;
    }
    for (int i = 0; i < nx; i++) {
        cout << "r[" << i << "] = " << r[i] << endl;
        for (int j = 0; j < ny; j++) {
            cout << "a[" << j << "][" << i << "] = " << a[j][i] << endl;
        }
    }

    return 0;
}
