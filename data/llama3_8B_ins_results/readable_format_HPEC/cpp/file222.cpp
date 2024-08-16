#include <cmath>
#include <iostream>

using namespace std;

const double M_PI = 3.14159265358979323846;

template <typename DATA_TYPE>
void init_array(DATA_TYPE a[][2], DATA_TYPE x[], int nx, int ny) {
    for (int i = 0; i < ny; i++) {
        x[i] = (i - 1) * M_PI;
    }
    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < ny; i++) {
            a[j][i] = (double)((i - 1) * (j)) / nx;
        }
    }
}

int main() {
    int nx = 10;
    int ny = 10;
    double a[10][10];
    double x[10];

    init_array(a, x, nx, ny);

    // Print the initialized array
    for (int i = 0; i < ny; i++) {
        for (int j = 0; j < ny; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < ny; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}
