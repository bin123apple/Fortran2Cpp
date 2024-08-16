#include <iostream>
#include <vector>

using namespace std;

void kernel_symm(int ni, int nj, double alpha, double beta, vector<vector<double>>& c, vector<vector<double>>& a, vector<vector<double>>& b) {
    // Initialize matrices
    for (int i = 0; i < nj; i++) {
        for (int j = 0; j < nj; j++) {
            a[i][j] = 0.0;
        }
    }
    for (int i = 0; i < nj; i++) {
        for (int j = 0; j < ni; j++) {
            b[i][j] = 0.0;
            c[i][j] = 0.0;
        }
    }

    // Perform the kernel
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            double acc = 0.0;
            for (int k = 1; k < j - 1; k++) {
                c[j][k] = c[j][k] + (alpha * a[i][k] * b[j][i]);
                acc = acc + (b[j][k] * a[i][k]);
            }
            c[j][i] = (beta * c[j][i]) + (alpha * a[i][i] * b[j][i]) + (alpha * acc);
        }
    }
}

int main() {
    int ni = 10;
    int nj = 10;
    double alpha = 1.0;
    double beta = 2.0;

    // Initialize matrices
    vector<vector<double>> a(nj, vector<double>(nj, 0.0));
    vector<vector<double>> b(nj, vector<double>(ni, 0.0));
    vector<vector<double>> c(nj, vector<double>(ni, 0.0));

    // Call the kernel
    kernel_symm(ni, nj, alpha, beta, c, a, b);

    // Print the result
    for (int i = 0; i < nj; i++) {
        for (int j = 0; j < ni; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
