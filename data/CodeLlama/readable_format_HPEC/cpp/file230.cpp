#include <vector>
#include <iostream>

using namespace std;

void init_array(int n, vector<vector<double>>& y, vector<vector<double>>& sumArray, vector<double>& alpha, vector<double>& beta, vector<double>& r) {
    // Initialize alpha, beta, and r arrays
    for (int i = 0; i < n; ++i) {
        alpha[i] = static_cast<double>(i + 1);
        beta[i] = (static_cast<double>(i + 1) / static_cast<double>(n)) / 2.0;
        r[i] = (static_cast<double>(i + 1) / static_cast<double>(n)) / 4.0;
    }

    // Initialize y and sumArray matrices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            y[j][i] = static_cast<double>((i + 1) * (j + 1)) / static_cast<double>(n);
            sumArray[j][i] = static_cast<double>((i + 1) * (j + 1)) / static_cast<double>(n);
        }
    }
}

int main() {
    int n = 5; // Example size
    vector<vector<double>> y(n, vector<double>(n));
    vector<vector<double>> sumArray(n, vector<double>(n));
    vector<double> alpha(n);
    vector<double> beta(n);
    vector<double> r(n);

    init_array(n, y, sumArray, alpha, beta, r);

    // Print results for verification
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "y[" << i << "][" << j << "] = " << y[i][j] << ", ";
            cout << "sumArray[" << i << "][" << j << "] = " << sumArray[i][j] << endl;
        }
    }

    return 0;
}
