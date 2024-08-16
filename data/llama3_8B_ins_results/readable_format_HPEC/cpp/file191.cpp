#include <iostream>
#include <vector>

using namespace std;

void init_array(int ni, int nj, vector<double>& a, vector<vector<double>>& r, vector<vector<double>>& q) {
    for (int j = 0; j < nj; j++) {
        for (int i = 0; i < ni; i++) {
            a[j][i] = (double(i - 1) * double(j - 1)) / ni;
            q[j][i] = (double(i - 1) * double(j)) / nj;
        }
    }

    for (int j = 0; j < nj; j++) {
        for (int i = 0; i < ni; i++) {
            r[j][i] = (double(i - 1) * double(j + 1)) / nj;
        }
    }
}

int main() {
    int ni = 10;
    int nj = 10;
    vector<vector<double>> a(nj, vector<double>(ni));
    vector<vector<double>> r(nj, vector<double>(ni));
    vector<vector<double>> q(nj, vector<double>(ni));

    init_array(ni, nj, a, r, q);

    // Print the arrays for verification
    for (int j = 0; j < nj; j++) {
        for (int i = 0; i < ni; i++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int j = 0; j < nj; j++) {
        for (int i = 0; i < ni; i++) {
            cout << q[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int j = 0; j < nj; j++) {
        for (int i = 0; i < ni; i++) {
            cout << r[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
