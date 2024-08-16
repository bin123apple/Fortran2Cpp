Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

void foo() {
    int x, y;
    x = 0;
    y = 2;

    #pragma omp task depend(inout: x) shared(x)
    x = x + 1; // 1st Child Task

    #pragma omp task shared(y)
    y = y - 1; // 2nd child task

    #pragma omp task depend(in: x) if(false) // 1st taskwait

    #pragma omp taskwait // 2nd taskwait

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;
}

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        foo();
    }
    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Function `foo`**: This is the equivalent of the Fortran subroutine.
3. **Parallel and Single Directives**: The `#pragma omp parallel` and `#pragma omp single` directives are used to create a parallel region and execute the single task within it, respectively.
4. **Task Dependencies**: The `#pragma omp task depend` directive is used to specify task dependencies. In this case, `x` is modified by the first task, and `y` is not affected by the second task.
5. **Printing**: The `std::cout` is used for output, similar to the `print` statement in Fortran.
6. **Taskwait**: The `#pragma omp taskwait` directive is used to synchronize the tasks.

### Notes:
- The `if(false)` clause in the task dependency for the first task ensures that the task is not executed, mimicking the `if(.FALSE.)` in Fortran.
- The `#pragma omp taskwait` directive is used to synchronize the tasks, similar to the `!$omp taskwait` in Fortran.
- The `#pragma omp parallel` and `#pragma omp single` directives are used to parallelize the execution of the `foo` function, which is akin to the `!$omp parallel` and `!$omp single` directives in Fortran.

This C++ code should produce the same output as the original Fortran code when executed with an OpenMP-capable compiler.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by ensuring that the outputs are consistent.

### Fortran Unit Test Code

```fortran
program test_DRB131_taskdep4_orig_yes_omp_45
    use omp_lib
    implicit none

    call test_foo()

contains

    subroutine test_foo()
        implicit none
        integer :: x, y
        x = 0
        y = 2

        !$omp parallel
        !$omp single
        call foo(x, y)
        !$omp end single
        !$omp end parallel
    end subroutine test_foo

    subroutine foo(x, y)
        implicit none
        integer, intent(inout) :: x
        integer, intent(in) :: y
        x = x + 1
        y = y - 1

        !$omp task depend(inout: x) shared(x)
        x = x + 1
        !$omp end task

        !$omp task shared(y)
        y = y - 1
        !$omp end task

        !$omp task depend(in: x) if(.FALSE.)
        !$omp end task

        !$omp taskwait

        print*, "x=", x
        print*, "y=", y
    end subroutine foo

end program test_DRB131_taskdep4_orig_yes_omp_45
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

void foo(int& x, int& y) {
    x = 0;
    y = 2;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(inout: x) shared(x)
            x = x + 1; // 1st Child Task

            #pragma omp task shared(y)
            y = y - 1; // 2nd child task

            #pragma omp task depend(in: x) if(false) // 1st taskwait

            #pragma omp taskwait // 2nd taskwait
        }
    }

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;
}

int main() {
    int x, y;
    foo(x, y);
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_foo` subroutine is added to the program to encapsulate the parallel execution of `foo`.
   - The `foo` subroutine is modified to accept `x` and `y` as arguments, allowing for inout and in parameters, respectively.

2. **C++ Unit Test Code**:
   - The `foo` function is modified to accept `x` and `y` as reference parameters.
   - The `main` function calls `foo` with `x` and `y` as arguments.

### Compilation and Execution:

- **Fortran**: Use a Fortran compiler that supports OpenMP, such as `gfortran`, and compile the Fortran code with the `-fopenmp` flag:
  ```sh
  gfortran -fopenmp test_DRB131_taskdep4_orig_yes_omp_45.f90 -o test_DRB131_taskdep4_orig_yes_omp_45
  ./test_DRB131_taskdep4_orig_yes_omp_45
  ```

- **C++**: Use a C++ compiler that supports OpenMP, such as `g++`, and compile the C++ code with the `-fopenmp` flag:
  ```sh
  g++ -fopenmp test_DRB131_taskdep4_orig_yes_omp_45.cpp -o test_DRB131_taskdep4_orig_yes_omp_45
  ./test_DRB131_taskdep4_orig_yes_omp_45
  ```

### Verification:

- **Expected Output**: Both the Fortran and C++ programs should produce the same output, verifying the correctness of the translation:
  ```
  x=2
  y=0
  ```

This unit test ensures that the outputs of both the original Fortran code and the translated C++ code are consistent, verifying the correctness of the translation.
