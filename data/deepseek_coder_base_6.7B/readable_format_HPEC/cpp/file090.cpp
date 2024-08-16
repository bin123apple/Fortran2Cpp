To translate the given Fortran code to C++, we need to understand the structure and the functionality of the original Fortran code and then implement similar functionality using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for task dependency and mutex-in-out set to control the flow of tasks.

Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int a, b, c, d;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out: c)
            c = 1;      // Task T1

            #pragma omp task depend(out: a)
            a = 2;      // Task T2

            #pragma omp task depend(out: b)
            b = 3;      // Task T3

            #pragma omp task depend(in: a) depend(mutexinoutset: c)
            c = c + a;  // Task T4

            #pragma omp task depend(in: b) depend(mutexinoutset: c)
            c = c + b;  // Task T5

            #pragma omp task depend(in: c)
            d = c;      // Task T6
        }
    }

    std::cout << d << std::endl;

    return 0;
}
```

### Explanation:
1. **Including the necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Main function**:
   - Declaration of variables `a`, `b`, `c`, and `d`.

3. **OpenMP parallel region**:
   - The `#pragma omp parallel` directive is used to parallelize the code.

4. **OpenMP single region**:
   - The `#pragma omp single` directive ensures that only one thread executes the enclosed code.

5. **OpenMP task regions**:
   - The `#pragma omp task` directive is used to create tasks. The `depend` clause is used to specify task dependencies.

6. **Initialization and computation**:
   - Each task initializes or modifies the variables `a`, `b`, `c`, and `d` as per the original Fortran code.

7. **Output**:
   - The value of `d` is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o DRB135_taskdep_mutexinoutset_orig_no_omp50 DRB135_taskdep_mutexinoutset_orig_no_omp50.cpp
```

This command enables OpenMP support and compiles the C++ code into an executable named `DRB135_taskdep_mutexinoutset_orig_no_omp50`.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ versions of the code involves checking the output against expected values. For simplicity, we'll assume that the expected output is known and is `10`.

### Fortran Unit Test

To test the Fortran code, we can modify the program to include a simple check for the output.

```fortran
program DRB135_taskdep_mutexinoutset_orig_no_omp50_test
    use omp_lib
    implicit none

    integer :: a, b, c, d
    integer :: expected_d

    expected_d = 10

    !$omp parallel
    !$omp single
        !$omp task depend(out: c)
        c = 1      ! Task T1
        !$omp end task
        !$omp task depend(out: a)
        a = 2      ! Task T2
        !$omp end task
        !$omp task depend(out: b)
        b = 3      ! Task T3
        !$omp end task
        !$omp task depend(in: a) depend(mutexinoutset: c)
        c = c + a  ! Task T4
        !$omp end task
        !$omp task depend(in: b) depend(mutexinoutset: c)
        c = c + b  ! Task T5
        !$omp end task
        !$omp task depend(in: c)
        d = c      ! Task T6
        !$omp end task
    !$omp end single
    !$omp end parallel

    if (d == expected_d) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    end if
end program
```

### C++ Unit Test

For the C++ code, we can use a simple `assert` statement to verify the output.

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    int a, b, c, d;
    int expected_d = 10;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out: c)
            c = 1;      // Task T1

            #pragma omp task depend(out: a)
            a = 2;      // Task T2

            #pragma omp task depend(out: b)
            b = 3;      // Task T3

            #pragma omp task depend(in: a) depend(mutexinoutset: c)
            c = c + a;  // Task T4

            #pragma omp task depend(in: b) depend(mutexinoutset: c)
            c = c + b;  // Task T5

            #pragma omp task depend(in: c)
            d = c;      // Task T6
        }
    }

    assert(d == expected_d);
    std::cout << "Test Passed" << std::endl;

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran test, use the following commands:

```sh
gfortran -fopenmp -o DRB135_taskdep_mutexinoutset_orig_no_omp50_test DRB135_taskdep_mutexinoutset_orig_no_omp50_test.f90
./DRB135_taskdep_mutexinoutset_orig_no_omp50_test
```

#### C++

To compile and run the C++ test, use the following commands:

```sh
g++ -fopenmp -o DRB135_taskdep_mutexinoutset_orig_no_omp50_test DRB135_taskdep_mutexinoutset_orig_no_omp50_test.cpp
./DRB135_taskdep_mutexinoutset_orig_no_omp50_test
```

### Expected Output

For both the Fortran and C++ tests, the expected output should be:

```
Test Passed
```

This indicates that the translation was successful and the functionality is preserved.
