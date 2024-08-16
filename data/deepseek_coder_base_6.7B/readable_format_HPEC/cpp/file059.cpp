To translate the provided Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, memory management, and OpenMP directives. Here's a C++ version of the code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len * len + len), c(len, 0);

    // Initialize arrays
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            b[j + i * len] = 1;
        }
        a[i] = 1;
    }

    // OpenMP target directive equivalent in C++
    #pragma omp target map(to:a[0:len]) map(tofrom:c[0:len]) device(0)
    {
        // OpenMP teams distribute parallel do equivalent in C++
        #pragma omp teams distribute parallel for
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                c[i] += a[j] * b[j + i * len];
            }
        }
    }

    // Print results
    for (int i = 0; i < len; ++i) {
        if (c[i] != len) {
            std::cout << c[i] << std::endl;
        }
    }

    return 0;
}
```

Key points in the translation:

1. **Array Initialization**: In C++, `std::vector` is used for dynamic arrays, which simplifies memory management compared to raw pointers.

2. **OpenMP Directives**: The OpenMP directives in C++ are similar to those in Fortran, but the syntax is slightly different. The `#pragma omp` directive is used in C++ for OpenMP directives.

3. **Array Indexing**: C++ uses 0-based indexing for arrays, unlike Fortran's 1-based indexing. This is adjusted in the loop conditions and array accesses.

4. **Memory Management**: The `std::vector` handles memory deallocation automatically when it goes out of scope, so explicit deallocation is not needed.

5. **Printing**: The `std::cout` is used for output, similar to the `print*` statement in Fortran.

6. **Program Structure**: The `main` function serves as the entry point for C++ programs, equivalent to the Fortran program block.

Remember to compile this C++ code with OpenMP support enabled. For example, using `g++`:

```sh
g++ -fopenmp your_program.cpp -o your_program
```

This command enables OpenMP support in the compiler.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of both implementations.

### Fortran Unit Test Code

Save the following Fortran code in a file named `test_drb149_missingdata1_orig_gpu_no.f90`:

```fortran
program test_DRB149_missingdata1_orig_gpu_no
    use omp_lib
    implicit none

    integer :: len, i, j
    integer, dimension(:), allocatable :: a, b, c
    integer, dimension(:), allocatable :: expected_c
    logical :: test_passed

    len = 100
    allocate (a(len))
    allocate (b(len+len*len))
    allocate (c(len))
    allocate (expected_c(len))

    ! Initialize arrays
    do i = 1, len
        do j = 1, len
            b(j+i*len)=1
        end do
        a(i) = 1
        c(i) = 0
        expected_c(i) = 0
    end do

    ! OpenMP target directive equivalent in Fortran
    !$omp target map(to:a,b) map(tofrom:c) device(0)
    !$omp teams distribute parallel do
    do i = 1, len
        do j = 1, len
            c(i) = c(i)+a(j)*b(j+i*len)
        end do
    end do
    !$omp end teams distribute parallel do
    !$omp end target

    ! Verify results
    test_passed = .true.
    do i = 1, len
        if (c(i) /= len) then
            test_passed = .false.
            exit
        end if
    end do

    if (test_passed) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if

    deallocate(a,b,c,expected_c)
end program test_DRB149_missingdata1_orig_gpu_no
```

### C++ Unit Test Code

Save the following C++ code in a file named `test_drb149_missingdata1_orig_gpu_no.cpp`:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cassert>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len * len + len), c(len, 0);
    std::vector<int> expected_c(len, 0);
    bool test_passed = true;

    // Initialize arrays
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            b[j + i * len] = 1;
        }
        a[i] = 1;
    }

    // OpenMP target directive equivalent in C++
    #pragma omp target map(to:a[0:len]) map(tofrom:c[0:len]) device(0)
    {
        // OpenMP teams distribute parallel do equivalent in C++
        #pragma omp teams distribute parallel for
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                c[i] += a[j] * b[j + i * len];
            }
        }
    }

    // Verify results
    for (int i = 0; i < len; ++i) {
        if (c[i] != len) {
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

### Compilation and Execution

To compile and run the Fortran unit test, use the following commands:

```sh
gfortran -fopenmp test_drb149_missingdata1_orig_gpu_no.f90 -o test_drb149_missingdata1_orig_gpu_no
./test_drb149_missingdata1_orig_gpu_no
```

To compile and run the C++ unit test, use the following commands:

```sh
g++ -fopenmp test_drb149_missingdata1_orig_gpu_no.cpp -o test_drb149_missingdata1_orig_gpu_no
./test_drb149_missingdata1_orig_gpu_no
```

Both tests should output "Test Passed" if the translation is correct. If there are any discrepancies, the tests will output "Test Failed".
