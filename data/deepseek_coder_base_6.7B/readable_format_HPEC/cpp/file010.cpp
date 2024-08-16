Certainly! Below is the translated Fortran code to C++. Note that OpenMP directives in C++ are slightly different from Fortran, and the syntax for array indexing starts from 0 in C++. Also, OpenMP is typically used with C or C++ code, so the code is adapted accordingly.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var[100];

    // Initialize array
    for(int i = 0; i < 100; ++i) {
        var[i] = 1;
    }

    // OpenMP directives for GPU offloading
    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for
        for(int i = 1; i < 100; ++i) {
            var[i] = var[i-1] + 1;
        }
    }

    // Print the result
    std::cout << var[99] << std::endl;

    return 0;
}
```

Key Points:
- The `#pragma omp target` directive is used to specify that the following block of code should be offloaded to a target device, in this case, the GPU. The `device(0)` clause specifies that the GPU with index 0 should be used.
- The `#pragma omp teams distribute parallel for` directive is used to parallelize the loop across teams of threads, similar to the `!$omp teams distribute parallel do` in Fortran.
- Array indexing in C++ starts from 0, so the loop runs from 1 to 99 to match the original Fortran code's 2 to 100.
- The `std::cout` is used for printing, similar to the `print*,` statement in Fortran.
- Remember to enable OpenMP in your compiler settings if you're using one that supports it, such as by using the `-fopenmp` flag in GCC or Clang.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the original Fortran code and the translated C++ code. These tests will verify that the final value of the array `var` is as expected after the computation.

### Fortran Unit Test

For the Fortran code, we'll create a simple test program that checks the value of `var(100)` after the computation. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic check.

```fortran
program test_DRB156_missingordered_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var(100)
    integer :: i
    integer :: expected_value

    expected_value = 100

    do i = 1, 100
        var(i) = 1
    end do

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
    do i = 2, 100
        var(i) = var(i-1)+1
    end do
    !$omp end teams distribute parallel do
    !$omp end target

    if (var(100) == expected_value) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if
end program test_DRB156_missingordered_orig_gpu_yes
```

### C++ Unit Test

For the C++ code, we can use a simple assertion to verify the correctness. C++ doesn't have a built-in unit testing framework, but for a simple case like this, we don't necessarily need one. We'll use `assert` from the C++ standard library.

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    int var[100];
    int expected_value = 100;

    // Initialize array
    for(int i = 0; i < 100; ++i) {
        var[i] = 1;
    }

    // OpenMP directives for GPU offloading
    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for
        for(int i = 1; i < 100; ++i) {
            var[i] = var[i-1] + 1;
        }
    }

    // Assert the result
    assert(var[99] == expected_value);

    std::cout << "Test Passed" << std::endl;

    return 0;
}
```

### Running the Tests

- **For Fortran**: Compile the Fortran test program with an OpenMP-supporting Fortran compiler (e.g., `gfortran`) and run the executable. Ensure OpenMP is enabled.
  
  Example:
  ```sh
  gfortran -fopenmp test_DRB156_missingordered_orig_gpu_yes.f90 -o test_DRB156
  ./test_DRB156
  ```

- **For C++**: Compile the C++ test program with an OpenMP-supporting C++ compiler (e.g., `g++`) and run the executable. Ensure OpenMP is enabled.

  Example:
  ```sh
  g++ -fopenmp test_DRB156_missingordered_orig_gpu_yes.cpp -o test_DRB156
  ./test_DRB156
  ```

These tests should pass, indicating that the final value of `var(100)` is as expected after the computation in both the Fortran and C++ versions.
