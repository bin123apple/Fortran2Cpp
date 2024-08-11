#include <iostream>
#include <cassert>
#include <cstdlib>

int main() {
    // Variable declarations
    const int v1 = 3 - 1; // Adjust for 0-based indexing
    const int v2 = 6 - 1;
    const int v3 = (-2) + 3; // Adjust for mapping to 0-based indexing
    const int v4 = 4 + 3;
    const int v5 = 13 - 12; // Adjust for mapping to 0-based indexing
    const int v6 = 18 - 12;
    bool l = false, r = false;

    // Array declarations
    int a[7][9][8] = {}; // Adjusted sizes for 0-based indexing
    int b[7][9][8] = {};

    // Fill arrays with zeros (already done by {} initialization)

    // Parallel region simulation (use OpenMP for actual parallelism)
    for(int i = v1; i <= v2; ++i) {
        for(int j = v3; j <= v4; ++j) {
            for(int k = v5; k <= v6; ++k) {
                l = l || i < 2 || i > 6 || j < 1 || j > 7 || k < 1 || k > 6;
                if (!l) a[i][j][k] = a[i][j][k] + 1;
            }
        }
    }

    // Sequential region
    for(int i = v1; i <= v2; ++i) {
        for(int j = v3; j <= v4; ++j) {
            for(int k = v5; k <= v6; ++k) {
                r = r || i < 2 || i > 6 || j < 1 || j > 7 || k < 1 || k > 6;
                if (!r) b[i][j][k] = b[i][j][k] + 1;
            }
        }
    }

    // Unit test verification
    std::cout << "Checking correctness..." << std::endl;
    for(int i = v1; i <= v2; ++i) {
        for(int j = v3; j <= v4; ++j) {
            for(int k = v5; k <= v6; ++k) {
                assert(a[i][j][k] == b[i][j][k]);
            }
        }
    }

    std::cout << "All tests passed." << std::endl;

    // Check logical variables match (additional check)
    assert(l == r);
    if (l != r) {
        std::cout << "Logical variables do not match." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}