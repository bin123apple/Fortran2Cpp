#include <iostream>
#include <vector>

using namespace std;

void print_array(int maxgrid, vector<vector<int>>& path) {
    for (int i = 1; i <= maxgrid; i++) {
        for (int j = 1; j <= maxgrid; j++) {
            cout << path[j-1][i-1] << endl;
            if ((i-1)*maxgrid + j-1 % 20 == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;
}

int main() {
    int maxgrid = 20; // assuming maxgrid is 20
    vector<vector<int>> path(maxgrid, vector<int>(maxgrid));
    // initialize path array
    print_array(maxgrid, path);
    return 0;
}
