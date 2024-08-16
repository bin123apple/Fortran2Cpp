#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, vector<vector<double>>& path) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            path[j][i] = (double(i * j)) / n;
        }
    }
}

int main() {
    int n = 10; // change this to your desired value
    vector<vector<double>> path(n, vector<double>(n));

    init_array(n, path);

    // print the array for verification
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << path[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
