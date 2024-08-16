To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code, and then replicate its behavior using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for parallelism and SIMD directives to vectorize the loop. Below is the translated C++ code:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    int i, j;

    // Initialize the array
    for (i = 0; i < 8; ++i) {
        var[i] = 0;
    }

    // OpenMP target directives
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams directive
        #pragma omp teams num_teams(1) thread_limit(1048)
        {
            // OpenMP distribute parallel do reduction(+:var)
            #pragma omp distribute parallel for reduction(+:var[:])
            for (i = 0; i < 20; ++i) {
                // OpenMP simd directive
                #pragma omp simd
                for (j = 0; j < 8; ++j) {
                    var[j] = var[j] + 1;
                }
            }
        }
    }

    // Print the results
    for (i = 0; i < 8; ++i) {
        if (var[i] != 20) {
            std::cout << var[i] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Array Initialization**: The array `var` is initialized to 0 using a loop.
3. **OpenMP Target Directives**: The `#pragma omp target` directive is used to specify the target for parallel execution. In this case, it's GPU device 0.
4. **OpenMP Teams Directive**: The `#pragma omp teams` directive is used to specify the number of teams and the thread limit.
5. **OpenMP Distribute Parallel Do Reduction**: The `#pragma omp distribute parallel for reduction(+:var[:])` directive is used to distribute the work among threads and perform a reduction on the array `var`.
6. **OpenMP SIMD Directive**: The `#pragma omp simd` directive is used to vectorize the loop.
7. **Printing the Results**: The results are printed to the standard output using a loop.

### Notes:
- **Array Indexing**: C++ uses 0-based indexing, so the loop indices start from 0 and go up to 7.
- **Reduction Clause**: The reduction clause in OpenMP is slightly different in C++. The syntax `reduction(+:var[:])` is used to perform an inclusive scan on the array `var`.
- **OpenMP Directives**: The OpenMP directives are used in a similar way as in Fortran, but with C++ syntax.

This C++ code should exhibit similar functionality to the original Fortran code, using OpenMP for parallelism and SIMD vectorization.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking if the final state of the `var` array matches the expected results after the parallel execution. For simplicity, we'll focus on testing the final state of the array, as the parallel execution logic is more complex and not directly accessible in the unit tests.

### Fortran Unit Test

For Fortran, we can write a simple test program that checks the final state of the `var` array.

```fortran
program test_DRB162_nolocksimd_orig_gpu_no
    use omp_lib
    implicit none

    integer :: var(8)
    integer :: i, expected_value
    logical :: test_passed

    ! Initialize the array
    do i = 1, 8
        var(i) = 0
    end do

    ! OpenMP target directives
    !$omp target map(tofrom:var) device(0)
    !$omp teams num_teams(1) thread_limit(1048)
    !$omp distribute parallel do reduction(+:var)
    do i = 1, 20
        !$omp simd
        do j = 1, 8
            var(j) = var(j) + 1
        end do
        !$omp end simd
    end do
    !$omp end distribute parallel do
    !$omp end teams
    !$omp end target

    ! Check the results
    test_passed = .true.
    expected_value = 20
    do i = 1, 8
        if (var(i) /= expected_value) then
            print*, "Test failed for element: ", i, "Expected: ", expected_value, "Got: ", var(i)
            test_passed = .false.
        end if
    end do

    if (test_passed) then
        print*, "All tests passed."
    else
        print*, "Some tests failed."
    end if

end program test_DRB162_nolocksimd_orig_gpu_no
```

### C++ Unit Test

For C++, we can use a simple test framework like Google Test, but for simplicity, we'll write a basic test similar to the Fortran one.

```cpp
#include <iostream>
#include <omp.h>

bool test_var_array() {
    int var[8];
    int i, j;
    bool test_passed = true;
    int expected_value = 20;

    // Initialize the array
    for (i = 0; i < 8; ++i) {
        var[i] = 0;
    }

    // OpenMP target directives
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams directive
        #pragma omp teams num_teams(1) thread_limit(1048)
        {
            // OpenMP distribute parallel do reduction(+:var)
            #pragma omp distribute parallel for reduction(+:var[:])
            for (i = 0; i < 20; ++i) {
                // OpenMP simd directive
                #pragma omp simd
                for (j = 0; j < 8; ++j) {
                    var[j] = var[j] + 1;
                }
            }
        }
    }

    // Check the results
    for (i = 0; i < 8; ++i) {
        if (var[i] != expected_value) {
            std::cout << "Test failed for element: " << i << " Expected: " << expected_value << " Got: " << var[i] << std::endl;
            test_passed = false;
        }
    }

    return test_passed;
}

int main() {
    if (test_var_array()) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Test Program**:
   - The program initializes the `var` array.
   - It then performs the parallel operations as in the original program.
   - It checks if each element of the `var` array matches the expected value (20) and prints the result.

2. **C++ Test Function**:
   - The `test_var_array` function initializes the `var` array.
   - It performs the parallel operations using OpenMP directives.
   - It checks if each element of the `var` array matches the expected value (20) and prints the result.
   - The `main` function calls the `test_var_array` function and prints the test result.

These unit tests will help verify that the final state of the `var` array matches the expected results after the parallel execution in both the Fortran and C++ versions of the code.
