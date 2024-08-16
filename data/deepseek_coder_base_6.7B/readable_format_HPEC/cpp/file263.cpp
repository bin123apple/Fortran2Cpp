Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>
#include <iostream>

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

void init_array(int ni, int nj, int nk, int nl, int nm, 
                std::vector<std::vector<DATA_TYPE>>& a, 
                std::vector<std::vector<DATA_TYPE>>& b, 
                std::vector<std::vector<DATA_TYPE>>& c, 
                std::vector<std::vector<DATA_TYPE>>& d) {
    // Resize the matrices to the correct dimensions
    a.resize(nk, std::vector<DATA_TYPE>(ni));
    b.resize(nj, std::vector<DATA_TYPE>(nk));
    c.resize(nm, std::vector<DATA_TYPE>(nj));
    d.resize(nl, std::vector<DATA_TYPE>(nm));

    // Populate matrix a
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(ni);
        }
    }

    // Populate matrix b
    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(nj);
        }
    }

    // Populate matrix c
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nm; ++j) {
            c[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 2) / static_cast<DATA_TYPE>(nl);
        }
    }

    // Populate matrix d
    for (int i = 0; i < nm; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) / static_cast<DATA_TYPE>(nk);
        }
    }
}

int main() {
    int ni = 5, nj = 4, nk = 3, nl = 2, nm = 3;
    std::vector<std::vector<DATA_TYPE>> a, b, c, d;

    init_array(ni, nj, nk, nl, nm, a, b, c, d);

    // Optional: Print the matrices to verify the results
    for (const auto& row : a) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    for (const auto& row : b) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    for (const auto& row : c) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    for (const auto& row : d) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Data Types and Dimensions**: The Fortran code uses `DATA_TYPE` as a placeholder for the data type. In C++, we use `double` as the default choice for `DATA_TYPE`.
2. **Matrices Initialization**: The matrices `a`, `b`, `c`, and `d` are dynamically sized using `std::vector`.
3. **Populating Matrices**: The nested loops in Fortran are translated to nested loops in C++. The calculations are directly translated from Fortran to C++ with type casting where necessary.
4. **Main Function**: The `main` function demonstrates how to call `init_array` and print the matrices to verify the results.

This C++ code should provide the same functionality as the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

Create a Fortran program that calls the `init_array` subroutine and checks the results:

```fortran
program test_init_array
    implicit none
    integer, parameter :: ni = 5, nj = 4, nk = 3, nl = 2, nm = 3
    real, dimension(nk, ni) :: a
    real, dimension(nj, nk) :: b
    real, dimension(nm, nj) :: c
    real, dimension(nl, nm) :: d
    integer :: i, j

    call init_array(ni, nj, nk, nl, nm, a, b, c, d)

    ! Print matrices to verify the results
    print *, 'Matrix a:'
    do i = 1, nk
        print *, (a(i, j), j = 1, ni)
    end do

    print *, 'Matrix b:'
    do i = 1, nj
        print *, (b(i, j), j = 1, nk)
    end do

    print *, 'Matrix c:'
    do i = 1, nm
        print *, (c(i, j), j = 1, nj)
    end do

    print *, 'Matrix d:'
    do i = 1, nl
        print *, (d(i, j), j = 1, nm)
    end do
end program test_init_array
```

### C++ Unit Test

Create a C++ program that calls the `init_array` function and checks the results:

```cpp
#include <vector>
#include <iostream>
#include <cmath> // For fabs

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

void init_array(int ni, int nj, int nk, int nl, int nm, 
                std::vector<std::vector<DATA_TYPE>>& a, 
                std::vector<std::vector<DATA_TYPE>>& b, 
                std::vector<std::vector<DATA_TYPE>>& c, 
                std::vector<std::vector<DATA_TYPE>>& d) {
    // Resize the matrices to the correct dimensions
    a.resize(nk, std::vector<DATA_TYPE>(ni));
    b.resize(nj, std::vector<DATA_TYPE>(nk));
    c.resize(nm, std::vector<DATA_TYPE>(nj));
    d.resize(nl, std::vector<DATA_TYPE>(nm));

    // Populate matrix a
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(ni);
        }
    }

    // Populate matrix b
    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(nj);
        }
    }

    // Populate matrix c
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nm; ++j) {
            c[j][i] = static_cast<DATA_TYPE>
