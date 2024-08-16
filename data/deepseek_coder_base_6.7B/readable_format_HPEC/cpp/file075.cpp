Certainly! Below is the translated Fortran code to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int var = 0;

    #pragma omp parallel shared(var)
    {
        #pragma omp single
        {
            var = var + 1;
        }
        #pragma omp barrier

        #pragma omp single
        {
            var = var + 1;
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The main function in C++ is equivalent to the `program` block in Fortran.
3. **Variable Declaration**: The variable `var` is declared as an integer.
4. **Parallel Region**: The `#pragma omp parallel shared(var)` directive is used to start a parallel region with `var` as a shared variable.
5. **Single Directive**: The `#pragma omp single` directive ensures that only one thread executes the enclosed code.
6. **Variable Increment**: The variable `var` is incremented within the single regions.
7. **Barrier**: The `#pragma omp barrier` directive synchronizes all threads in the parallel region.
8. **Output**: The value of `var` is printed to the standard output using `std::cout`.

This C++ code should exhibit the same behavior as the original Fortran code, with the addition of OpenMP directives for parallelism.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program test_drb120_barrier_orig_no
    use omp_lib
    implicit none

    integer :: var
    integer :: num_threads
    integer :: i
    integer, parameter :: num_tests = 100
    logical :: test_passed

    var = 0
    num_threads = 0
    test_passed = .true.

    !$omp parallel shared(var, num_threads)
    !$omp single
    num_threads = omp_get_num_threads()
    !$omp end single
    !$omp barrier

    !$omp parallel shared(var, num_threads)
    !$omp single
    var = var + 1
    !$omp end single
    !$omp barrier

    !$omp parallel shared(var, num_threads)
    !$omp single
    var = var + 1
    !$omp end single
    !$omp barrier

    !$omp parallel shared(var, num_threads)
    !$omp single
    if (var /= 2) then
        test_passed = .false.
    end if
    !$omp end single
    !$omp barrier

    !$omp parallel shared(var, num_threads)
    !$omp single
    if (num_threads /= omp_get_num_threads()) then
        test_passed = .false.
    end if
    !$omp end single
    !$omp barrier

    !$omp parallel shared(var, num_threads)
    !$omp single
    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    end if
    !$omp end single
    !$omp end parallel

end program test_drb120_barrier_orig_no
```

### C++ Unit Test Code

```cpp
#include <omp.h>
#include <iostream>
#include <vector>

int main() {
    int var = 0;
    int num_threads = 0;
    bool test_passed = true;

    #pragma omp parallel shared(var, num_threads)
    {
        #pragma omp single
        {
            num_threads = omp_get_num_threads();
        }
        #pragma omp barrier

        #pragma omp single
        {
            var = var + 1;
        }
        #pragma omp barrier

        #pragma omp single
        {
            var = var + 1;
        }
        #pragma omp barrier

        #pragma omp single
        {
            if (var != 2) {
                test_passed = false;
            }
            if (num_threads != omp_get_num_threads()) {
                test_passed = false;
            }
            if (test_passed) {
                std::cout << "Test Passed" << std::endl;
            } else {
                std::cout << "Test Failed" << std::endl;
            }
        }
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The program initializes `var` to 0 and `num_threads` to 0.
   - It checks the number of threads before and after the increment to ensure that the parallel region behaves as expected.
   - It prints "Test Passed" if the test succeeds, otherwise "Test Failed".

2. **C++ Unit Test Code**:
   - The program similarly initializes `var` to 0 and `num_threads` to 0.
   - It checks the number of threads before and after the increment to ensure that the parallel region behaves as expected.
   - It prints "Test Passed" if the test succeeds, otherwise "Test Failed".

### Running the Tests:

1. **Fortran**:
   - Compile the Fortran code with OpenMP support: `gfortran -fopenmp test_drb120_barrier_orig_no.f90 -o test_drb120_barrier_orig_no`
   - Run the executable: `./test_drb120_barrier_orig_no`

2. **C++**:
   - Compile the C++ code with OpenMP support: `g++ -fopenmp test_drb120_barrier_orig_no.cpp -o test_drb120_barrier_orig_no`
   - Run the executable: `./test_drb120_barrier_orig_no`

Both unit tests should print "Test Passed" if the translation is correct.
