#include <iostream>
#include <vector>

using namespace std;

void initArray(int maxgrid, vector<vector<double>>& sumTang, vector<vector<double>>& mean, vector<vector<double>>& path) {
    for (int i = 0; i < maxgrid; i++) {
        for (int j = 0; j < maxgrid; j++) {
            sumTang[j][i] = i * j;
            mean[j][i] = (i - j) / (double)maxgrid;
            path[j][i] = ((i - 1) * (j - 2)) / (double)maxgrid;
        }
    }
}

int main() {
    int maxgrid = 10; // adjust this value as needed
    vector<vector<double>> sumTang(maxgrid, vector<double>(maxgrid));
    vector<vector<double>> mean(maxgrid, vector<double>(maxgrid));
    vector<vector<double>> path(maxgrid, vector<double>(maxgrid));

    initArray(maxgrid, sumTang, mean, path);

    // print the arrays for verification
    for (int i = 0; i < maxgrid; i++) {
        for (int j = 0; j < maxgrid; j++) {
            cout << sumTang[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < maxgrid; i++) {
        for (int j = 0; j < maxgrid; j++) {
            cout << mean[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < maxgrid; i++) {
        for (int j = 0; j < maxgrid; j++) {
            cout << path[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
