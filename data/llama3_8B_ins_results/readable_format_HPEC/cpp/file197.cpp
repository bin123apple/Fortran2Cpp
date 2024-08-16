#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, double alpha, double beta, vector<vector<double>>& a, vector<vector<double>>& b, vector<double>& x) {
    alpha = 43532.0;
    beta = 12313.0;

    for (int i = 0; i < n; i++) {
        x[i] = (i - 1) / static_cast<double>(n);
        for (int j = 0; j < n; j++) {
            a[j][i] = ((i - 1) * (j - 1)) / static_cast<double>(n);
            b[j][i] = ((i - 1) * (j - 1)) / static_cast<double>(n);
        }
    }
}

int main() {
    int n = 10; // adjust the value of n as needed
    double alpha, beta;
    vector<vector<double>> a(n, vector<double>(n));
    vector<vector<double>> b(n, vector<double>(n));
    vector<double> x(n);

    init_array(n, alpha, beta, a, b, x);

    // print the initialized arrays
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
