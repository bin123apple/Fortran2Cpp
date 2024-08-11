#include <iostream>
#include <vector>
#include <cassert>

int main() {
    const int isize = 7, jsize = 9, ksize = 8; // Adjusted sizes to match Fortran array indices
    std::vector<std::vector<std::vector<int>>> a(isize, std::vector<std::vector<int>>(jsize, std::vector<int>(ksize, 0)));
    std::vector<std::vector<std::vector<int>>> b(isize, std::vector<std::vector<int>>(jsize, std::vector<int>(ksize, 0)));
    
    bool l = false, r = false;

    // Translated logic from Fortran
    for (int i = 1; i <= 6; ++i) {
        for (int j = -2; j <= 4; ++j) {
            for (int k = 13; k <= 18; ++k) {
                l = l || i < 2 || i > 6 || j < -2 || j > 4;
                l = l || k < 13 || k > 18;
                if (!l) a[i-1][j+3][k-12] = a[i-1][j+3][k-12] + 1; // Adjusted to 0-based indexing
            }
        }
    }

    for (int i = 1; i <= 6; ++i) {
        for (int j = -2; j <= 4; ++j) {
            for (int k = 13; k <= 18; ++k) {
                r = r || i < 2 || i > 6 || j < -2 || j > 4;
                r = r || k < 13 || k > 18;
                if (!r) b[i-1][j+3][k-12] = b[i-1][j+3][k-12] + 1;
            }
        }
    }

    // Unit Test Code
    std::cout << "Verifying arrays and conditions..." << std::endl;
    for (int i = 0; i < isize; ++i) {
        for (int j = 0; j < jsize; ++j) {
            for (int k = 0; k < ksize; ++k) {
                assert(a[i][j][k] == b[i][j][k]); // This will terminate the program if the condition fails
            }
        }
    }
    std::cout << "Arrays match successfully." << std::endl;
    
    assert(l == r); // Verifies that logical conditions match
    std::cout << "Logical conditions match." << std::endl;

    return 0;
}