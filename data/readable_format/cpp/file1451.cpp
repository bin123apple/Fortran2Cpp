#include <iostream>
#include <vector>

int main() {
    // Define and initialize the arrays
    std::vector<std::vector<double>> a(10, std::vector<double>(10, 1.0)); // Initialize a 10x10 array with 1.0
    std::vector<double> b = { 4, 5, 6, 4, 5, 2, 7, 4, 9, 1 }; // Initialize b
    std::vector<std::vector<double>> c(a.size() + 1, std::vector<double>(a[0].size() + 1, 0.0)); // Initialize c with 0.0

    // Copy elements from 'a' to 'c'
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            c[i][j] = a[i][j];
        }
    }

    // Copy elements from 'b' to the last row and last column of 'c'
    for (size_t i = 0; i < b.size(); ++i) {
        c[a.size()][i] = b[i]; // Last row
        c[i][a[0].size()] = b[i]; // Last column
    }

    // Output the size of 'a' (rows, since the question only prints rows)
    std::cout << a.size() << std::endl;

    // Output the elements of 'a'
    for (const auto& row : a) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}