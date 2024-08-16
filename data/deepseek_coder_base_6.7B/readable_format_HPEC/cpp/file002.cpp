Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
        b[i] = i + 2;
    }

    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    for (int i = 0; i < len; ++i) {
        std::cout << "Values for i and a(i) are: " << i + 1 << " " << a[i] << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <vector>` for dynamic array (vector) support.
   - `#include <omp.h>` for OpenMP support.

2. **Define main function**:
   - The `main` function is the entry point of the C++ program.

3. **Initialize variables**:
   - Define the length `len` of the arrays.
   - Initialize vectors `a` and `b` with size `len`.

4. **Populate arrays**:
   - Use a loop to populate arrays `a` and `b`.

5. **SIMD Directive**:
   - Use the `#pragma omp simd` directive to parallelize the loop.

6. **Computation**:
   - Use another loop to perform the computation `a[i+1] = a[i] + b[i]`.

7. **Output results**:
   - Use another loop to print the values of `i` and `a[i]`.

8. **Return**:
   - Return `0` at the end of the `main` function to indicate successful execution.

### Compilation:
To compile this C++ code with OpenMP support, you can use the following command:

```sh
g++ -fopenmp -o DRB024_simdtruedep_orig_yes DRB024_simdtruedep_orig_yes.cpp
```

This command tells the compiler to enable OpenMP support (`-fopenmp`) and outputs an executable named `DRB024_simdtruedep_orig_yes`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

Here is the Fortran unit test code:

```fortran
program test_DRB024_simdtruedep_orig_yes
    use omp_lib
    implicit none

    integer :: i, len
    integer, dimension(:), allocatable :: a
    integer, dimension(:), allocatable :: b
    logical :: test_passed

    len = 100
    allocate (a(len))
    allocate (b(len))

    do i = 1, len
        a(i) = i
        b(i) = i+1
    end do

    !$omp simd
    do i = 1, len-1
        a(i+1) = a(i) + b(i)
    end do

    test_passed = .true.
    do i = 1, len
        if (a(i) /= i * 2) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif

    deallocate(a,b)
end program test_DRB024_simdtruedep_orig_yes
```

### C++ Unit Test Code

Here is the C++ unit test code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cassert>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
        b[i] = i + 2;
    }

    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    bool test_passed = true;
    for (int i = 0; i < len; ++i) {
        if (a[i] != (i + 1) * 2) {
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

### Explanation:

#### Fortran Unit Test Code:
1. **Initialization**:
   - Define the length `len` of the arrays.
   - Allocate and initialize arrays `a` and `b`.

2. **Computation**:
   - Perform the computation `a(i+1) = a(i) + b(i)`.

3. **Test**:
   - Use a loop to check if each element of `a` is equal to `i * 2`.
   - If all elements are correct, print "Test Passed"; otherwise, print "Test Failed".

4. **Deallocation**:
   - Deallocate arrays `a` and `b`.

#### C++ Unit Test Code:
1. **Initialization**:
   - Define the length `len` of the arrays.
   - Initialize vectors `a` and `b` with size `len`.

2. **Computation**:
   - Perform the computation `a[i+1] = a[i] + b[i]`.

3. **Test**:
   - Use a loop to check if each element of `a` is equal to `(i + 1) * 2`.
   - If all elements are correct, print "Test Passed"; otherwise, print "Test Failed".

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran unit test code, use the following commands:

```sh
gfortran -fopenmp -o test_DRB024_simdtruedep_orig_yes test_DRB024_simdtruedep_orig_yes.f90
./test_DRB024_simdtruedep_orig_yes
```

#### C++:
To compile and run the C++ unit test code, use the following commands:

```sh
g++ -fopenmp -o test_DRB024_simdtruedep_orig_yes test_DRB024_simdtruedep_orig_yes.cpp
./test_DRB024_simdtruedep_orig_yes
```

Both programs should output "Test Passed" if the translation is correct.
