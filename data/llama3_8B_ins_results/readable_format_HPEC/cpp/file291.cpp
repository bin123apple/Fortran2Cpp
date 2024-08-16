#include <iostream>
#include <vector>

using namespace std;

void kernel_seidel(int tsteps, int n, vector<vector<double>>& a) {
    // Note: We assume that the input vector 'a' is a 2D vector of size n x n
    // and that 'tsteps' and 'n' are valid input values.

    for (int t = 1; t <= tsteps; t++) {
        for (int i = 2; i < n - 1; i++) {
            for (int j = 2; j < n - 1; j++) {
                a[j][i] = (a[j - 1][i - 1] + a[j][i - 1] + a[j + 1][i - 1] +
                           a[j - 1][i] + a[j][i] + a[j + 1][i] +
                           a[j - 1][i + 1] + a[j][i + 1] + a[j + 1][i + 1]) / 9.0;
            }
        }
    }
}

int main() {
    int tsteps = 1; // Set the number of tsteps
    int n = 10; // Set the size of the matrix
    vector<vector<double>> a(n, vector<double>(n)); // Initialize the matrix

    // Initialize the matrix values (optional)
    //...

    kernel_seidel(tsteps, n, a);

    // Print the resulting matrix values (optional)
    //...

    return 0;
}
