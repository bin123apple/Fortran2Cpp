#include <iostream>
#include <vector>

using namespace std;

void kernel_lu(int n, vector<vector<double>>& a) {
    for (int k = 0; k < n; k++) {
        for (int j = k + 1; j < n; j++) {
            a[j][k] = a[j][k] / a[k][k];
        }
        for (int i = k + 1; i < n; i++) {
            for (int j = k + 1; j < n; j++) {
                a[j][i] = a[j][i] - (a[k][i] * a[j][k]);
            }
        }
    }
}

int main() {
    int n = 4; // adjust this value as needed
    vector<vector<double>> a(n, vector<double>(n)); // initialize a matrix

    // initialize a matrix (optional)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i * n + j; // example initialization
        }
    }

    kernel_lu(n, a);

    // print the modified matrix (optional)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
