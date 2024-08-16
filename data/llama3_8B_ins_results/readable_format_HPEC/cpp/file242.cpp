#include <iostream>
#include <vector>

using namespace std;

void init_array(int ni, int nj, int nk, double alpha, double beta, vector<vector<double>>& c, vector<vector<double>>& a, vector<vector<double>>& b) {
    alpha = 32412.0;
    beta = 2123.0;

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            c[j][i] = ((double(i - 1) * double(j - 1))) / double(ni);
        }
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nk; j++) {
            a[j][i] = ((double(i - 1) * double(j - 1))) / double(ni);
        }
    }

    for (int i = 0; i < nk; i++) {
        for (int j = 0; j < nj; j++) {
            b[j][i] = ((double(i - 1) * double(j - 1))) / double(ni);
        }
    }
}

int main() {
    int ni = 10;
    int nj = 10;
    int nk = 10;

    vector<vector<double>> c(nj, vector<double>(ni));
    vector<vector<double>> a(nk, vector<double>(ni));
    vector<vector<double>> b(nj, vector<double>(nk));

    init_array(ni, nj, nk, 0.0, 0.0, c, a, b);

    // Print the arrays
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            cout << c[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nk; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nk; i++) {
        for (int j = 0; j < nj; j++) {
            cout << b[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
