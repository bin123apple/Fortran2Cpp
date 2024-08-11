#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void elmhes(vector<vector<double>>& A, int N) {
    for (int m = 1; m < N - 1; ++m) {
        double x = 0.0;
        int i = m;
        for (int j = m; j < N; ++j) {
            if (fabs(A[j][m - 1]) > fabs(x)) {
                x = A[j][m - 1];
                i = j;
            }
        }
        if (i != m) {
            for (int j = m - 1; j < N; ++j) swap(A[i][j], A[m][j]);
            for (int j = 0; j < N; ++j) swap(A[j][i], A[j][m]);
        }
        if (x != 0.0) {
            for (int j = m + 1; j < N; ++j) {
                double y = A[j][m - 1] / x;
                A[j][m - 1] = y;
                for (int k = m; k < N; ++k) A[j][k] -= y * A[m][k];
                for (int k = 0; k < N; ++k) A[k][m] += y * A[k][j];
            }
        }
    }
}

int main() {
    vector<vector<double>> A = {
        {1.0, 4.0, 7.0},
        {2.0, 5.0, 8.0},
        {3.0, 6.0, 9.0}
    };

    elmhes(A, A.size());

    cout << "Transformed matrix A (C++):" << endl;
    for (const auto& row : A) {
        for (double elem : row) {
            cout << setw(8) << setprecision(2) << fixed << elem << " ";
        }
        cout << endl;
    }

    return 0;
}