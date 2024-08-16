To translate the provided Fortran code to C++, we need to consider several aspects, such as array indexing, loop structures, and the way functions (or subroutines in Fortran) are called. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran passes arrays and variables by reference by default, while in C++, we need to explicitly use pointers or references to achieve the same effect. Given the nature of the Fortran code, we'll assume that `u`, `rhs`, and `grid_points` are 4D arrays (or at least 3D arrays for the first 3 dimensions) managed somehow in the C++ code. The `timer_start` and `timer_stop` functions are assumed to be defined elsewhere in the C++ code.

Here's a C++ translation of the Fortran code:

```cpp
#include <iostream>

// Assuming these are defined somewhere in your C++ code
extern bool timeron;
extern void timer_start(int t_add);
extern void timer_stop(int t_add);
extern int grid_points[3]; // Assuming grid_points is a global or passed array

// Assuming u, rhs are 4D arrays managed somehow in your C++ code
// The actual declaration would depend on how you manage these arrays in C++
extern double u[5][grid_points[0]-2][grid_points[1]-2][grid_points[2]-2];
extern double rhs[5][grid_points[0]-2][grid_points[1]-2][grid_points[2]-2];

void add() {
    if (timeron) timer_start(1); // Assuming t_add is a constant or defined somewhere

    for (int k = 0; k < grid_points[2] - 2; ++k) {
        for (int j = 0; j < grid_points[1] - 2; ++j) {
            for (int i = 0; i < grid_points[0] - 2; ++i) {
                for (int m = 0; m < 5; ++m) {
                    u[m][i][j][k] = u[m][i][j][k] + rhs[m][i][j][k];
                }
            }
        }
    }

    if (timeron) timer_stop(1);
}

int main() {
    // Example usage of add function
    add();
    return 0;
}
```

This translation assumes that `u`, `rhs`, and `grid_points` are defined and managed in a way that's compatible with C++. The `timeron`, `timer_start`, and `timer_stop` functions are also assumed to be defined elsewhere in your C++ code. The translation also assumes that the 4D arrays `u` and `rhs` are accessible in the same way in C++, which might require additional setup depending on how you choose to manage these arrays.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests. These tests will involve initializing the arrays `u` and `rhs` with some test values, then calling the `add` subroutine/function and finally checking if the results are as expected.

### Fortran Unit Test

For the Fortran code, we'll create a simple test program that uses the `add` subroutine. We'll assume that `bt_data` module contains the necessary definitions for `u`, `rhs`, and `grid_points`.

```fortran
program test_add
    use bt_data
    implicit none

    integer :: i, j, k, m

    ! Initialize grid_points
    grid_points(1) = 4
    grid_points(2) = 4
    grid_points(3) = 4

    ! Initialize u and rhs with some test values
    do m = 1, 5
        do k = 1, grid_points(3)-2
            do j = 1, grid_points(2)-2
                do i = 1, grid_points(1)-2
                    u(m,i,j,k) = 1.0
                    rhs(m,i,j,k) = 0.5
                end do
            end do
        end do
    end do

    ! Call the add subroutine
    call add()

    ! Check the results
    do m = 1, 5
        do k = 1, grid_points(3)-2
            do j = 1, grid_points(2)-2
                do i = 1, grid_points(1)-2
                    if (u(m,i,j,k) /= 1.5) then
                        print *, "Test failed at u(", m, ",", i, ",", j, ",", k, ")"
                        stop
                    end if
                end do
            end do
        end do
    end do

    print *, "All tests passed."

end program test_add
```

### C++ Unit Test

For the C++ code, we'll use a simple test case similar to the Fortran one. We'll initialize the arrays `u` and `rhs` with test values, call the `add` function, and then verify the results.

```cpp
#include <iostream>
#include <cassert>

// Assuming these are defined somewhere in your C++ code
extern bool timeron;
extern void timer_start(int t_add);
extern void timer_stop(int t_add);
extern int grid_points[3]; // Assuming grid_points is a global or passed array

// Assuming u, rhs are 4D arrays managed somehow in your C++ code
// The actual declaration would depend on how you manage these arrays in C++
extern double u[5][grid_points[0]-2][grid_points[1]-2][grid_points[2]-2];
extern double rhs[5][grid_points[0]-2][grid_points[1]-2][grid_points[2]-2];

void add(); // Assuming add function is declared

int main() {
    // Initialize grid_points
    grid_points[0] = 4;
    grid_points[1] = 4;
    grid_points[2] = 4;

    // Initialize u and rhs with some test values
    for (int m = 0; m < 5; ++m) {
        for (int k = 0; k < grid_points[2] - 2; ++k) {
            for (int j = 0; j < grid_points[1] - 2; ++j) {
                for (int i = 0; i < grid_points[0] - 2; ++i) {
                    u[m][i][j][k] = 1.0;
                    rhs[m][i][j][k] = 0.5;
                }
            }
        }
    }

    // Call the add function
    add();

    // Check the results
    for (int m = 0; m < 5; ++m) {
        for (int k = 0; k < grid_points[2] - 2; ++k) {
            for (int j = 0; j < grid_points[1] - 2; ++j) {
                for (int i = 0; i < grid_points[0] - 2; ++i) {
                    assert(u[m][i][j][k] == 1.5);
                }
            }
        }
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

These unit tests are basic and assume that the arrays `u` and `rhs` are correctly initialized and that the `add` subroutine/function works as expected. In a real-world scenario, you might want to test with more complex scenarios, including edge cases.
