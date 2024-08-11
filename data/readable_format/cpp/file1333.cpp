// file: fpsysy.cpp
#include <iostream>
#include <vector>

using namespace std;

void fpsysy(vector<vector<double>>& a, int n, vector<double>& g) {
    double fac;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            g[i] = g[i] / a[i][i];
            continue;
        }

        for (int k = i; k < n; ++k) {
            fac = a[k][i];
            for (int j = 0; j < i; ++j) {
                fac -= a[k][j] * a[j][i];
            }
            a[k][i] = fac / (i < k ? a[i][i] : 1.0);
        }

        fac = g[i];
        for (int j = 0; j < i; ++j) {
            fac -= g[j] * a[i][j];
        }
        g[i] = fac / a[i][i];
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int k = i + 1; k < n; ++k) {
            g[i] -= g[k] * a[k][i];
        }
    }
}

int main() {
    int n = 3;
    vector<vector<double>> a = {
        {1, 2, 3},
        {2, 5, 7},
        {3, 7, 10}
    };
    vector<double> g = {6, 18, 24};

    fpsysy(a, n, g);

    cout << "Results for g:" << endl;
    for (auto& val : g) {
        cout << val << endl;
    }

    return 0;
}