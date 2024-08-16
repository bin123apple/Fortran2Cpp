Certainly! Below is the translated version of the provided Fortran code to C++. This translation uses OpenMP for parallelization, similar to the original Fortran code.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    const int size = 100;
    int a[size];

    // Initialize the array
    for (int i = 0; i < size; ++i) {
        a[i] = 0;
    }

    // Parallel loop to increment each element of the array
    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        a[i] = a[i] + 1;
    }

    return 0;
}
```

### Explanation:
1. **Include necessary headers**: The `<iostream>` header is included for input/output operations, although it's not strictly necessary for this specific code. The `<omp.h>` header is included for OpenMP functionalities.

2. **Define constants and variables**: The size of the array is defined as `const int size = 100;`. The array `a` is declared with `int a[size];`.

3. **Initialize the array**: A loop is used to initialize each element of the array to `0`. This step is not explicitly shown in the Fortran code but is a good practice in C++ to ensure all elements are initialized.

4. **Parallel loop**: The `#pragma omp parallel for` directive is used to parallelize the loop. This directive tells the compiler to parallelize the loop across multiple threads. The loop runs from `0` to `size - 1` because C++ uses 0-based indexing.

5. **Increment each element**: Each element of the array is incremented by `1`.

### Compilation and Execution:
To compile and run this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp your_program.cpp -o your_program
./your_program
```

Replace `your_program.cpp` with the name of your C++ source file.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program DRB045_doall1_orig_no_test
    use omp_lib
    implicit none

    integer :: i
    integer :: a(100)
    logical :: test_passed

    ! Initialize the array
    a = 0

    ! Parallel loop to increment each element of the array
    !$omp parallel do
    do i = 1, 100
        a(i) = a(i) + 1
    end do
    !$omp end parallel do

    ! Verify the result
    test_passed = .true.
    do i = 1, 100
        if (a(i) /= 1) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test Passed: All elements are incremented."
    else
        print *, "Test Failed: Not all elements are incremented."
    endif

end program DRB045_doall1_orig_no_test
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    const int size = 100;
    int a[size];
    bool test_passed = true;

    // Initialize the array
    for (int i = 0; i < size; ++i) {
        a[i] = 0;
    }

    // Parallel loop to increment each element of the array
    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        a[i] = a[i] + 1;
    }

    // Verify the result
    for (int i = 0; i < size; ++i) {
        if (a[i] != 1) {
            test_passed = false;
            break;
        }
    }

    if (test_passed) {
        std::cout << "Test Passed: All elements are incremented." << std::endl;
    } else {
        std::cout << "Test Failed: Not all elements are incremented." << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The array `a` is initialized to `0`.
   - The parallel loop increments each element of the array.
   - A loop checks if all elements are incremented to `1`. If any element is not `1`, the test fails.
   - The result is printed to the console.

2. **C++ Unit Test Code**:
   - The array `a` is initialized to `0`.
   - The parallel loop increments each element of the array.
   - A loop checks if all elements are incremented to `1`. If any element is not `1`, the test fails.
   - The result is printed to the console.

### Compilation and Execution:

- **Fortran**:
  ```sh
  gfortran -fopenmp DRB045_doall1_orig_no_test.f90 -o DRB045_doall1_orig_no_test
  ./DRB045_doall1_orig_no_test
  ```

- **C++**:
  ```sh
  g++ -fopenmp DRB045_doall1_orig_no_test.cpp -o DRB045_doall1_orig_no_test
  ./DRB045_doall1_orig_no_test
  ```

These unit tests will help verify that the translation from Fortran to C++ is correct by ensuring that all elements of the array are incremented by `1`.
