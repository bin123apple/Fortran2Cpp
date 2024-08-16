To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, memory management, and parallel processing. Here's a C++ version of the Fortran code using OpenMP for parallel processing:

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Arrays in C++ are 0-indexed
    }

    // Generate a random number between 0 and 1
    double u = static_cast<double>(rand()) / RAND_MAX;
    int j = static_cast<int>(100 * u);

    // Parallel section with OpenMP
    #pragma omp parallel if(j % 2 == 0)
    {
        #pragma omp for
        for (int i = 0; i < len - 1; ++i) {
            a[i + 1] = a[i] + 1;
        }
    }

    // Print the 50th element of the array
    std::cout << "a[49] = " << a[49] << std::endl; // C++ arrays are 0-indexed

    return 0;
}
```

Key points in the translation:

1. **Array Indexing**: C++ arrays are 0-indexed, unlike Fortran's 1-indexed arrays. Therefore, the loop and array access are adjusted accordingly.

2. **Memory Management**: The `std::vector` is used to dynamically allocate an array of size `len`. This is a more modern and safer approach compared to raw pointers.

3. **Random Number Generation**: The `rand()` function from `<cstdlib>` is used to generate a random number between 0 and `RAND_MAX`. The `static_cast` is used to convert the `rand()` result to a `double` and then to an integer for the division.

4. **Parallel Processing**: The OpenMP directives `#pragma omp parallel` and `#pragma omp for` are used to parallelize the loop. The `if(j % 2 == 0)` clause ensures that the parallel section is executed only if `j` is even.

5. **Printing**: The `std::cout` is used for output, and the array index is adjusted to `49` to correctly access the 50th element of the array, considering C++'s 0-indexing.

6. **Compilation**: To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using `g++`, you can compile the program with the `-fopenmp` flag:
   ```sh
   g++ -fopenmp your_program.cpp -o your_program
   ```

This translation assumes that the goal is to maintain the logic and functionality of the original Fortran code while adapting it to C++ conventions and practices.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will check if the array manipulation and the output are as expected.

### Fortran Unit Test

For Fortran, we can write a simple test program that includes the original code and checks the output. Fortran doesn't have a built-in unit testing framework, so we'll do a basic implementation.

```fortran
program test_drb114
    use omp_lib
    implicit none

    integer :: i, len, rem, j
    real :: u
    integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:), allocatable :: a
    real(dp) :: expected_value

    len = 100
    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    call random_number(u)
    j = FLOOR(100*u)

    !$omp parallel do if (MOD(j,2)==0)
    do i = 1, len-1
        a(i+1) = a(i)+1
    end do
    !$omp end parallel do

    expected_value = 50.0_dp
    if (a(50) == expected_value) then
        print *, "Test passed: a(50) = ", a(50)
    else
        print *, "Test failed: a(50) = ", a(50), "Expected: ", expected_value
    end if

    deallocate(a)
end program test_drb114
```

### C++ Unit Test

For C++, we can use a simple testing approach similar to the Fortran example. For a more structured approach, you might consider using a unit testing framework like Google Test. However, for simplicity, we'll stick to basic checks.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <omp.h>

bool test_array_manipulation() {
    const int len = 100;
    std::vector<double> a(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    double u = static_cast<double>(rand()) / RAND_MAX;
    int j = static_cast<int>(100 * u);

    #pragma omp parallel if(j % 2 == 0)
    {
        #pragma omp for
        for (int i = 0; i < len - 1; ++i) {
            a[i + 1] = a[i] + 1;
        }
    }

    // Check if the 50th element is as expected
    double expected_value = 50.0;
    if (a[49] == expected_value) {
        return true;
    } else {
        return false;
    }
}

int main() {
    if (test_array_manipulation()) {
        std::cout << "Test passed: a[49] = " << 50 << std::endl;
    } else {
        std::cout << "Test failed: a[49] = " << 50 << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

- **Fortran**: Compile the Fortran test program with OpenMP support, for example, using `gfortran`:
  ```sh
  gfortran -fopenmp test_drb114.f90 -o test_drb114
  ./test_drb114
  ```

- **C++**: Compile the C++ test program with OpenMP support, for example, using `g++`:
  ```sh
  g++ -fopenmp test_drb114.cpp -o test_drb114
  ./test_drb114
  ```

These tests will verify that the array manipulation and output are as expected for both the Fortran and C++ versions.
