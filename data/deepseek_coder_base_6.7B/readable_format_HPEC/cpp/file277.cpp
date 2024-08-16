To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code, and then replicate its behavior using C++ syntax and constructs. The Fortran code uses OpenMP for parallel processing and a custom module `DRB101` for generating tasks. Since the specifics of the `gen_task` subroutine and the `DRB101` module are not provided, we will focus on the structure and parallel processing aspects.

Here's a C++ translation that captures the essence of the Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

// Assuming the existence of a function equivalent to the Fortran subroutine 'gen_task'
void gen_task(int i) {
    // Placeholder for the actual implementation of 'gen_task'
    // This function should modify the global or passed vector to store the results
}

int main() {
    std::vector<int> a(100);

    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 1; i <= 100; ++i) {
                gen_task(i);
            }
        }
    }

    for (int i = 0; i < 100; ++i) {
        if (a[i] != i + 1) {
            std::cout << "warning: a(" << i << ") = " << a[i] << " not expected " << i + 1 << std::endl;
        }
        // Uncomment the following line to print the values for verification
        // std::cout << a[i] << " " << i + 1 << std::endl;
    }

    return 0;
}
```

Key Points:
- The `#pragma omp parallel` directive is used in C++ to specify parallel regions, similar to the `!$omp parallel` in Fortran.
- The `#pragma omp single` directive ensures that the enclosed block is executed by a single thread, similar to the `!$omp single` in Fortran.
- The `std::vector<int> a(100)` is used to dynamically allocate an array of integers, similar to the `allocate` statement in Fortran.
- The loop that fills the array with values uses 1-based indexing, consistent with the original Fortran code.
- The `gen_task` function is called with each index from 1 to 100. Since the original Fortran code does not specify the implementation of `gen_task`, a placeholder is provided. You should replace the body of `gen_task` with the actual logic that modifies the `a` array.
- The verification loop checks if each element of the array `a` matches the expected value (`i + 1`), printing a warning message if they do not match.

Remember to compile this C++ code with OpenMP support enabled. For example, if you're using `g++`, you would compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we need to create unit tests that check the functionality of the `gen_task` subroutine/function. Since the specifics of `gen_task` are not provided, I'll assume a simple behavior for demonstration purposes: `gen_task` will simply set the corresponding element in the array `a` to `i + 1`.

### Fortran Unit Test

First, let's modify the original Fortran code to include a simple implementation of `gen_task` and then write a unit test.

**Modified Fortran Code with `gen_task` Implementation:**

```fortran
module DRB101
    implicit none
contains
    subroutine gen_task(i, a)
        integer, intent(in) :: i
        integer, intent(inout) :: a(*)
        a(i) = i + 1
    end subroutine gen_task
end module DRB101

program DRB101_task_value_orig_no
    use omp_lib
    use DRB101
    implicit none

    integer :: i
    integer, allocatable :: a(:)

    allocate (a(100))

    !$omp parallel
        !$omp single
        do i = 1, 100
            call gen_task(i, a)
        end do
        !$omp end single
    !$omp end parallel

    do i = 1, 100
        if (a(i) /= i+1) then
            print*,'warning: a(',i,') =',a(i),' not expected',i+1
        end if
    end do
end program
```

**Fortran Unit Test (Using a Simple Test Framework):**

Fortran doesn't have a built-in unit testing framework like some other languages, so we'll create a simple test by manually checking the results.

```fortran
! This is a simple test to verify the functionality of gen_task
program test_gen_task
    use DRB101
    implicit none

    integer :: i
    integer, allocatable :: a(:)
    logical :: test_passed

    allocate (a(100))

    ! Call gen_task for each i
    do i = 1, 100
        call gen_task(i, a)
    end do

    ! Verify each element of a
    test_passed = .true.
    do i = 1, 100
        if (a(i) /= i+1) then
            print*, 'Test failed for i =', i, 'Expected', i+1, 'Got', a(i)
            test_passed = .false.
        end if
    end do

    if (test_passed) then
        print*, 'All tests passed.'
    else
        print*, 'Some tests failed.'
    end if
end program test_gen_task
```

### C++ Unit Test

For C++, we can use a unit testing framework like Google Test for more comprehensive testing. However, for simplicity, I'll provide a basic test similar to the Fortran example.

**Modified C++ Code with `gen_task` Implementation:**

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

void gen_task(int i, std::vector<int>& a) {
    a[i - 1] = i + 1; // Adjust for 0-based indexing
}

int main() {
    std::vector<int> a(100);

    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 1; i <= 100; ++i) {
                gen_task(i, a);
            }
        }
    }

    for (int i = 0; i < 100; ++i) {
        if (a[i] != i + 1) {
            std::cout << "warning: a(" << i << ") = " << a[i] << " not expected " << i + 1 << std::endl;
        }
    }

    return 0;
}
```

**C++ Unit Test (Using a Simple Test Framework):**

```cpp
#include <iostream>
#include <vector>

void gen_task(int i, std::vector<int>& a);

int main() {
    std::vector<int> a(100);
    bool test_passed = true;

    // Call gen_task for each i
    for (int i = 1; i <= 100; ++i) {
        gen_task(i, a);
    }

    // Verify each element of a
    for (int i = 0; i < 100; ++i) {
        if (a[i] != i + 1) {
            std::cout << "Test failed for i = " << i << ". Expected " << i + 1 << " Got " << a[i] << std::endl;
            test_passed = false;
        }
    }

    if (test_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return
