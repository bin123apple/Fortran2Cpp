#include <iostream>
#include <numeric> // For std::accumulate
#include <vector>

int main() {
    const int size = 100;
    std::vector<std::vector<int>> a(size, std::vector<int>(size));
    std::vector<std::vector<int>> b(size, std::vector<int>(size));
    int d = 0;

    // Populating arrays and performing calculations as in the Fortran code
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = 1;
            b[i][j] = 2;
            a[i][j] = a[i][j] + b[i][j];
        }
    }

    // Calculating the sum of all elements in a
    for (int i = 0; i < size; ++i) {
        d += std::accumulate(a[i].begin(), a[i].end(), 0);
    }

    std::cout << d << std::endl;

    return 0;
}