Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));

    // Parallel region with default(none)
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    // Parallel region with default(shared)
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            b[i][j] = b[i][j] + 1;
        }
    }

    // Printing a specific element to verify the operation
    std::cout << a[49][49] << " " << b[49][49] << std::endl;

    return 0;
}
```

### Explanation:
1. **Include Libraries**:
   - `#include <iostream>` for input/output operations.
   - `#include <vector>` for dynamic arrays.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Main Function**:
   - Defines the main function where the program execution begins.

3. **Constants and Matrices**:
   - Uses `const int len = 100;` to define the matrix size.
   - Initializes two 2D `std::vector` matrices `a` and `b` with size `len x len`.

4. **Parallel Regions**:
   - The first parallel region uses `#pragma omp parallel for collapse(2)` to parallelize the nested loops.
     - `collapse(2)` is used to collapse the nested loops into a single loop, which is more efficient for OpenMP.
   - The second parallel region also uses `#pragma omp parallel for collapse(2)` but without specifying any variables as it inherits the default sharing and scoping from the parent region.

5. **Loop Constructs**:
   - Nested loops are used to increment each element of the matrices `a` and `b`.

6. **Output**:
   - Prints the values of `a[49][49]` and `b[49][49]` to verify the operation.

### Compilation and Execution:
To compile and run this C++ program, you need to enable OpenMP support. Here's how you can do it:

```sh
g++ -fopenmp your_program.cpp -o your_program
./your_program
```

Replace `your_program.cpp` with the name of your C++ source file.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB113_default_orig_no
    use omp_lib
    implicit none

    integer :: i, j
    integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:,:), allocatable :: a, b
    real(dp) :: expected_value

    ! Initialize matrices
    allocate(a(100, 100))
    allocate(b(100, 100))
    a = 0.0_dp
    b = 0.0_dp

    ! Parallel region with default(none)
    !$omp parallel do default(none) shared(a) private(i,j)
    do i = 1, 100
        do j = 1, 100
            a(i,j) = a(i,j) + 1
        end do
    end do
    !$omp end parallel do

    ! Parallel region with default(shared)
    !$omp parallel do default(shared) private(i,j)
    do i = 1, 100
        do j = 1, 100
            b(i,j) = b(i,j) + 1
        end do
    end do
    !$omp end parallel do

    ! Check results
    expected_value = 100.0_dp
    if (a(50,50) == expected_value .and. b(50,50) == expected_value) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if

    ! Deallocate matrices
    deallocate(a, b)
end program test_DRB113_default_orig_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cassert>

int main() {
    const int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len, 0.0));
    std::vector<std::vector<double>> b(len, std::vector<double>(len, 0.0));

    // Parallel region with default(none)
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    // Parallel region with default(shared)
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            b[i][j] = b[i][j] + 1;
        }
    }

    // Check results
    const double expected_value = 100.0;
    assert(a[49][49] == expected_value && b[49][49] == expected_value);

    std::cout << "Test Passed" << std::endl;

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - Initializes the matrices `a` and `b` with zeros.
   - Performs the parallel operations as in the original code.
   - Checks if the final values in the middle of the matrices are as expected (100).
   - Prints "Test Passed" if the values are correct, otherwise "Test Failed".

2. **C++ Unit Test Code**:
   - Initializes the matrices `a` and `b` with zeros.
   - Performs the parallel operations as in the translated code.
   - Uses `assert` to check if the final values in the middle of the matrices are as expected (100).
   - Prints "Test Passed" if the values are correct.

### Compilation and Execution:

- **Fortran**:
  ```sh
  gfortran -fopenmp test_DRB113_default_orig_no.f90 -o test_DRB113_default_orig_no
  ./test_DRB113_default_orig_no
  ```

- **C++**:
  ```sh
  g++ -fopenmp test_DRB113_default_orig_no.cpp -o test_DRB113_default_orig_no
  ./test_DRB113_default_orig_no
  ```

These unit tests will help verify the correctness of the translation by checking if the operations on the matrices produce the expected results.
