Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>
#include <iostream>

// Assuming DATA_TYPE is a floating-point type, e.g., float or double
using DATA_TYPE = double;

void init_array(int ni, int nj, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& r, std::vector<std::vector<DATA_TYPE>>& q) {
    // Resize the matrices to the correct dimensions
    a.resize(nj, std::vector<DATA_TYPE>(ni));
    r.resize(nj, std::vector<DATA_TYPE>(ni));
    q.resize(nj, std::vector<DATA_TYPE>(ni));

    // Initialize the matrices
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(ni);
            q[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) / static_cast<DATA_TYPE>(nj);
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            r[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) / static_cast<DATA_TYPE>(nj);
        }
    }
}

int main() {
    int ni = 5; // Example value for ni
    int nj = 5; // Example value for nj

    std::vector<std::vector<DATA_TYPE>> a, r, q;

    init_array(ni, nj, a, r, q);

    // Optional: Print the matrices to verify the initialization
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "---" << std::endl;

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << r[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "---" << std::endl;

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << q[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

This C++ code defines a function `init_array` that initializes three matrices (`a`, `r`, and `q`) based on the given dimensions (`ni` and `nj`). The matrices are initialized using nested loops and the formulas provided in the original Fortran code. The `main` function demonstrates how to call `init_array` and print the matrices for verification.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the matrix initialization.

### Fortran Unit Test

First, let's create a Fortran program that calls the `init_array` subroutine and checks the results:

```fortran
program test_init_array
    implicit none
    integer, parameter :: ni = 5, nj = 5
    real, dimension(nj, ni) :: a, r, q
    integer :: i, j
    logical :: test_passed

    call init_array(ni, nj, a, r, q)

    ! Check the values of a
    test_passed = .true.
    do i = 1, ni
        do j = 1, nj
            if (a(j, i) /= (i - 1) * (j - 1) / ni) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do
    if (test_passed) then
        print *, "Test for a passed."
    else
        print *, "Test for a failed."
    endif

    ! Check the values of r
    test_passed = .true.
    do i = 1, ni
        do j = 1, nj
            if (r(j, i) /= (i - 1) * (j + 1) / nj) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do
    if (test_passed) then
        print *, "Test for r passed."
    else
        print *, "Test for r failed."
    endif

    ! Check the values of q
    test_passed = .true.
    do i = 1, ni
        do j = 1, nj
            if (q(j, i) /= (i - 1) * j / nj) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do
    if (test_passed) then
        print *, "Test for q passed."
    else
        print *, "Test for q failed."
    endif

contains

    subroutine init_array(ni, nj, a, r, q)
        implicit none
        integer, intent(in) :: ni, nj
        real, dimension(nj, ni) :: a, r, q
        integer :: i, j

        do i = 1, ni
            do j = 1, nj
                a(j, i) = (i - 1) * (j - 1) / ni
                q(j, i) = (i - 1) * j / nj
            end do
        end do

        do i = 1, ni
            do j = 1, nj
                r(j, i) = (i - 1) * (j + 1) / nj
            end do
        end do
    end subroutine init_array

end program test_init_array
```

### C++ Unit Test

Next, let's create a C++ program that calls the `init_array` function and checks the results:

```cpp
#include <vector>
#include <iostream>
#include <cmath>

using DATA_TYPE = double;

void init_array(int ni, int nj, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& r, std::vector<std::vector<DATA_TYPE>>& q) {
    a.resize(nj, std::vector<DATA_TYPE>(ni));
    r.resize(nj, std::vector<DATA_TYPE>(ni));
    q.resize(nj, std::vector<DATA_TYPE>(ni));

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(ni);
            q[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) / static_cast<DATA_TYPE>(nj);
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            r[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) / static_cast<DATA_TYPE>(nj);
        }
    }
}

bool check_matrix(const std::
