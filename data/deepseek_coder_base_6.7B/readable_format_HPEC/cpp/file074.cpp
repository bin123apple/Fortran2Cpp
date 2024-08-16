To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, memory management, and parallel execution. The Fortran code uses OpenMP for parallelization, which has a direct equivalent in C++ using OpenMP as well. Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len), b(len), c(len);

    // Initialize arrays
    for (int i = 0; i < len; ++i) {
        a[i] = (i + 1) / 2.0;
        b[i] = (i + 1) / 3.0;
        c[i] = (i + 1) / 7.0;
    }

    // Parallel loop with linear clause
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < len; ++i) {
        c[i] = c[i] + a[i] * b[i];
    }

    // Print a value from the array c to verify correctness
    std::cout << "c[49] = " << c[49] << std::endl;

    return 0;
}
```

Key points in the translation:

1. **Array Initialization**: In C++, arrays are zero-indexed, unlike Fortran which is one-indexed. Therefore, the loop in the `for` statement starts from `0` and goes up to `len - 1`.

2. **Memory Management**: The Fortran code uses `allocate` and `deallocate` for dynamic arrays. In C++, `std::vector` is used, which manages memory automatically.

3. **Parallel Execution**: The OpenMP directives in C++ (`#pragma omp parallel for`) are used to parallelize the loop. The `schedule(static)` clause is used to ensure that the iterations are distributed across threads in a static manner.

4. **Printing**: The Fortran `print` statement is replaced with `std::cout` in C++ for console output.

5. **Indexing**: The Fortran code uses `real(dp)` to specify double precision. In C++, `double` is used directly.

6. **Loop Constructs**: The Fortran `do` loop is replaced with a C++ `for` loop.

7. **Program Structure**: The C++ program starts with including necessary headers and using the OpenMP library. The `main` function serves as the entry point for the program.

Make sure to compile the C++ code with OpenMP support enabled. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will check if the array `c` is correctly updated based on the operations performed on arrays `a` and `b`.

### Fortran Unit Test

For the Fortran code, we can add a simple test after the computation to check if `c(50)` is as expected. Here's how you can do it:

```fortran
program DRB112_linear_orig_no
    use omp_lib
    implicit none

    integer :: len, i, j
    integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:), allocatable :: a, b, c
    real(dp) :: expected_value

    len = 100
    i = 0
    j = 0

    allocate(a(len))
    allocate(b(len))
    allocate(c(len))

    do i = 1, len
        a(i) = (real(i, dp)) / 2.0
        b(i) = (real(i, dp)) / 3.0
        c(i) = (real(i, dp)) / 7.0
    end do

    !$omp parallel do linear(j)
    do i = 1, len
        c(j) = c(j) + a(i) * b(i)
        j = j + 1
    end do
    !$omp end parallel do

    ! Expected value calculation
    expected_value = 0.0
    do i = 1, len
        expected_value = expected_value + (a(i) * b(i)) / 7.0
    end do

    ! Test
    if (abs(c(50) - expected_value) < 1.0E-6) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if

    if (allocated(a)) deallocate(a)
    if (allocated(b)) deallocate(b)
end program DRB112_linear_orig_no
```

### C++ Unit Test

For the C++ code, we can use a simple assertion to check if `c[49]` is as expected. Here's how you can do it:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>
#include <cassert>

int main() {
    const int len = 100;
    std::vector<double> a(len), b(len), c(len);
    double expected_value = 0.0;

    // Initialize arrays
    for (int i = 0; i < len; ++i) {
        a[i] = (i + 1) / 2.0;
        b[i] = (i + 1) / 3.0;
        c[i] = (i + 1) / 7.0;
    }

    // Parallel loop with linear clause
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < len; ++i) {
        c[i] = c[i] + a[i] * b[i];
    }

    // Expected value calculation
    for (int i = 0; i < len; ++i) {
        expected_value += (a[i] * b[i]) / 7.0;
    }

    // Test
    assert(std::abs(c[49] - expected_value) < 1.0E-6);
    std::cout << "Test passed." << std::endl;

    return 0;
}
```

To compile and run the Fortran code with OpenMP support, use:

```sh
gfortran -fopenmp your_fortran_code.f90 -o fortran_test
./fortran_test
```

To compile and run the C++ code with OpenMP support, use:

```sh
g++ -fopenmp your_cpp_code.cpp -o cpp_test
./cpp_test
```

These unit tests will verify that the array `c` is correctly updated based on the operations performed on arrays `a` and `b`. If the tests pass, it means the translation is correct.
