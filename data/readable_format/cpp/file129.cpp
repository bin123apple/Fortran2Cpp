#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    std::array<int, 5> b = {0, 0, 0, 0, 0};

    // Implementing the where and elsewhere logic
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != 1) {
            b[i] = 2;
        }
    }

    // Expected result for comparison
    std::array<int, 5> expected = {0, 2, 2, 2, 2};

    // Check if the operation has been performed correctly
    if (!std::equal(b.begin(), b.end(), expected.begin())) {
        std::cerr << "An error occurred." << std::endl;
        return 1; // Use return 1 to indicate error, similar to STOP 1 in Fortran
    }

    return 0; // Successful execution
}