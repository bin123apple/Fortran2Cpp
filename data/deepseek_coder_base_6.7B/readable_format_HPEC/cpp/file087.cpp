To translate the given Fortran code to C++, we need to consider several aspects, including the use of OpenMP for parallelism, array allocation, and function calls. The Fortran code uses OpenMP directives for parallel execution and a custom subroutine `gen_task`. In C++, we can use OpenMP similarly and include the necessary headers for array allocation and I/O operations.

Here's a C++ version of the Fortran code, assuming the existence of a function `gen_task` that matches the signature expected by the Fortran code. Note that in C++, array indexing starts from 0, unlike Fortran where it starts from 1.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

// Assuming the existence of a function similar to gen_task in Fortran
void gen_task(int i) {
    // Placeholder for the actual implementation
    // This function should modify the global array 'a' or take an array as argument
}

int main() {
    const int size = 100;
    std::vector<int> a(size); // Using vector for dynamic array allocation

    // OpenMP parallel region
    #pragma omp parallel
    {
        // OpenMP single directive
        #pragma omp single
        {
            // Parallel loop equivalent to the Fortran do loop
            #pragma omp for
            for (int i = 0; i < size; ++i) {
                gen_task(i + 1); // Adjusting for 0-based indexing
            }
        }
    }

    // Verification loop
    for (int i = 0; i < size; ++i) {
        if (a[i] != i + 1) { // Adjusting for 0-based indexing
            std::cout << "warning: a(" << i << ") = " << a[i] << " not expected " << i + 1 << std::endl;
        }
        // Uncomment the following line if you need to print the values
        // std::cout << a[i] << " " << i + 1 << std::endl;
    }

    return 0;
}
```

Key points in the translation:
- The `std::vector<int>` is used for dynamic array allocation, similar to `allocate` in Fortran.
- OpenMP directives are used similarly to the Fortran code, with `#pragma omp parallel` for parallel execution and `#pragma omp single` for executing a block of code in a single thread.
- The loop in the OpenMP parallel region uses `#pragma omp for` to parallelize the loop, similar to the Fortran `do` loop.
- The function `gen_task` is assumed to be defined elsewhere, and its signature and behavior are not specified in the original Fortran code snippet. You may need to adjust the function signature and its implementation to match the expected behavior.
- The `implicit none` statement in Fortran is not needed in C++ as variable types must be explicitly declared.
- The `use` statements in Fortran, which import modules, are replaced by including the necessary headers in C++.
- The Fortran `print*` statement is replaced by `std::cout` for output in C++.
- Adjustments are made for 0-based indexing in C++, as opposed to Fortran's 1-based indexing.

Remember to compile this C++ code with OpenMP support enabled. For example, if you're using GCC, you would compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves writing additional code that tests the functionality of the `gen_task` function and the main program logic. Given the original task's focus on parallel execution and array manipulation, the tests will focus on verifying that the parallel execution and array manipulation are performed correctly.

### Fortran Unit Test

For the Fortran code, we'll create a simple test within the program that checks if the `gen_task` subroutine is called correctly and if the array `a` is filled as expected. Note that the original Fortran code does not include the implementation of `gen_task`, so we'll assume a hypothetical behavior for demonstration purposes.

```fortran
program DRB100_task_reference_orig_no_test
    use omp_lib
    implicit none
    integer :: i
    integer, allocatable :: a(:)
    logical :: test_passed

    allocate (a(100))

    ! Assuming gen_task sets the array element to its index + 1 for testing purposes
    !$omp parallel
        !$omp single
        do i = 1, 100
            call gen_task(i, a)
        end do
        !$omp end single
    !$omp end parallel

    test_passed = .true.
    do i = 1, 100
        if (a(i) /= i+1) then
            print*, 'Test failed for a(', i, ') = ', a(i), ' expected ', i+1
            test_passed = .false.
        end if
    end do

    if (test_passed) then
        print*, 'All tests passed.'
    else
        print*, 'Some tests failed.'
    end if
end program DRB100_task_reference_orig_no_test

subroutine gen_task(i, a)
    integer, intent(in) :: i
    integer, intent(inout) :: a(:)
    a(i) = i + 1
end subroutine gen_task
```

This test assumes that `gen_task` fills the array `a` with values equal to their indices + 1. You should replace the `gen_task` subroutine with the actual implementation.

### C++ Unit Test

For the C++ code, we'll use a simple test within the `main` function to verify the functionality. Similar to the Fortran test, we'll assume `gen_task` sets the array element to its index + 1 for demonstration purposes.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

void gen_task(int i, std::vector<int>& a) {
    a[i - 1] = i + 1; // Adjust for 0-based indexing
}

int main() {
    const int size = 100;
    std::vector<int> a(size);
    bool test_passed = true;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp for
            for (int i = 1; i <= size; ++i) {
                gen_task(i, a);
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        if (a[i] != i + 1) {
            std::cout << "Test failed for a(" << i << ") = " << a[i] << " expected " << i + 1 << std::endl;
            test_passed = false;
        }
    }

    if (test_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}
```

This C++ test assumes that `gen_task` fills the vector `a` with values equal to their indices + 1. You should replace the `gen_task` function with the actual implementation.

### Compiling and Running the Tests

- For the Fortran code, use a command similar to:
  ```sh
  gfortran -fopenmp your_fortran_test_program.f90 -o fortran_test
  ./fortran_test
  ```
- For the C++ code, use a command similar to:
  ```sh
  g++ -fopenmp your_cpp_test_program.cpp -o cpp_test
  ./cpp_test
  ```

These tests are basic and assume that `gen_task` correctly fills the array or vector with values as specified. You should adjust the tests according to the actual behavior of `gen_task`.
