Below is the translated C++ code based on the provided Fortran code. The C++ code uses standard libraries and follows the structure and logic of the Fortran code.

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

// Function to fill the table
void filltab(int dimx, int dimy, std::vector<std::vector<float>>& ftab) {
    for (int x = 0; x < dimx; ++x) {
        for (int y = 0; y < dimy; ++y) {
            ftab[x][y] = (x + 1) * 100 + (y + 1);
        }
    }
}

// Function to print the table
void printtab(const std::vector<std::vector<float>>& tab, int dimx, int dimy) {
    for (int x = 0; x < dimx; ++x) {
        std::cout << std::setw(3) << x + 1 << "  ";
        for (int y = 0; y < dimy; ++y) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(1) << tab[x][y];
        }
        std::cout << std::endl;
    }
}

int main() {
    // Declarations
    int dimx = 8, dimy = 6;
    std::vector<std::vector<float>> ftab(dimx, std::vector<float>(dimy));

    // Procedure calls
    filltab(dimx, dimy, ftab);
    printtab(ftab, dimx, dimy);

    // No need to deallocate in C++ as vector will automatically manage memory

    return 0;
}
```

### Explanation:
1. **filltab Function**: This function fills a 2D vector with values based on the given dimensions. The logic is directly translated from the Fortran `filltab` subroutine.
2. **printtab Function**: This function prints the 2D vector in a formatted manner, similar to the Fortran `printtab` subroutine. The formatting is done using `iomanip` for setting the width and precision.
3. **main Function**: This function initializes the dimensions, allocates the 2D vector, calls the `filltab` and `printtab` functions, and then exits. Memory management is handled automatically by the `std::vector`.

### Note:
- The Fortran code uses 1-based indexing, while C++ uses 0-based indexing. Adjustments are made accordingly in the C++ code.
- The `assert` statement for unit testing is not included in the provided Fortran code, so it is not translated here. If you have specific unit tests, please provide them, and I can include the corresponding `assert` statements in the C++ code.