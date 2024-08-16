#include <iostream>
#include <vector>

using namespace std;

void kernel_mvt(int n, vector<double> x1, vector<double> x2, vector<double> y1, vector<double> y2, vector<vector<double>>& a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x1[i] += a[j][i] * y1[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x2[i] += a[i][j] * y2[j];
        }
    }
}

int main() {
    int n = 10; // replace with your desired value
    vector<double> x1(n);
    vector<double> x2(n);
    vector<double> y1(n);
    vector<double> y2(n);
    vector<vector<double>> a(n, vector<double>(n)); // 2D vector to store matrix a

    // initialize a, x1, x2, y1, y2 as needed

    kernel_mvt(n, x1, x2, y1, y2, a);

    // print or use the updated values of x1, x2

    return 0;
}
