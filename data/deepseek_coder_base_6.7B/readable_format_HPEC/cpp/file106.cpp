To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, parallel execution, and OpenMP directives. The Fortran code uses OpenMP for parallel execution and array indexing starts from 1, while C++ array indexing starts from 0. Here's a C++ version of the code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> var(100, 1); // Initialize vector with 100 elements set to 1

    // OpenMP target directive is not directly supported in C++, but we can achieve similar functionality with OpenMP directives.
    // The device clause is not applicable in the same way in C++ as it is in Fortran, so we'll omit it for simplicity.
    #pragma omp parallel for ordered
    for (int i = 1; i < 100; ++i) { // Loop starts from 1 to 99 to match Fortran's 2 to 100
        #pragma omp ordered
        {
            var[i] = var[i - 1] + 1;
        }
    }

    // Check for data races
    for (int i = 0; i < 100; ++i) {
        if (var[i] != i + 1) { // +1 to match Fortran's 1 to 100 comparison
            std::cout << "Data Race Present" << std::endl;
            break; // Exit the loop on the first occurrence
        }
    }

    return 0;
}
```

Key Points:
- We use `std::vector<int>` to represent the array of integers.
- OpenMP's `#pragma omp parallel for ordered` directive is used to parallelize the loop with ordered execution.
- Array indexing in C++ starts from 0, so we adjust the loop to start from 1 and use `i + 1` when checking the condition.
- The `#pragma omp ordered` block ensures that each thread updates its corresponding element in the vector in order.
- The OpenMP target directive is not directly supported in C++, so we omit the `#pragma omp target` and focus on achieving the parallel execution with OpenMP.
- We use `#include <omp.h>` to include OpenMP functionalities.
- We use `std::cout` for printing, which is part of the `<iostream>` header.

This C++ code should exhibit similar functionality to the original Fortran code, with parallel execution and data race checking.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ codes involves checking the final state of the `var` array to ensure it has been correctly updated. For simplicity, we'll focus on a basic approach to testing rather than using a unit testing framework, as the scope of this example is straightforward.

### Fortran Unit Test

Since Fortran doesn't have a built-in unit testing framework, we'll write a simple test within the program itself. This test will check if the array `var` has been correctly updated.

```fortran
program DRB155_missingordered_orig_gpu_no_test
    use omp_lib
    implicit none

    integer :: var(100)
    integer :: i
    logical :: test_passed

    do i = 1, 100
        var(i) = 1
    end do

    !$omp target map(tofrom:var) device(0)
    !$omp parallel do ordered
    do i = 2, 100
        !$omp ordered
        var(i) = var(i-1)+1
        !$omp end ordered
    end do
    !$omp end parallel do
    !$omp end target

    test_passed = .TRUE.
    do i = 1, 100
        if (var(i)/=i) then
            test_passed = .FALSE.
            exit
        end if
    end do

    if (test_passed) then
        print*,"Test Passed"
    else
        print*,"Test Failed"
    end if

end program
```

### C++ Unit Test

For C++, we can use a simple approach similar to the Fortran example. We'll include a basic test within the `main` function to verify the final state of the `var` vector.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> var(100, 1); // Initialize vector with 100 elements set to 1

    #pragma omp parallel for ordered
    for (int i = 1; i < 100; ++i) {
        #pragma omp ordered
        {
            var[i] = var[i - 1] + 1;
        }
    }

    // Test
    bool test_passed = true;
    for (int i = 0; i < 100; ++i) {
        if (var[i] != i + 1) {
            test_passed = false;
            break;
        }
    }

    if (test_passed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Running the Tests

To run these tests, you'll need a Fortran and C++ compiler that supports OpenMP, such as the GNU Compiler Collection (GCC).

- **Fortran**: Compile with `gfortran -fopenmp DRB155_missingordered_orig_gpu_no_test.f90 -o test_fortran` and run with `./test_fortran`.
- **C++**: Compile with `g++ -fopenmp DRB155_missingordered_orig_gpu_no_test.cpp -o test_cpp` and run with `./test_cpp`.

Both tests should output "Test Passed" if the array `var` has been correctly updated, verifying that the translation from Fortran to C++ has been done correctly.
