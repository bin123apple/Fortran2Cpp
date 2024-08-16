To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code and then implement it using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for parallel processing and includes a critical section to ensure mutual exclusion.

Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int sum = 0;
    int sum0 = 0;
    int sum1 = 0;

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 1; i <= 1001; ++i) {
            sum0 += i;
        }

        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (int i = 1; i <= 1001; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The `main` function is the entry point of the C++ program.
3. **Variable Declarations**: Variables `sum`, `sum0`, and `sum1` are declared at the beginning of the `main` function.
4. **Parallel Region**: The `#pragma omp parallel` directive is used to start a parallel region. Inside this region, two sections are created:
   - The first section (`#pragma omp for`) uses OpenMP's `for` directive to parallelize the loop.
   - The second section (`#pragma omp critical`) ensures mutual exclusion by preventing multiple threads from accessing the critical section at the same time.
5. **Loop and Sum**: The loop inside the parallel region sums up the values from 1 to 1001, storing the result in `sum0`. The critical section adds `sum0` to `sum`.
6. **Outside Parallel Region**: After the parallel region, a loop is used to sum up the values from 1 to 1001, storing the result in `sum1`.
7. **Output**: The results are printed to the standard output using `std::cout`.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you're using `g++` and your compiler supports OpenMP):

```sh
g++ -fopenmp your_program.cpp -o your_program
```

This command enables OpenMP support by using the `-fopenmp` flag.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking if the outputs are consistent and correct. For simplicity, we'll focus on testing the functionality that calculates the sum of numbers from 1 to 1001.

### Fortran Unit Test

For Fortran, we can create a simple test program that includes the original code and checks if the output is as expected.

```fortran
program test_DRB092_threadprivatemissing2_orig_yes
    use omp_lib
    implicit none

    integer :: i, sum, expected_sum
    sum = 0
    expected_sum = 0

    ! Calculate expected sum
    do i = 1, 1001
        expected_sum = expected_sum + i
    end do

    !$omp parallel
        !$omp do
        do i = 1, 1001
            sum = sum + i
        end do
        !$omp end do
    !$omp end parallel

    if (sum == expected_sum) then
        print *, "Test Passed: sum =", sum
    else
        print *, "Test Failed: sum =", sum, "expected_sum =", expected_sum
    end if

end program test_DRB092_threadprivatemissing2_orig_yes
```

### C++ Unit Test

For C++, we can use a simple test function that includes the translated code and checks if the output is as expected.

```cpp
#include <iostream>
#include <omp.h>

bool test_sum() {
    int sum = 0;
    int expected_sum = 0;

    // Calculate expected sum
    for (int i = 1; i <= 1001; ++i) {
        expected_sum += i;
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 1; i <= 1001; ++i) {
            #pragma omp atomic
            sum += i;
        }
    }

    return sum == expected_sum;
}

int main() {
    if (test_sum()) {
        std::cout << "Test Passed: sum = " << sum << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Test Program**:
   - The `test_DRB092_threadprivatemissing2_orig_yes` program calculates the sum of numbers from 1 to 1001 using OpenMP parallelization.
   - It compares the calculated sum with the expected sum (calculated in a serial manner) and prints the result.

2. **C++ Test Function**:
   - The `test_sum` function calculates the sum of numbers from 1 to 1001 using OpenMP parallelization.
   - It compares the calculated sum with the expected sum (calculated in a serial manner) and returns the result.
   - The `main` function calls `test_sum` and prints the result.

### Compilation and Execution:

- **Fortran**:
  ```sh
  gfortran -fopenmp test_DRB092_threadprivatemissing2_orig_yes.f90 -o test_DRB092_threadprivatemissing2_orig_yes
  ./test_DRB092_threadprivatemissing2_orig_yes
  ```

- **C++**:
  ```sh
  g++ -fopenmp test_sum.cpp -o test_sum
  ./test_sum
  ```

These tests will verify that the translation from Fortran to C++ is correct by ensuring that the sum calculations produce the same results.
