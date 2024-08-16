#include <iostream>
#include <vector>

using namespace std;

void kernel_atax(int nx, int ny, vector<vector<double>>& a, vector<double>& x, vector<double>& y, vector<double>& tmp) {
    // Initialize y and tmp arrays
    for (int i = 0; i < ny; i++) {
        y[i] = 0.0;
    }
    for (int i = 0; i < nx; i++) {
        tmp[i] = 0.0;
    }

    // Compute tmp array
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            tmp[i] += a[j][i] * x[j];
        }
    }

    // Compute y array
    for (int j = 0; j < ny; j++) {
        y[j] += a[j][i] * tmp[i];
    }
}

int main() {
    int nx = 10; // replace with your desired value
    int ny = 10; // replace with your desired value
    vector<vector<double>> a(ny, vector<double>(nx)); // initialize a matrix
    vector<double> x(ny); // initialize x vector
    vector<double> y(ny); // initialize y vector
    vector<double> tmp(nx); // initialize tmp vector

    // Fill in your data here
    //...

    kernel_atax(nx, ny, a, x, y, tmp);

    // Print the results
    for (int j = 0; j < ny; j++) {
        cout << "y[" << j << "] = " << y[j] << endl;
    }

    return 0;
}
