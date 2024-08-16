#include <iostream>
#include <vector>

using namespace std;

void kernel_fdtd_2d(int tmax, int nx, int ny, vector<double>& fict, vector<vector<double>>& ex, vector<vector<double>>& ey, vector<vector<double>>& hz) {
    for (int t = 1; t <= tmax; t++) {
        for (int j = 1; j <= ny; j++) {
            ey[j][1] = fict[t];
        }
        for (int i = 2; i <= nx; i++) {
            for (int j = 1; j <= ny; j++) {
                ey[j][i] = ey[j][i] - (0.5 * (hz[j][i] - hz[j][i-1]));
            }
        }
        for (int i = 1; i <= nx; i++) {
            for (int j = 2; j <= ny; j++) {
                ex[j][i] = ex[j][i] - (0.5 * (hz[j][i] - hz[j-1][i]));
            }
        }
        for (int i = 1; i <= nx-1; i++) {
            for (int j = 1; j <= ny-1; j++) {
                hz[j][i] = hz[j][i] - (0.7 * (ex[j+1][i] - ex[j][i] + ey[j][i+1] - ey[j][i]));
            }
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

    // initialize fict, ex, ey, and hz arrays as needed

    kernel_fdtd_2d(tmax, nx, ny, fict, ex, ey, hz);

    // print or use the updated arrays as needed

    return 0;
}
