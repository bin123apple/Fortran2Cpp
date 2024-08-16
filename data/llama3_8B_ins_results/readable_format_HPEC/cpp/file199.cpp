#include <iostream>
#include <vector>

using namespace std;

void kernel_syrk(int ni, int nj, double alpha, double beta, vector<vector<double>>& c, vector<vector<double>>& a) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            c[j][i] = c[j][i] * beta;
        }
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            for (int k = 0; k < nj; k++) {
                c[j][i] = c[j][i] + (alpha * a[k][i] * a[k][j]);
            }
        }
    }
}

int main() {
    int ni = 10; // Replace with your desired value
    int nj = 10; // Replace with your desired value
    double alpha = 1.0; // Replace with your desired value
    double beta = 1.0; // Replace with your desired value

    vector<vector<double>> a(ni, vector<double>(ni));
    vector<vector<double>> c(nj, vector<double>(ni));

    // Initialize a and c arrays with your desired values

    kernel_syrk(ni, nj, alpha, beta, c, a);

    // Print the result
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            cout << c[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
