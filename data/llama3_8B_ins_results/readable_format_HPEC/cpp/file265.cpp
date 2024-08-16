#include <iostream>
#include <vector>

using namespace std;

void kernel_jacobi_2d_imper(int tsteps, int n, vector<vector<double>>& a, vector<vector<double>>& b) {
    // Initialize b array
    for (int i = 2; i < n - 1; i++) {
        for (int j = 2; j < n - 1; j++) {
            b[j][i] = 0.2 * (a[j][i] + a[j - 1][i] + a[j + 1][i] + a[j][i + 1] + a[j][i - 1]);
        }
    }

    // Update a array
    for (int i = 2; i < n - 1; i++) {
        for (int j = 2; j < n - 1; j++) {
            a[j][i] = b[j][i];
        }
    }
}

int main() {
    int tsteps = 1; // Replace with your desired value
    int n = 10; // Replace with your desired value
    vector<vector<double>> a(n, vector<double>(n));
    vector<vector<double>> b(n, vector<double>(n));

    // Initialize a array (not shown in the Fortran code)

    kernel_jacobi_2d_imper(tsteps, n, a, b);

    // Print the updated a array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
