#include <iostream>
#include <vector>

using namespace std;

void initArray(int n, vector<vector<double>>& x, vector<vector<double>>& a, vector<vector<double>>& b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[j][i] = (double)((i - 1) * (j) + 1.0) / n;
            a[j][i] = (double)((i - 1) * (j + 1) + 2.0) / n;
            b[j][i] = (double)((i - 1) * (j + 2) + 3.0) / n;
        }
    }
}

int main() {
    int n = 10; // adjust the value of n as needed
    vector<vector<double>> x(n, vector<double>(n));
    vector<vector<double>> a(n, vector<double>(n));
    vector<vector<double>> b(n, vector<double>(n));

    initArray(n, x, a, b);

    // print the initialized arrays (optional)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << x[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
