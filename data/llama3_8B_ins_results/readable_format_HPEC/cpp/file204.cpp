#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, vector<double>& p, vector<vector<double>>& a) {
    for (int i = 0; i < n; i++) {
        p[i] = 1.0 / n;
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            a[j][i] = 1.0 / n;
        }
    }
}

int main() {
    int n = 10; // adjust this value as needed
    vector<double> p(n);
    vector<vector<double>> a(n, vector<double>(n));

    init_array(n, p, a);

    // print the initialized arrays
    cout << "p: ";
    for (double val : p) {
        cout << val << " ";
    }
    cout << endl;

    cout << "a: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
