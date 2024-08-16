Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int n = 180;
    const int size = 2025;
    std::vector<double> base(size);
    std::vector<int> indexSet = {
        521, 533, 525, 527, 529, 531, 547, 549,
        551, 553, 555, 557, 573, 575, 577, 579, 581, 583, 599,
        601, 603, 605, 607, 609, 625, 627, 629, 631, 633, 635,
        651, 653, 655, 657, 659, 661, 859, 861, 863, 865, 867,
        869, 885, 887, 889, 891, 893, 895, 911, 913, 915, 917,
        919, 921, 937, 939, 941, 943, 945, 947, 963, 965, 967,
        969, 971, 973, 989, 991, 993, 995, 997, 999, 1197, 1199,
        1201, 1203, 1205, 1207, 1223, 1225, 1227, 1229, 1231,
        1233, 1249, 1251, 1253, 1255, 1257, 1259, 1275, 1277,
        1279, 1281, 1283, 1285, 1301, 1303, 1305, 1307, 1309,
        1311, 1327, 1329, 1331, 1333, 1335, 1337, 1535, 1537,
        1539, 1541, 1543, 1545, 1561, 1563, 1565, 1567, 1569,
        1571, 1587, 1589, 1591, 1593, 1595, 1597, 1613, 1615,
        1617, 1619, 1621, 1623, 1639, 1641, 1643, 1645, 1647,
        1649, 1665, 1667, 1669, 1671, 1673, 1675, 1873, 1875,
        1877, 1879, 1881, 1883, 1899, 1901, 1903, 1905, 1907,
        1909, 1925, 1927, 1929, 1931, 1933, 1935, 1951, 1953,
        1955, 1957, 1959, 1961, 1977, 1979, 1981, 1983, 1985,
        1987, 2003, 2005, 2007, 2009, 2011, 2013
    };

    // Initialize base array
    for (int i = 0; i < size; ++i) {
        base[i] = 0.5 * (i + 1);
    }

    // Parallel loop
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        int idx1 = indexSet[i] - 1; // Adjust for 0-based indexing
        int idx2 = indexSet[i] + 11; // Adjust for 0-based indexing
        base[idx1] += 1.0;
        base[idx2] += 3.0;
    }

    // Print results
    std::cout << "xa1(999) = " << base[998] << " xa2(1285) = " << base[1284] << std::endl;

    return 0;
}
```

### Explanation:
1. **Include Libraries**:
   - `#include <iostream>` for input/output operations.
   - `#include <vector>` for dynamic array support.
   - `#include <omp.h>` for OpenMP support.

2. **Constants and Variables**:
   - `const int n = 180;` defines the number of iterations.
   - `const int size = 2025;` defines the size of the `base` array.
   - `std::vector<double> base(size);` creates a dynamic array of doubles.
   - `std::vector<int> indexSet` initializes the indices for accessing the `base` array.

3. **Initialization**:
   - A loop initializes the `base` array with values `0.5 * (i + 1)`.

4. **Parallel Loop**:
   - The parallel loop uses OpenMP to parallelize the loop.
   - The loop iterates over `n` elements, and for each element, it calculates the indices `idx1` and `idx2`.
   - It then updates the elements at `idx1` and `idx2` in the `base` array.

5. **Printing Results**:
   - The final step prints the values of `base[998]` and `base[1284]` to match the Fortran output.

### Notes:
- The Fortran code uses 1-based indexing, while C++ uses 0-based indexing. Therefore, when translating, adjustments are made accordingly.
- The `#pragma omp parallel for` directive is used to parallelize the loop, which is equivalent to the `!$omp parallel do` in Fortran.
- The `print*` statement in Fortran is replaced with `std::cout` in C++ for output.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of both implementations.

### Fortran Unit Test

To compile and run the Fortran code, you can use a Fortran compiler like `gfortran`. Here is an example command to compile and run the Fortran code:

```sh
gfortran -fopenmp -o DRB008_indirectaccess4_orig_yes DRB008_indirectaccess4_orig_yes.f90
./DRB008_indirectaccess4_orig_yes
```

### C++ Unit Test

To compile and run the C++ code, you can use a C++ compiler like `g++`. Here is an example command to compile and run the C++ code:

```sh
g++ -fopenmp -o DRB008_indirectaccess4_orig_yes DRB008_indirectaccess4_orig_yes.cpp
./DRB008_indirectaccess4_orig_yes
```
