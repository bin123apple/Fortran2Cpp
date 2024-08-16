#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init_array(int ni, int nj, double& alpha, double& beta, vector<vector<double>>& a, vector<vector<double>>& c) {
    // Initialize alpha and beta
    alpha = 32412;
    beta = 2123;

    // Resize the arrays to the correct size
    a.resize(ni, vector<double>(ni));
    c.resize(nj, vector<double>(ni));

    // Fill the arrays
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = (static_cast<double>(i) * static_cast<double>(j)) / static_cast<double>(ni);
        }
    }

    for (int j = 0; j < ni; ++j) {
        for (int i = 0; i < ni; ++i) {
            c[j][i] = (static_cast<double>(i) * static_cast<double>(j)) / static_cast<double>(ni);
        }
    }
}

int main() {
    int ni = 5; // Example size
    int nj = 5; // Example size
    double alpha, beta;
    vector<vector<double>> a, c;

    init_array(ni, nj, alpha, beta, a, c);

    // Optional: Print the arrays to verify the results
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
