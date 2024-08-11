#include <iostream>
#include <array>

void foo(std::array<std::array<int, 4>, 4>& a, int i) {
    --i; // Adjusting for 0-indexing in C++.

    // Check if any of the first three elements of row 'i' are not zero.
    for (int j = 0; j < 3; ++j) {
        if (a[i][j] != 0) {
            // Only update if 'i + 1' is within bounds.
            if (i + 1 < static_cast<int>(a.size())) {
                for (int k = 1; k < 4; ++k) { // Update elements 2 to 4 in the next row.
                    a[i + 1][k] = 1;
                }
            }
            break; // Match Fortran behavior by exiting after first modification.
        }
    }
}

int main() {
    std::array<std::array<int, 4>, 4> a{{
        {0, 2, 0, 0},
        {0, 0, 0, 0},
        {3, 0, 0, 0},
        {0, 0, 0, 0}
    }};

    foo(a, 3); // Test the function with i = 3

    std::cout << "Modified array:" << std::endl;
    for (const auto& row : a) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}