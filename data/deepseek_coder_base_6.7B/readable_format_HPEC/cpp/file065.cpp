Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len), c(len);

    // Initialize vectors b and c with some values (example initialization)
    for (int i = 0; i < len; ++i) {
        b[i] = i; // Example initialization
        c[i] = i + 1; // Example initialization
    }

    #pragma omp simd
    for (int i = 0; i < len; ++i) {
        a[i] = b[i] + c[i];
    }

    // Deallocate is not needed in C++ as vectors handle memory automatically

    return 0;
}
```

### Explanation:
1. **Vector Initialization**: In C++, we use `std::vector` to handle dynamic arrays. The size of the vectors is set to `len`.
2. **OpenMP Directives**: The `#pragma omp simd` directive is used to parallelize the loop similar to the `!$omp simd` directive in Fortran.
3. **Loop**: The loop runs from `0` to `len - 1` because C++ uses 0-based indexing.
4. **Deallocation**: In C++, vectors automatically deallocate memory when they go out of scope or are destroyed, so explicit deallocation is not needed.

### Notes:
- **Initialization**: The example initialization for vectors `b` and `c` is just for demonstration. You can initialize them with any values you want.
- **OpenMP**: Make sure your compiler supports OpenMP and that you enable OpenMP in your compiler settings. For GCC and Clang, you typically add the `-fopenmp` flag.

This C++ code should give you similar functionality to the original Fortran code, utilizing SIMD parallelism where applicable.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify that the translation is correct by comparing the output of both implementations.

### Fortran Unit Test Code

```fortran
program test_DRB070_simd1_orig_no
    use omp_lib
    implicit none

    integer :: len, i
    integer, dimension(:), allocatable :: a, b, c
    logical :: test_passed
    len = 100
    allocate (a(len))
    allocate (b(len))
    allocate (c(len))

    ! Initialize vectors b and c with some values
    do i = 1, len
        b(i) = i
        c(i) = i + 1
    end do

    !$omp simd
    do i = 1, len
        a(i) = b(i) + c(i)
    end do
    !$omp end simd

    ! Check the results
    test_passed = .true.
    do i = 1, len
        if (a(i) /= b(i) + c(i)) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif

    deallocate(a,b,c)
end program test_DRB070_simd1_orig_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len), c(len);
    bool test_passed = true;

    // Initialize vectors b and c with some values
    for (int i = 0; i < len; ++i) {
        b[i] = i + 1; // Adjusted for 1-based indexing to match Fortran initialization
        c[i] = i + 2; // Adjusted for 1-based indexing to match Fortran initialization
    }

    #pragma omp simd
    for (int i = 0; i < len; ++i) {
        a[i] = b[i] + c[i];
    }

    // Check the results
    for (int i = 0; i < len; ++i) {
        if (a[i] != b[i] + c[i]) {
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
1. **Fortran Unit Test**:
   - The program initializes vectors `b` and `c` with values that match the Fortran code's initialization.
   - It then performs the SIMD operation and checks if the result matches the expected output.
   - If all elements in `a` match the expected values, it prints "Test Passed"; otherwise, it prints "Test Failed".

2. **C++ Unit Test**:
   - The program initializes vectors `b` and `c` similarly to the Fortran test.
   - It performs the SIMD operation and checks if the result matches the expected output.
   - If all elements in `a` match the expected values, it prints "Test Passed"; otherwise, it prints "Test Failed".

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran test, use a Fortran compiler that supports OpenMP, such as gfortran:

```sh
gfortran -fopenmp test_DRB070_simd1_orig_no.f90 -o test_DRB070_simd1_orig_no
./test_DRB070_simd1_orig_no
```

#### C++:
To compile and run the C++ test, use a C++ compiler that supports OpenMP, such as g++:

```sh
g++ -fopenmp test_DRB070_simd1_orig_no.cpp -o test_DRB070_simd1_orig_no
./test_DRB070_simd1_orig_no
```

Both tests should output "Test Passed" if the translation is correct.
