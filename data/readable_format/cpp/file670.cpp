#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    vector<vector<float>> a(3, vector<float>(3));
    vector<vector<float>> b(2, vector<float>(3));
    vector<vector<float>> c(2, vector<float>(3));

    // Initialize matrix a
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = static_cast<float>(i * 3 + j + 1);
        }
    }

    // Initialize matrices b and c by slicing parts of a
    b[0] = a[1]; // Second row of `a` to first row of `b`
    b[1] = a[0]; // First row of `a` to second row of `b`
    c[0] = a[2]; // Third row of `a` to first row of `c`
    c[1] = a[1]; // Second row of `a` to second row of `c`

    // Perform unit tests
    // Expected values for b
    vector<vector<float>> expected_b = {{4, 5, 6}, {1, 2, 3}};
    // Expected values for c
    vector<vector<float>> expected_c = {{7, 8, 9}, {4, 5, 6}};

    for (size_t i = 0; i < b.size(); ++i) {
        for (size_t j = 0; j < b[i].size(); ++j) {
            assert(b[i][j] == expected_b[i][j]);
            assert(c[i][j] == expected_c[i][j]);
        }
    }

    cout << "All tests passed." << endl;

    return 0;
}