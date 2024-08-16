Below is the translated Fortran code to C++. Note that OpenMP directives and array indexing differences between Fortran and C++ require some adjustments. Additionally, C++ uses zero-based indexing, unlike Fortran's one-based indexing.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 180;
    std::vector<int> indexSet = {
        521, 523, 525, 527, 529, 531, 547, 549, 551, 553, 555, 557, 573, 575, 577, 579, 581, 583, 599,
        601, 603, 605, 607, 609, 625, 627, 629, 631, 633, 635, 651, 653, 655, 657, 659, 661, 859, 861, 863, 865, 867,
        869, 885, 887, 889, 891, 893, 895, 911, 913, 915, 917, 919, 921, 937, 939, 941, 943, 945, 947, 963, 965, 967,
        969, 971, 973, 989, 991, 993, 995, 997, 999, 1197, 1199, 1201, 1203, 1205, 1207, 1223, 1225, 1227, 1229, 1231,
        1233, 1249, 1251, 1253, 1255, 1257, 1259, 1275, 1277, 1279, 1281, 1283, 1285, 1301, 1303, 1305, 1307, 1309,
        1311, 1327, 1329, 1331, 1333, 1335, 1337, 1535, 1537, 1539, 1541, 1543, 1545, 1561, 1563, 1565, 1567, 1569,
        1571, 1587, 1589, 1591, 1593, 1595, 1597, 1613, 1615, 1617, 1619, 1621, 1623, 1639, 1641, 1643, 1645, 1647,
        1649, 1665, 1667, 1669, 1671, 1673, 1675, 1873, 1875, 1877, 1879, 1881, 1883, 1899, 1901, 1903, 1905, 1907,
        1909, 1925, 1927, 1929, 1931, 1933, 1935, 1951, 1953, 1955, 1957, 1959, 1961, 1977, 1979, 1981, 1983, 1985,
        1987, 2003, 2005, 2007, 2009, 2011, 2013
    };

    std::vector<double> base(2025, 0.0); // Initialize with 0.0

    // OpenMP parallel loop
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        int idx1 = indexSet[i] - 1; // Adjust for zero-based indexing
        int idx2 = indexSet[i] + 11 - 1; // Adjust for zero-based indexing
        base[idx1] += 1.0;
        base[idx2] += 3.0;
    }

    // Check and print results
    for (int i = 0; i < 2025; ++i) {
        if (base[i] == 4.0) {
            std::cout << "i= " << i + 1 << " base = " << base[i] << std::endl; // Adjust for one-based indexing
        }
    }

    return 0;
}
```

This C++ code mirrors the functionality of the original Fortran code. Note the following adjustments:

1. **Array Indexing**: Adjusted to zero-based indexing as C++ uses.
2. **OpenMP Directives**: Used `#pragma omp parallel for` to parallelize the loop, similar to the Fortran version.
3. **Printing**: Adjusted the loop to print one-based indices to match the original Fortran code's output.
4. **Initialization**: Initialized `base` vector with zeros to match the Fortran code's initialization.

Make sure to compile this C++ code with OpenMP support enabled. For example, using `g++`:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the outputs of both implementations.

### Fortran Unit Test Code

Save the following Fortran code in a file named `test_drb052.f90`:

```fortran
program test_drb052
    use omp_lib
    implicit none

    integer, dimension(:), allocatable :: indexSet
    integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:), pointer :: xa1, xa2
    real(dp), dimension(:), allocatable, target :: base
    integer :: N = 180
    integer :: i, idx1, idx2
    logical :: test_passed

    allocate (xa1(2025))
    allocate (xa2(2025))
    allocate (base(2025))
    allocate (indexSet(180))
    xa1 => base(1:2025)
    xa2 => base(1:2025)

    indexSet = (/ 521, 523, 525, 527, 529, 531, 547, 549, &
                551, 553, 555, 557, 573, 575, 577, 579, 581, 583, 599, &
                601, 603, 605, 607, 609, 625, 627, 629, 631, 633, 635, &
                651, 653, 655, 657, 659, 661, 859, 861, 863, 8
