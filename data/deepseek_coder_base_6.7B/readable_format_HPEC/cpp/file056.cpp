Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int a = 0;

    #pragma omp parallel shared(a)
    {
        #pragma omp master
        {
            a = 0;
        }

        #pragma omp barrier

        #pragma omp for reduction(+:a)
        for(int i = 1; i <= 10; ++i) {
            a += i;
        }

        #pragma omp single
        {
            std::cout << "Sum is " << a << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Main function**:
   - Declare and initialize the variable `a` to 0.

3. **Parallel region**:
   - Use `#pragma omp parallel shared(a)` to start a parallel region with `a` as a shared variable.

4. **Master region**:
   - Use `#pragma omp master` to ensure only the master thread initializes `a`.

5. **Barrier**:
   - Use `#pragma omp barrier` to synchronize all threads.

6. **Reduction on `a`**:
   - Use `#pragma omp for reduction(+:a)` to perform a reduction on `a` within the loop.

7. **Loop to sum**:
   - Use a `for` loop to sum values from 1 to 10, inclusive.

8. **Single region**:
   - Use `#pragma omp single` to ensure only one thread prints the result.

9. **Output the result**:
   - Use `std::cout` to print the sum.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o DRB141_reduction_barrier_orig_no DRB141_reduction_barrier_orig_no.cpp
```

This command tells the compiler to enable OpenMP support (`-fopenmp`) and outputs an executable named `DRB141_reduction_barrier_orig_no`.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of both programs.

### Fortran Unit Test

Save the following Fortran code in a file named `test_DRB141_reduction_barrier_orig_no.f90`:

```fortran
program test_DRB141_reduction_barrier_orig_no
    use omp_lib
    implicit none

    integer :: a, expected_sum
    integer :: i

    a = 0
    expected_sum = 0
    do i = 1, 10
        expected_sum = expected_sum + i
    end do

    !$omp parallel shared(a) private(i)
        !$omp master
        a = 0
        !$omp end master

        !$omp barrier

        !$omp do reduction(+:a)
        do i = 1, 10
            a = a + i
        end do
        !$omp end do

        !$omp single
        if (a == expected_sum) then
            print*, "Test Passed: Sum is ", a
        else
            print*, "Test Failed: Sum is ", a
        end if
        !$omp end single
    !$omp end parallel
end program test_DRB141_reduction_barrier_orig_no
```

### C++ Unit Test

Save the following C++ code in a file named `test_DRB141_reduction_barrier_orig_no.cpp`:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int a = 0;
    int expected_sum = 0;

    for(int i = 1; i <= 10; ++i) {
        expected_sum += i;
    }

    #pragma omp parallel shared(a)
    {
        #pragma omp master
        {
            a = 0;
        }

        #pragma omp barrier

        #pragma omp for reduction(+:a)
        for(int i = 1; i <= 10; ++i) {
            a += i;
        }

        #pragma omp single
        {
            if (a == expected_sum) {
                std::cout << "Test Passed: Sum is " << a << std::endl;
            } else {
                std::cout << "Test Failed: Sum is " << a << std::endl;
            }
        }
    }

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran unit test, use the following commands:

```sh
gfortran -fopenmp test_DRB141_reduction_barrier_orig_no.f90 -o test_DRB141_reduction_barrier_orig_no
./test_DRB141_reduction_barrier_orig_no
```

#### C++

To compile and run the C++ unit test, use the following commands:

```sh
g++ -fopenmp test_DRB141_reduction_barrier_orig_no.cpp -o test_DRB141_reduction_barrier_orig_no
./test_DRB141_reduction_barrier_orig_no
```

### Expected Output

Both programs should output:

```
Test Passed: Sum is 55
```

This indicates that the translation is correct.
