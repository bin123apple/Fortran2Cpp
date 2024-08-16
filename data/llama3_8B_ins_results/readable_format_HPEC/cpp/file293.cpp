#include <iostream>
#include <vector>

using namespace std;

void init_array(int tmax, int nx, int ny, vector<double>& fict, vector<vector<double>>& ex, vector<vector<double>>& ey, vector<vector<double>>& hz) {
    fict.resize(tmax);
    ex.resize(ny, nx);
    ey.resize(ny, nx);
    hz.resize(ny, nx);

    for (int i = 0; i < tmax; i++) {
        fict[i] = (double)(i - 1);
    }

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            ex[j][i] = (double)((i - 1) * (j)) / (double)nx;
            ey[j][i] = (double)((i - 1) * (j + 1)) / (double)ny;
            hz[j][i] = (double)((i - 1) * (j + 2)) / (double)nx;
        }
    }
}

int main() {
    int tmax = 10; // adjust this value as needed
    int nx = 10; // adjust this value as needed
    int ny = 10; // adjust this value as needed

    vector<double> fict(tmax);
    vector<vector<double>> ex(ny, vector<double>(nx));
    vector<vector<double>> ey(ny, vector<double>(nx));
    vector<vector<double>> hz(ny, vector<double>(nx));

    init_array(tmax, nx, ny, fict, ex, ey, hz);

    // print the initialized arrays for verification
    for (int i = 0; i < tmax; i++) {
        cout << "fict[" << i << "] = " << fict[i] << endl;
    }

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            cout << "ex[" << j << "][" << i << "] = " << ex[j][i] << endl;
            cout << "ey[" << j << "][" << i << "] = " << ey[j][i] << endl;
            cout << "hz[" << j << "][" << i << "] = " << hz[j][i] << endl;
        }
    }

    return 0;
}
