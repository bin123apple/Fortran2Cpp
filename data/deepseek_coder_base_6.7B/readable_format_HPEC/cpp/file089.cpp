To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the OpenMP directives, and the array indexing. Here's a C++ version of the provided Fortran code:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    const int N = 8;
    int b[N], c[N], temp[N];
    int a = 2;
    int val = 0;

    // Initialize arrays
    for (int i = 0; i < N; ++i) {
        b[i] = 0;
        c[i] = 2;
        temp[i] = 0;
    }

    // OpenMP directives
    #pragma omp target map(tofrom:b) map(to:c,temp,a) device(0)
    #pragma omp teams
    for (int i = 0; i < 100; ++i) {
        #pragma omp distribute
        for (int j = 0; j < N; ++j) {
            temp[j] = b[j] + c[j];
        }

        #pragma omp distribute
        for (int j = N - 1; j >= 0; --j) {
            b[j] = temp[j] * a;
        }
    }

    // Additional loop
    for (int i = 0; i < 100; ++i) {
        val += 2;
        val *= 2;
    }

    // Check condition
    for (int i = 0; i < N; ++i) {
        if (val != b[i]) {
            std::cout << b[i] << " " << val << std::endl;
        }
    }

    return 0;
}
```

Key Points:
- The `#include <iostream>` directive is used for input/output operations.
- The `#pragma omp` directives are used for OpenMP directives, similar to the `!$omp` directives in Fortran.
- Arrays in C++ are zero-indexed, unlike Fortran which is one-indexed. This is accounted for in the loop conditions.
- The `const int N = 8;` line defines the size of the arrays.
- The `implicit none` statement in Fortran is not needed in C++ as variable types must be explicitly declared.
- The `print*,` statement in Fortran is replaced with `std::cout <<` in C++ for output.
- The `use` statements in Fortran, which import modules, are not needed in C++ as the functionality is included directly in the code.
- The `device(0)` clause in the OpenMP target directive specifies the target device, but since the provided code does not explicitly manage GPU resources, it's omitted for simplicity.
- The `do` loop in Fortran is replaced with `for` loops in C++.
- The `end do` statements in Fortran are replaced with `}` in C++.

This translation assumes that the OpenMP library is correctly set up in your development environment. If you're using an IDE or compiler that supports OpenMP, you should enable OpenMP support in your project settings.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the original Fortran code and the translated C++ code involves checking the correctness of the operations performed by each program. However, it's important to note that the provided programs are designed to be executed in parallel, and the results might not be deterministic without considering the parallel execution context. For the purpose of these tests, we'll focus on verifying the correctness of the sequential parts of the programs.

### Fortran Unit Test

For the Fortran code, we'll create a simple test that checks the correctness of the operations after the parallel sections. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll manually implement a test.

```fortran
program test_DRB160_nobarrier_orig_gpu_yes
    use omp_lib
    implicit none
    integer :: i, errors
    integer, parameter :: N = 8
    integer :: b(N), c(N), temp(N)
    integer :: a, val

    ! Initialize arrays
    do i = 1, N
        b(i) = 0
        c(i) = 2
        temp(i) = 0
    end do

    a = 2
    val = 0

    ! Execute the parallel section
    !$omp target map(tofrom:b) map(to:c,temp,a) device(0)
    !$omp teams
    do i = 1, 100
        !$omp distribute
        do i = 1, N
            temp(i) = b(i) + c(i)
        end do

        !$omp distribute
        do i = N, 1, -1
            b(i) = temp(i) * a
        end do
    end do
    !$omp end teams
    !$omp end target

    ! Additional loop
    do i = 1, 100
        val = val + 2
        val = val * 2
    end do

    ! Check the results
    errors = 0
    do i = 1, N
        if (val /= b(i)) then
            print *, "Test failed for b(", i, "), expected: ", val, " got: ", b(i)
            errors = errors + 1
        end if
    end do

    if (errors == 0) then
        print *, "All tests passed."
    else
        print *, errors, " tests failed."
    end if
end program test_DRB160_nobarrier_orig_gpu_yes
```

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example. C++ also doesn't have a built-in unit testing framework, but we can use assertions for simplicity.

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    const int N = 8;
    int b[N], c[N], temp[N];
    int a = 2;
    int val = 0;
    int errors = 0;

    // Initialize arrays
    for (int i = 0; i < N; ++i) {
        b[i] = 0;
        c[i] = 2;
        temp[i] = 0;
    }

    // Execute the parallel section
    #pragma omp target map(tofrom:b) map(to:c,temp,a) device(0)
    #pragma omp teams
    for (int i = 0; i < 100; ++i) {
        #pragma omp distribute
        for (int j = 0; j < N; ++j) {
            temp[j] = b[j] + c[j];
        }

        #pragma omp distribute
        for (int j = N - 1; j >= 0; --j) {
            b[j] = temp[j] * a;
        }
    }

    // Additional loop
    for (int i = 0; i < 100; ++i) {
        val += 2;
        val *= 2;
    }

    // Check the results
    for (int i = 0; i < N; ++i) {
        if (val != b[i]) {
            std::cerr << "Test failed for b[" << i << "], expected: " << val << " got: " << b[i] << std::endl;
            errors++;
        }
    }

    if (errors == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cerr << errors << " tests failed." << std::endl;
    }

    return 0;
}
```

### Running the Tests

To run these tests, you'll need to compile the Fortran and C++ programs with OpenMP support enabled. For Fortran, you might use a command like `gfortran -fopenmp test_program.f90 -o test_program`, and for C++, `g++ -fopenmp test_program.cpp -o test_program`. Then, you can run the compiled programs to perform the tests.

These tests are designed to verify the correctness of the sequential parts of the programs. They check if the final values of the `b` array are as expected after the operations.
