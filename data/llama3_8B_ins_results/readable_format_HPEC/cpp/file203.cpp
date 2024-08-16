#include <iostream>
#include <vector>

using namespace std;

void initArray(int n, vector<vector<double>>& a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[j][i] = ((double(i - 1) * (double(j + 1))) + 2.0) / n;
        }
    }
}

int main() {
    int n = 10; // adjust the value of n as needed
    vector<vector<double>> a(n, vector<double>(n));

    initArray(n, a);

    // print the initialized array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
