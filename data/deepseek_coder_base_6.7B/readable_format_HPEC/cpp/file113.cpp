To translate the given Fortran code to C++, we need to consider the differences in syntax and conventions between Fortran and C++. The Fortran code uses OpenMP directives for parallelism, which have a different syntax in C++. Here's a C++ version of the code, using OpenMP for parallelism:

```cpp
#include <iostream>
#include <omp.h>

// Function prototype
void foo();

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            foo();
        }
    }
    return 0;
}

void foo() {
    int x = 0;
    int y = 2;

    #pragma omp task depend(inout: x) shared(x)
    {
        x = x + 1; // 1st Child Task
    }

    #pragma omp task shared(y)
    {
        y = y - x; // 2nd child task
    }

    #pragma omp taskwait depend(in: x) // 1st taskwait

    std::cout << "x=" << x << std::endl;

    #pragma omp taskwait // 2nd taskwait

    std::cout << "y=" << y << std::endl;
}
```

### Key Points:

1. **OpenMP Directives**: The OpenMP directives used in Fortran (`!$omp`) are replaced with `#pragma omp` in C++.
2. **Function Declaration**: The subroutine `foo` is declared as `void foo();` before the `main` function.
3. **Variable Declarations**: Variables `x` and `y` are declared at the beginning of the `foo` function.
4. **Task Dependencies**: The `depend` clause for tasks in Fortran is translated to `depend` in C++. Note that the `inout` and `in` clauses in Fortran have similar semantics in C++, but the syntax is slightly different.
5. **Output**: The `print*,` statement in Fortran is replaced with `std::cout` in C++.
6. **Parallel and Single Blocks**: The `!$omp parallel` and `!$omp single` directives are translated to `#pragma omp parallel` and `#pragma omp single` respectively.

Make sure to compile this C++ code with an OpenMP-capable compiler, such as `g++`, and enable OpenMP support using the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ versions of the code involves checking the correctness of the parallel execution and the final values of `x` and `y`. For simplicity, we'll focus on testing the functionality that involves parallel execution and task dependencies.

### Fortran Unit Test

For Fortran, we'll use a simple approach to test the functionality, as Fortran doesn't have a built-in unit testing framework similar to what's available in C++. We'll modify the original program to include checks after the parallel execution.

```fortran
program DRB167_taskdep5_orig_no_omp50
    use omp_lib
    implicit none

    !$omp parallel
    !$omp single
    call foo()
    !$omp end single
    !$omp end parallel

contains
    subroutine foo()
        implicit none
        integer :: x, y
        x = 0
        y = 2

        !$omp task depend(inout: x) shared(x)
        x = x+1                                 !!1st Child Task
        !$omp end task

        !$omp task shared(y)
        y = y-x                                 !!2nd child task
        !$omp end task

        !$omp taskwait depend(in: x)            !!1st taskwait

        ! Check the values of x and y after the first taskwait
        if (x == 1 .and. y == 2) then
            print*, "Test 1 Passed"
        else
            print*, "Test 1 Failed"
        end if

        !$omp taskwait                          !!2nd taskwait

        ! Check the values of x and y after the second taskwait
        if (x == 1 .and. y == 1) then
            print*, "Test 2 Passed"
        else
            print*, "Test 2 Failed"
        end if

    end subroutine
end program
```

### C++ Unit Test

For C++, we can use a more structured approach with a unit testing framework like Google Test. However, for simplicity, we'll follow a similar approach to the Fortran test, checking the values of `x` and `y` after each taskwait.

```cpp
#include <iostream>
#include <omp.h>

void foo();

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            foo();
        }
    }
    return 0;
}

void foo() {
    int x = 0;
    int y = 2;

    #pragma omp task depend(inout: x) shared(x)
    {
        x = x + 1; // 1st Child Task
    }

    #pragma omp task shared(y)
    {
        y = y - x; // 2nd child task
    }

    #pragma omp taskwait depend(in: x) // 1st taskwait

    // Check the values of x and y after the first taskwait
    if (x == 1 && y == 2) {
        std::cout << "Test 1 Passed" << std::endl;
    } else {
        std::cout << "Test 1 Failed" << std::endl;
    }

    #pragma omp taskwait // 2nd taskwait

    // Check the values of x and y after the second taskwait
    if (x == 1 && y == 1) {
        std::cout << "Test 2 Passed" << std::endl;
    } else {
        std::cout << "Test 2 Failed" << std::endl;
    }
}
```

### Compilation and Execution

- **Fortran**: Use a Fortran compiler that supports OpenMP, such as `gfortran`, and compile the Fortran program with the `-fopenmp` flag:
  ```sh
  gfortran -fopenmp your_fortran_program.f90 -o fortran_test
  ./fortran_test
  ```
- **C++**: Use a C++ compiler that supports OpenMP, such as `g++`, and compile the C++ program with the `-fopenmp` flag:
  ```sh
  g++ -fopenmp your_cpp_program.cpp -o cpp_test
  ./cpp_test
  ```

These tests will output whether each test has passed or failed, allowing you to verify the correctness of the parallel execution and the final values of `x` and `y` in both the Fortran and C++ versions.
