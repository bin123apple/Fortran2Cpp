Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 2000;
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    // Parallel section
    #pragma omp parallel for
    for (int i = 0; i < 1000; ++i) {
        a[2 * i] = a[i] + 1;
    }

    // Print the 1002nd element (1-based indexing in Fortran, 0-based indexing in C++)
    std::cout << "a(1002) = " << a[1001] << std::endl; // Note: C++ arrays are 0-based

    return 0;
}
```

### Explanation:
1. **Vector Initialization**:
   - In C++, we use `std::vector<int>` to create a dynamically sized array.
   - The size of the vector is set to `len`.
   - We initialize the vector using a loop, similar to the Fortran code.

2. **Parallel Section**:
   - The parallel section is created using `#pragma omp parallel for`.
   - The loop runs from `0` to `1000` because C++ uses 0-based indexing.
   - The operation inside the parallel loop is the same as in the Fortran code.

3. **Printing the Result**:
   - We print the 1002nd element of the array (1002 in 1-based indexing, 1001 in 0-based indexing).

4. **Compilation**:
   - To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:
     ```sh
     g++ -fopenmp -o DRB033_truedeplinear_orig_yes DRB033_truedeplinear_orig_yes.cpp
     ```

This code should give you the same output as the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB033_truedeplinear_orig_yes
    use omp_lib
    implicit none

    integer :: i, len
    integer, dimension(:), allocatable :: a
    integer :: expected_value

    len = 2000
    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    !$omp parallel do
    do i = 1, 1000
        a(2*i) = a(i) + 1
    end do
    !$omp end parallel do

    expected_value = 1002
    if (a(expected_value) == 1003) then
        print *, "Test passed: a(1002) = ", a(expected_value)
    else
        print *, "Test failed: a(1002) = ", a(expected_value)
    end if

    deallocate(a)
end program test_DRB033_truedeplinear_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 2000;
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    // Parallel section
    #pragma omp parallel for
    for (int i = 0; i < 1000; ++i) {
        a[2 * i] = a[i] + 1;
    }

    // Test
    int expected_value = 1001; // 1002 in 1-based indexing, 1001 in 0-based indexing
    if (a[expected_value] == 1003) {
        std::cout << "Test passed: a(1002) = " << a[expected_value] << std::endl;
    } else {
        std::cout << "Test failed: a(1002) = " << a[expected_value] << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
   - The program initializes the array `a`.
   - It performs the parallel operation as in the original code.
   - It checks if the value at index `1002` (1-based indexing) is `1003`, which is the expected outcome.
   - It prints the result of the test.

2. **C++ Unit Test Code**:
   - The program initializes the vector `a`.
   - It performs the parallel operation as in the translated code.
   - It checks if the value at index `1001` (0-based indexing) is `1003`, which is the expected outcome.
   - It prints the result of the test.

### Compilation and Execution:
1. **Fortran**:
   - Compile the Fortran code with OpenMP support:
     ```sh
     gfortran -fopenmp -o test_DRB033_truedeplinear_orig_yes test_DRB033_truedeplinear_orig_yes.f90
     ```
   - Run the executable:
     ```sh
     ./test_DRB033_truedeplinear_orig_yes
     ```

2. **C++**:
   - Compile the C++ code with OpenMP support:
     ```sh
     g++ -fopenmp -o test_DRB033_truedeplinear_orig_yes test_DRB033_truedeplinear_orig_yes.cpp
     ```
   - Run the executable:
     ```sh
     ./test_DRB033_truedeplinear_orig_yes
     ```

Both programs should output "Test passed: a(1002) = 1003" if the translation is correct.
