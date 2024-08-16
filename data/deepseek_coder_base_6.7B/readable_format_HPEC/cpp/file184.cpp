Certainly! Below is the translated version of the provided Fortran code into C++. Note that in C++, array indices start from 0, unlike Fortran where they start from 1. Therefore, adjustments are made in the indexing. Additionally, C++ does not have built-in array bounds checking, so it's essential to ensure that the indices are within the bounds of the arrays.

```cpp
#include <iostream>

void bubble(double** ten, int** j1, int** j2, int** j3, int m, int ind) {
    double temp;
    int j_temp;

    if (ind == 1) {
        for (int i = 0; i < m - 1; ++i) {
            if (ten[i][ind] > ten[i + 1][ind]) {
                temp = ten[i + 1][ind];
                ten[i + 1][ind] = ten[i][ind];
                ten[i][ind] = temp;

                j_temp = j1[i + 1][ind];
                j1[i + 1][ind] = j1[i][ind];
                j1[i][ind] = j_temp;

                j_temp = j2[i + 1][ind];
                j2[i + 1][ind] = j2[i][ind];
                j2[i][ind] = j_temp;

                j_temp = j3[i + 1][ind];
                j3[i + 1][ind] = j3[i][ind];
                j3[i][ind] = j_temp;
            }
        }
    } else {
        for (int i = 0; i < m - 1; ++i) {
            if (ten[i][ind] < ten[i + 1][ind]) {
                temp = ten[i + 1][ind];
                ten[i + 1][ind] = ten[i][ind];
                ten[i][ind] = temp;

                j_temp = j1[i + 1][ind];
                j1[i + 1][ind] = j1[i][ind];
                j1[i][ind] = j_temp;

                j_temp = j2[i + 1][ind];
                j2[i + 1][ind] = j2[i][ind];
                j2[i][ind] = j_temp;

                j_temp = j3[i + 1][ind];
                j3[i + 1][ind] = j3[i][ind];
                j3[i][ind] = j_temp;
            }
        }
    }
}

int main() {
    // Example usage
    int m = 5; // Number of elements
    int ind = 1; // Index for comparison

    // Allocate memory for the arrays
    double** ten = new double*[m];
    int** j1 = new int*[m];
    int** j2 = new int*[m];
    int** j3 = new int*[m];

    for (int i = 0; i < m; ++i) {
        ten[i] = new double[2]; // 2 columns
        j1[i] = new int[2]; // 2 columns
        j2[i] = new int[2]; // 2 columns
        j3[i] = new int[2]; // 2 columns
    }

    // Initialize arrays with example values
    for (int i = 0; i < m; ++i) {
        ten[i][0] = i; // Example values
        ten[i][1] = m - i; // Example values
        j1[i][0] = i; // Example values
        j1[i][1] = m - i; // Example values
        j2[i][0] = i; // Example values
        j2[i][1] = m - i; // Example values
        j3[i][0] = i; // Example values
        j3[i][1] = m - i; // Example values
    }

    // Call the bubble sort function
    bubble(ten, j1, j2, j3, m, ind);

    // Print the sorted arrays
    for (int i = 0; i < m; ++i) {
        std::cout << "ten[" << i << "]: " << ten[i][0] << ", " << ten[i][1] << std::endl;
        std::cout << "j1[" << i << "]: " << j1[i][0] << ", " << j1[i][1] << std::endl;
        std::cout << "j2[" << i << "]: " << j2[i][0] << ", " << j2[i][1] << std::endl;
        std::cout << "j3[" << i << "]: " << j3[i][0] << ", " << j3[i][1] << std::endl;
    }

    // Free allocated memory
    for (int i = 0; i < m; ++i) {
        delete[] ten[i];
        delete[] j1[i];
        delete[] j2[i];
        delete[] j3[i];
    }
    delete[] ten;
    delete[] j1;
    delete[] j2;
    delete[] j3;

    return 0;
}
```

This C++ code defines a `bubble` function that performs a bubble sort on the given arrays based on the `ind` parameter. The `main` function demonstrates how to allocate memory for the arrays, initialize them with example values, call the `bubble` function, and then print the sorted arrays. Finally, it deallocates the allocated memory.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify that the sorting functionality works as expected.

### Fortran Unit Test

First, let's create a Fortran program that includes the original subroutine and a test case.

```fortran
program test_bubble
    implicit none
    integer, parameter :: m = 5
    integer :: ind
    double precision, dimension(m, 2) :: ten
    integer, dimension(m, 2) :: j1, j2, j3
    integer :: i

    ! Initialize arrays
    do i = 1, m
        ten(i, 1) = m - i + 1.0
        ten(i, 2) = i
        j1(i, 1) = m - i + 1
        j1(i, 2) = i
        j2(i, 1) = m - i + 1
        j2(i, 2) = i
        j3(i, 1) = m - i + 1
        j3(i, 2) = i
    end do

    ! Set index for comparison
    ind = 1

    ! Call the bubble sort subroutine
    call bubble(ten, j1, j2, j3, m, ind)

    ! Print sorted arrays
    print *, 'Sorted ten array:'
    do i = 1, m
        print *, ten(i, 1), ten(i, 2)
    end do

    print *, 'Sorted j1 array:'
    do i = 1, m
        print *, j1(i, 1), j1(i, 2)
    end do

    print *, 'Sorted j2 array:'
    do i = 1, m
        print *, j2(i, 1), j2(i, 2)
    end do

    print *, 'Sorted j3 array:'
    do i = 1, m
        print *, j3(i, 1), j3(i, 2)
    end do

contains

    subroutine bubble(ten, j1, j2, j3, m, ind)
        implicit none
        integer m, ind, j1(m, 0:1), j2(m, 0:1), j3(m, 0:1)
        double precision ten(m, 0:1)
        double precision temp
        integer i, j_temp

        if (ind .eq. 1) then
            do i = 1, m - 1
                if (ten(i, ind) .gt. ten(i + 1, ind)) then
                    temp = ten(i + 1, ind)
                    ten(i + 1, ind) = ten(i, ind)
                    ten(i, ind) =
