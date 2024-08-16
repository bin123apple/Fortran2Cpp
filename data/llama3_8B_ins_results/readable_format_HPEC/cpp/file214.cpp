#include <iostream>
#include <vector>

using namespace std;

void kernel_covariance(int m, int n, double float_n, vector<vector<double>>& dat, vector<vector<double>>& symmat, vector<double>& mean) {
    // Determine mean of column vectors of input data matrix
    for (int j = 0; j < m; j++) {
        mean[j] = 0.0;
        for (int i = 0; i < n; i++) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Center the column vectors.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dat[j][i] -= mean[j];
        }
    }

    // Calculate the m * m covariance matrix.
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = j1; j2 < m; j2++) {
            symmat[j2][j1] = 0.0;
            for (int i = 0; i < n; i++) {
                symmat[j2][j1] += (dat[j1][i] * dat[j2][i]);
            }
            symmat[j1][j2] = symmat[j2][j1];
        }
    }
}

int main() {
    int m = 10; // Replace with your desired value
    int n = 20; // Replace with your desired value
    double float_n = 100.0; // Replace with your desired value

    vector<vector<double>> dat(m, vector<double>(n));
    vector<vector<double>> symmat(m, vector<double>(m));
    vector<double> mean(m);

    // Initialize dat, symmat, and mean with your data

    kernel_covariance(m, n, float_n, dat, symmat, mean);

    // Print the covariance matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << symmat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
