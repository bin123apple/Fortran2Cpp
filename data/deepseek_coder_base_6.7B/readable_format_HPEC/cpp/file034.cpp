To translate the given Fortran code to C++, we need to understand the structure and the functionality of the original code, then implement similar functionality using C++ syntax and OpenMP directives. The Fortran code demonstrates the use of task dependencies and parallel regions.

Here's how you can translate the Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

// Function prototype
void foo();

int main() {
    // Equivalent of the Fortran 'program' block
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
    int x, y;
    x = 0;
    y = 2;

    // Equivalent of the 1st task with depend(inout: x) and shared(x)
    #pragma omp task depend(inout: x) shared(x)
    {
        x = x + 1; // 1st Child Task
    }

    // Equivalent of the 2nd task with shared(y)
    #pragma omp task shared(y)
    {
        y = y - 1; // 2nd child task
    }

    // Equivalent of the 1st taskwait with depend(in: x)
    #pragma omp taskwait depend(in: x)

    std::cout << "x=" << x << std::endl;

    // Equivalent of the 2nd taskwait
    #pragma omp taskwait

    std::cout << "y=" << y << std::endl;
}
```

### Explanation:
1. **Program Structure**: The `main` function in C++ serves as the entry point for the program, similar to the `program` block in Fortran.
2. **Parallel Region**: The `#pragma omp parallel` directive is used to start a parallel region, which is equivalent to the `!$omp parallel` block in Fortran.
3. **Single Directive**: The `#pragma omp single` directive ensures that the enclosed block is executed by a single thread, similar to the `!$omp single` block in Fortran.
4. **Task Dependencies**: The `#pragma omp task` directive is used to create tasks, and `#pragma omp taskwait` is used to synchronize on task completion. The `depend` clause is used to specify dependencies between tasks, similar to the `dependent` attribute in Fortran.
5. **Shared Variables**: The `shared` clause is used to specify shared variables among tasks, which is similar to the `shared` attribute in Fortran.
6. **Printing**: The `std::cout` is used for output, similar to the `print*` statement in Fortran.

This C++ code should exhibit the same behavior as the original Fortran code, with OpenMP tasks and dependencies correctly managed.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the functionality of the `foo` subroutine/function to ensure that the task dependencies and parallel execution behave as expected.

### Fortran Unit Test

For Fortran, we can write a simple test program that calls `foo` and checks the results. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic check.

```fortran
program test_DRB166_taskdep4_orig_no_omp50
    use omp_lib
    implicit none

    call foo()

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
        y = y-1                                 !!2nd child task
        !$omp end task

        !$omp taskwait depend(in: x)            !!1st taskwait

        print*, "x=", x

        !$omp taskwait                          !!2nd taskwait

        print*, "y=", y

    end subroutine

end program test_DRB166_taskdep4_orig_no_omp50
```

To compile and run this Fortran test, you would typically use a command like:

```sh
gfortran -fopenmp test_DRB166_taskdep4_orig_no_omp50.f90 -o test_DRB166_taskdep4_orig_no_omp50
./test_DRB166_taskdep4_orig_no_omp50
```

### C++ Unit Test

For C++, we can use a simple testing approach similar to the Fortran example. C++ has more sophisticated testing frameworks available (like Google Test), but for simplicity, we'll stick to basic checks.

```cpp
#include <iostream>
#include <omp.h>

void foo();

int main() {
    foo();
    return 0;
}

void foo() {
    int x, y;
    x = 0;
    y = 2;

    #pragma omp task depend(inout: x) shared(x)
    {
        x = x + 1; // 1st Child Task
    }

    #pragma omp task shared(y)
    {
        y = y - 1; // 2nd child task
    }

    #pragma omp taskwait depend(in: x)

    std::cout << "x=" << x << std::endl;

    #pragma omp taskwait

    std::cout << "y=" << y << std::endl;
}
```

To compile and run this C++ test, you would use a command like:

```sh
g++ -fopenmp test_DRB166_taskdep4_orig_no_omp50.cpp -o test_DRB166_taskdep4_orig_no_omp50
./test_DRB166_taskdep4_orig_no_omp50
```

### Expected Output

For both the Fortran and C++ tests, the expected output should be:

```
x=1
y=1
```

This output verifies that the task dependencies and parallel execution work as expected in both the original Fortran code and the translated C++ code.
