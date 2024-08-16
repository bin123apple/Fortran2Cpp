#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> grid = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result;
    int k = 3;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    grid = {5, 9, 3, 4, 1, 6, 7, 8, 2};
    result.clear();
    k = 1;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    grid = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    result.clear();
    k = 4;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

void minPath(vector<int> grid, int k, vector<int> &result) {
    int n = grid.size();
    int x = -1;
    int y = -1;

    // Find the position of 1 in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i * n + j] == 1) {
                x = i;
                y = j;
            }
        }
    }

    int min = n * n;
    if (x > 0 && grid[x * n + y - 1] < min) min = grid[x * n + y - 1];
    if (x < n - 1 && grid[x * n + y + 1] < min) min = grid[x * n + y + 1];
    if (y > 0 && grid[(x - 1) * n + y] < min) min = grid[(x - 1) * n + y];
    if (y < n - 1 && grid[(x + 1) * n + y] < min) min = grid[(x + 1) * n + y];

    result.clear();
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            result.push_back(1);
        } else {
            result.push_back(min);
        }
    }
}

[C++]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> grid = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result;
    int k = 3;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    grid = {5, 9, 3, 4, 1, 6, 7, 8, 2};
    result.clear();
    k = 1;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    grid = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    result.clear();
    k = 4;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

void minPath(vector<int> grid, int k, vector<int> &result) {
    int n = grid.size();
    int x = -1;
    int y = -1;

    // Find the position of 1 in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i * n + j] == 1) {
                x = i;
                y = j;
            }
        }
    }

    int min = n * n;
    if (x > 0 && grid[x * n + y - 1] < min) min = grid[x * n + y - 1];
    if (x < n - 1 && grid[x * n + y + 1] < min) min = grid[x * n + y + 1];
    if (y > 0 && grid[(x - 1) * n + y] < min) min = grid[(x - 1) * n + y];
    if (y < n - 1 && grid[(x + 1) * n + y] < min) min = grid[(x + 1) * n + y];

    result.clear();
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            result.push_back(1);
        } else {
            result.push_back(min);
        }
    }
}

[C++]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> grid = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result;
    int k = 3;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    grid = {5, 9, 3, 4, 1, 6, 7, 8, 2};
    result.clear();
    k = 1;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    grid = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    result.clear();
    k = 4;
    minPath(grid, k, result);
    cout << "result: " << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

void minPath(vector<int> grid, int k, vector<int> &result) {
    int n = grid.size();
    int x = -1;
    int y = -1;

    // Find the position of 1 in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i * n + j] == 1) {
                x = i;
                y = j;
            }
        }
    }

    int min = n * n;
    if (x > 0 && grid[x * n + y - 1] < min) min = grid[x * n + y - 1];
    if (x < n - 1 && grid[x * n + y + 1] < min) min = grid[x * n + y + 1];
    if (y > 0 && grid[(x - 1) * n
