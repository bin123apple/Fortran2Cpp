#include <iostream>
#include <vector>

int main() {
    const int n = 100;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 1)); // Initialize a 2D vector with size nxn, all values set to 1
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += a[i][j];
        }
    }

    // If you need to print or use the sum, you can do it here.
    // For example, to print it:
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}