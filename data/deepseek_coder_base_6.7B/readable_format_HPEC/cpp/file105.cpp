To translate the given Fortran code to C++, we need to understand the structure and functionality of the original Fortran code and then implement similar behavior using C++ syntax and OpenMP directives. The Fortran code initializes `x` and `y` with specific values, then copies these values to a private copy within a parallel region, and finally prints these values.

Here's how you can translate the given Fortran code to C++ using OpenMP:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    double x;
    int y;

    #pragma omp parallel
    {
        #pragma omp single
        {
            x = 1.0;
            y = 1;
        }
        #pragma omp barrier
        #pragma omp single copyprivate(x, y)
        {
            // This block has a private copy of x and y
            // Any modifications to x and y within this block will not affect the original variables
        }
    }

    std::cout << "x = " << x << "  y = " << y << std::endl;

    return 0;
}
```

### Explanation:
1. **OpenMP Pragmas**: The `#pragma omp parallel` and `#pragma omp single` directives are used in C++ to parallelize and synchronize code blocks, respectively. The `#pragma omp barrier` directive is used to synchronize the parallel threads.
2. **Private Copy**: The `#pragma omp single copyprivate(x, y)` directive ensures that the variables `x` and `y` are private to each thread in the `single` block. Any modifications to `x` and `y` within this block will not affect the original variables.
3. **Initialization**: The variables `x` and `y` are initialized within the `single` block.
4. **Output**: The values of `x` and `y` are printed to the standard output.

### Notes:
- The `#pragma omp parallel` block is executed in parallel, and the `#pragma omp single` ensures that only one thread executes the code within it.
- The `#pragma omp barrier` ensures that all threads reach this point before proceeding.
- The `#pragma omp single copyprivate(x, y)` ensures that `x` and `y` are private to each thread, preventing race conditions or unexpected behavior.
- The `std::cout` is used for output in C++.

This C++ code should exhibit the same functionality as the original Fortran code, with the added parallelism and OpenMP directives.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the values of `x` and `y` after they are set within the parallel region. However, it's important to note that the original Fortran code does not explicitly set `x` and `y` to specific values within the parallel region, as the `copyprivate` clause ensures that each thread has its own private copy. The C++ code, on the other hand, explicitly initializes `x` and `y` within the `single` block, which is a direct translation of the Fortran code's behavior.

### Fortran Unit Test

For the Fortran code, we can write a simple test by adding checks after the parallel region. Fortran does not have a built-in unit testing framework like some other languages, so we'll do a basic check.

```fortran
program test_DRB102_copyprivate_orig_no
    use omp_lib
    use DRB102
    implicit none

    real :: x
    integer :: y
    logical :: test_passed

    !$omp parallel
        !$omp single
            x = 1.0
            y = 1
        !$omp end single copyprivate(x,y)
    !$omp end parallel

    ! Check the values of x and y
    test_passed = .true.
    if (x /= 1.0) then
        print *, 'Test failed for x'
        test_passed = .false.
    endif
    if (y /= 1) then
        print *, 'Test failed for y'
        test_passed = .false.
    endif

    if (test_passed) then
        print *, 'All tests passed'
    endif

end program test_DRB102_copyprivate_orig_no
```

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example. C++ has more sophisticated testing frameworks available (like Google Test), but for simplicity, we'll stick to basic checks.

```cpp
#include <iostream>
#include <omp.h>

bool test_values(double x, int y) {
    if (x != 1.0 || y != 1) {
        std::cerr << "Test failed for x or y" << std::endl;
        return false;
    }
    return true;
}

int main() {
    double x;
    int y;

    #pragma omp parallel
    {
        #pragma omp single
        {
            x = 1.0;
            y = 1;
        }
        #pragma omp barrier
        #pragma omp single copyprivate(x, y)
        {
            // This block has a private copy of x and y
            // Any modifications to x and y within this block will not affect the original variables
        }
    }

    if (test_values(x, y)) {
        std::cout << "All tests passed" << std::endl;
    }

    return 0;
}
```

### Explanation

- **Fortran Test**: After the parallel region, we check if `x` and `y` have the expected values. If not, we print an error message.
- **C++ Test**: Similar to the Fortran test, we check if `x` and `y` have the expected values. If not, we print an error message.

### Running the Tests

- **Fortran**: Compile the Fortran test code with an OpenMP-enabled Fortran compiler (e.g., `gfortran -fopenmp test_DRB102_copyprivate_orig_no.f90 -o test_DRB102_copyprivate_orig_no`) and run the executable.
- **C++**: Compile the C++ test code with an OpenMP-enabled C++ compiler (e.g., `g++ -fopenmp test_DRB102_copyprivate_orig_no.cpp -o test_DRB102_copyprivate_orig_no`) and run the executable.

These tests will verify that the values of `x` and `y` are as expected after the parallel region, ensuring that the translation from Fortran to C++ maintains the intended functionality.
