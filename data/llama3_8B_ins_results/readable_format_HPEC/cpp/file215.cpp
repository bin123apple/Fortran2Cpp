#include <iostream>
#include <vector>

using namespace std;

void kernelFloydWarshall(int n, vector<vector<int>>& path) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (path[j][i] >= path[k][i] + path[j][k]) {
                    path[j][i] = path[k][i] + path[j][k];
                }
            }
        }
    }
}

int main() {
    int n = 5; // adjust this value as needed
    vector<vector<int>> path(n, vector<int>(n)); // initialize path matrix

    // initialize path matrix values (not shown in the Fortran code)
    //...

    kernelFloydWarshall(n, path);

    // print the updated path matrix (not shown in the Fortran code)
    //...

    return 0;
}
