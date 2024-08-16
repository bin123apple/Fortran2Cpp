To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, memory management, and parallel processing. Fortran arrays are 1-based by default, while C++ arrays are 0-based. Also, Fortran's dynamic array allocation and deallocation mechanisms do not have a direct equivalent in C++, but we can use `std::vector` for dynamic arrays. OpenMP directives in Fortran can be used in C++ with minor syntax adjustments. Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 1000;
    std::vector<std::vector<float>> b(len, std::vector<float>(len));

    for (int i = 0; i < len; ++i) {
        #pragma omp parallel for
        for (int j = 1; j < len; ++j) {
            b[i][j] = b[i][j - 1];
        }
    }

    std::cout << "b(500,500) = " << b[500][500] << std::endl;

    return 0;
}
```

Key Points in the Translation:

1. **Array Indexing**: Adjusted to start from 0 in C++, as opposed to 1 in Fortran.
2. **Dynamic Arrays**: Used `std::vector` for dynamic arrays in C++, which simplifies memory management compared to raw pointers or Fortran's allocatable arrays.
3. **Parallel Processing**: Used `#pragma omp parallel for` to parallelize the inner loop, mirroring the OpenMP directives in Fortran.
4. **Output**: Used `std::cout` for output, formatting the output similarly to the Fortran `print` statement.
5. **Compilation**: Ensure you compile this C++ code with OpenMP support enabled. For example, if you're using `g++`, you would compile the code with the `-fopenmp` flag: `g++ -fopenmp your_program.cpp -o your_program`.

This translation assumes that the goal is to maintain the logic and functionality of the original Fortran code while adapting it to C++ conventions and practices.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will check if the values in the array `b` are correctly updated according to the specified logic. For simplicity, we'll focus on testing the specific functionality that modifies the array `b`.

### Fortran Unit Test

For the Fortran code, we can add a test subroutine that checks the value of `b(500,500)` after the main computation. Fortran lacks a built-in unit testing framework, so we'll do a simple manual check.

```fortran
program DRB037_truedepseconddimension_orig_yes
    use omp_lib
    implicit none

    integer :: i, j, n, m, len
    real, dimension(:,:), allocatable :: b

    len = 1000
    n = len
    m = len

    allocate (b(len,len))

    ! Initialize the array
    do i = 1, n
        do j = 1, m
            b(i,j) = 0.0
        end do
    end do

    ! Main computation
    do i = 1, n
        !$omp parallel do
        do j = 2, m
            b(i,j) = b(i,j-1) + 1.0
        end do
        !$omp end parallel do
    end do

    ! Test
    if (b(500,500) == 999.0) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if

    deallocate(b)
end program
```

This test initializes the array `b` with zeros, then modifies it according to the logic, and finally checks if the value at `b(500,500)` is as expected (999.0).

### C++ Unit Test

For the C++ code, we can use a simple assertion to test the value of `b[500][500]` after the main computation. C++ does not include a built-in unit testing framework, but for simplicity, we'll use `assert` from the `<cassert>` header.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cassert>

int main() {
    const int len = 1000;
    std::vector<std::vector<float>> b(len, std::vector<float>(len, 0.0f));

    for (int i = 0; i < len; ++i) {
        #pragma omp parallel for
        for (int j = 1; j < len; ++j) {
            b[i][j] = b[i][j - 1] + 1.0f;
        }
    }

    // Test
    assert(b[500][500] == 999.0f);

    std::cout << "Test passed." << std::endl;

    return 0;
}
```

This test initializes the array `b` with zeros, then modifies it according to the logic, and finally uses `assert` to check if the value at `b[500][500]` is as expected (999.0).

### Running the Tests

- **Fortran**: Compile the Fortran program with OpenMP support and run the executable. The program itself will print whether the test passed or failed.
  
  Example: `gfortran -fopenmp your_fortran_program.f90 -o fortran_test && ./fortran_test`

- **C++**: Compile the C++ program with OpenMP support and run the executable. If the assertion passes, it will print "Test passed." Otherwise, the program will terminate with an assertion failure.

  Example: `g++ -fopenmp your_cpp_program.cpp -o cpp_test && ./cpp_test`

These tests are basic and focus on verifying the specific functionality of the array modification logic. For more comprehensive testing, especially in larger and more complex programs, consider using dedicated unit testing frameworks like `GoogleTest` for C++ or `fruit` for Fortran.
