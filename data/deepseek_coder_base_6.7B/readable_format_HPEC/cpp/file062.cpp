To translate the given Fortran code to C++, we need to understand the structure and the purpose of the original Fortran code and then implement similar functionality using C++ syntax and OpenMP directives. The Fortran code demonstrates the use of OpenMP for task dependency and mutex-like behavior, where tasks are dependent on each other and on shared variables.

Here's a C++ version of the Fortran code using OpenMP for parallelism and task dependencies:

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

            #pragma omp task depend(in: a)
            c = c + a;  // Task T4

            #pragma omp task depend(in: b)
            c = c + b;  // Task T5

            #pragma omp task depend(in: c)
            d = c;      // Task T6
        }
    }

    std::cout << d << std::endl;

    return 0;
}
```

### Key Points of Translation:

1. **Program Structure**: The `program` block in Fortran is translated to the `main` function in C++.

2. **Module and Use Statement**: The `use omp_lib` statement in Fortran is translated to including the OpenMP header `<omp.h>` in C++.

3. **Implicit None**: Fortran's `implicit none` is not needed in C++ as variable types must be explicitly declared.

4. **Variable Declarations**: Variables are declared at the beginning of the C++ program. The types are explicitly specified (e.g., `int a, b, c, d;`).

5. **Parallel and Single Regions**: The `!$omp parallel` and `!$omp single` directives in Fortran are translated to `#pragma omp parallel` and `#pragma omp single` in C++.

6. **Tasks**: The `!$omp task` directives are translated to `#pragma omp task` in C++. The `depend` clause is directly translated to the `depend` clause in C++.

7. **Assignments**: The assignments are directly translated from Fortran to C++ with the same syntax.

8. **Print Statement**: The `print *, d` statement in Fortran is translated to `std::cout << d << std::endl;` in C++.

9. **End Directives**: The `!$omp end task` and `!$omp end parallel` directives in Fortran are translated to `#pragma omp end task` and `#pragma omp end parallel` in C++.

This C++ code should compile with an OpenMP-capable compiler (e.g., `g++` or `clang++`) and execute with the appropriate flags to enable OpenMP. For example, with `g++`, you would compile the program with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```

This will enable OpenMP in your C++ program.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ versions of the code involves checking the correctness of the output against expected values. For simplicity, we'll use a basic approach to unit testing by comparing the output of each program with an expected value.

### Fortran Unit Test

For the Fortran code, we can modify the program to write the output to a file and then compare the file content with the expected output.

1. **Modified Fortran Program (`DRB135_taskdep_mutexinoutset_orig_no_omp50_test.f90`)**:

```fortran
program DRB135_taskdep_mutexinoutset_orig_no_omp50_test
    use omp_lib
    implicit none

    integer :: a, b, c, d
    open(unit=10, file='output.txt', status='replace')

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
        !$omp task depend(in: a)
        c = c + a  ! Task T4
        !$omp end task
        !$omp task depend(in: b)
        c = c + b  ! Task T5
        !$omp end task
        !$omp task depend(in: c)
        d = c      ! Task T6
        !$omp end task
    !$omp end single
    !$omp end parallel

    write(10, *) d
    close(10)
end program
```

2. **Test Script (`test_fortran.sh`)**:

```sh
#!/bin/bash

# Compile the Fortran program
gfortran -fopenmp DRB135_taskdep_mutexinoutset_orig_no_omp50_test.f90 -o DRB135_taskdep_mutexinoutset_orig_no_omp50_test

# Run the program
./DRB135_taskdep_mutexinoutset_orig_no_omp50_test

# Check the output
if grep -q '6' output.txt; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
fi
```

### C++ Unit Test

For the C++ code, we can modify the program to write the output to a file and then compare the file content with the expected output.

1. **Modified C++ Program (`DRB135_taskdep_mutexinoutset_orig_no_omp50_test.cpp`)**:

```cpp
#include <iostream>
#include <fstream>
#include <omp.h>

int main() {
    int a, b, c, d;
    std::ofstream out("output.txt");

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

            #pragma omp task depend(in: a)
            c = c + a;  // Task T4

            #pragma omp task depend(in: b)
            c = c + b;  // Task T5

            #pragma omp task depend(in: c)
            d = c;      // Task T6
        }
    }

    out << d << std::endl;
    out.close();

    return 0;
}
```

2. **Test Script (`test_cpp.sh`)**:

```sh
#!/bin/bash

# Compile the C++ program
g++ -fopenmp DRB135_taskdep_mutexinoutset_orig_no_omp50_test.cpp -o DRB135_taskdep_mutexinoutset_orig_no_omp50_test

# Run the program
./DRB135_taskdep_mutexinoutset_orig_no_omp50_test

# Check the output
if grep -q '6' output.txt; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
fi
```

### Running the Tests

1. **Fortran Test**:

Save the Fortran program in a file named `DRB135_taskdep_mutexinoutset_orig_no_omp50_test.f90` and the test script in a file named `test_fortran.sh`.
