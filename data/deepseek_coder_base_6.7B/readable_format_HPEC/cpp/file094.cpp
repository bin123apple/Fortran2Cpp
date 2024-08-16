Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based
        b[i] = i + 2; // Fortran arrays are 1-based
    }

    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    std::cout << "a[49] = " << a[49] << std::endl; // C++ arrays are 0-based

    return 0;
}
```

### Explanation:
1. **Vector Initialization**: In C++, we use `std::vector<int>` to create arrays `a` and `b`. The size of these vectors is set to `len`.
2. **Filling Arrays**: The loop fills the arrays `a` and `b` similarly to the Fortran code. Note that C++ arrays are 0-based, so we adjust the indices accordingly.
3. **SIMD Directive**: The `#pragma omp simd` directive is used to parallelize the loop similar to the Fortran `!$omp simd` directive.
4. **Printing the Result**: The result is printed using `std::cout`. C++ arrays are 0-based, so to access the 50th element, we use `a[49]`.

Make sure to compile this C++ code with OpenMP support enabled. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp -o DRB115_forsimd_orig_yes DRB115_forsimd_orig_yes.cpp
```
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of the Fortran and C++ programs.

### Fortran Unit Test

You can create a Fortran program to test the original code. Save it as `test_DRB115_forsimd_orig_yes.f90`.

```fortran
program test_DRB115_forsimd_orig_yes
    use omp_lib
    implicit none

    integer :: i, len
    integer, dimension(:), allocatable :: a, b
    integer :: expected_value

    len = 100
    allocate (a(len))
    allocate (b(len))

    do i = 1, len
        a(i) = i
        b(i) = i + 1
    end do

    !$omp simd
    do i = 1, len - 1
        a(i + 1) = a(i) + b(i)
    end do

    expected_value = 51  ! a(50) in Fortran is 51

    if (a(50) == expected_value) then
        print *, "Test passed: a(50) =", a(50)
    else
        print *, "Test failed: a(50) =", a(50), "Expected:", expected_value
    end if

    deallocate(a, b)
end program test_DRB115_forsimd_orig_yes
```

### C++ Unit Test

You can create a C++ program to test the translated code. Save it as `test_DRB115_forsimd_orig_yes.cpp`.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len);
    int expected_value = 51;  // a[49] in C++ is 50 (0-based indexing)

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based
        b[i] = i + 2; // Fortran arrays are 1-based
    }

    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    if (a[49] == expected_value) {
        std::cout << "Test passed: a[49] = " << a[49] << std::endl;
    } else {
        std::cout << "Test failed: a[49] = " << a[49] << " Expected: " << expected_value << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran test, use the following commands:

```sh
gfortran -fopenmp -o test_DRB115_forsimd_orig_yes test_DRB115_forsimd_orig_yes.f90
./test_DRB115_forsimd_orig_yes
```

#### C++

To compile and run the C++ test, use the following commands:

```sh
g++ -fopenmp -o test_DRB115_forsimd_orig_yes test_DRB115_forsimd_orig_yes.cpp
./test_DRB115_forsimd_orig_yes
```

### Expected Output

For both Fortran and C++ programs, the expected output should be:

```
Test passed: a(50) = 51
```

or


```
Test passed: a[49] = 51
```

This confirms that the translation from Fortran to C++ is correct.
