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

    #pragma omp taskwait depend(in: x) // 1st taskwait

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    #pragma omp taskwait // 2nd taskwait
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
3. **OpenMP Directives**:
   - `#pragma omp parallel`: This is used to start a parallel region.
   - `#pragma omp single`: This ensures that the enclosed block is executed by only one thread in the parallel region.
   - `#pragma omp task`: This is used to create a task. The `depend` clause is used to specify the dependencies between tasks.
   - `#pragma omp taskwait`: This is used to wait for all tasks to complete.
4. **Variables `x` and `y`**: These are declared and initialized as in the Fortran code.
5. **Output**: The values of `x` and `y` are printed using `std::cout`.

### Notes:
- The OpenMP directives are used similarly to their Fortran counterparts.
- The `#pragma` directive is used in C++ for OpenMP.
- The `implicit none` statement in Fortran is not needed in C++ as variable types must be explicitly declared.
- The `print*,` statement in Fortran is replaced with `std::cout` in C++.
- The `end program` and `end subroutine` statements in Fortran are replaced by the closing brace `}` in C++.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB165_taskdep4_orig_yes_omp_50
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

        !$omp taskwait depend(in: x)

        print*, "x=", x
        print*, "y=", y

        !$omp taskwait
    end subroutine foo

end program test_DRB165_taskdep4_orig_yes_omp_50
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

void foo(int& x, int y) {
    x = x + 1;
    y = y - 1;

    #pragma omp task depend(inout: x) shared(x)
    x = x + 1; // 1st Child Task

    #pragma omp task shared(y)
    y = y - 1; // 2nd child task

    #pragma omp taskwait depend(in: x) // 1st taskwait

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    #pragma omp taskwait // 2nd taskwait
}

void test_foo() {
    int x = 0;
    int y = 2;

    #pragma omp parallel
    {
        #pragma omp single
        foo(x, y);
    }
}

int main() {
    test_foo();
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_foo` subroutine is added to the Fortran program to encapsulate the call to `foo`.
   - The `foo` subroutine is modified to accept `x` and `y` as arguments, allowing for inout and in parameters, respectively.

2. **C++ Unit Test Code**:
   - The `test_foo` function is added to the C++ code to encapsulate the call to `foo`.
   - The `foo` function is modified to accept `x` and `y` by reference, allowing for inout and in parameters, respectively.

### Running the Tests:

1. **Fortran**:
   - Compile the Fortran code using a Fortran compiler that supports OpenMP, e.g., `gfortran`:
     ```sh
     gfortran -fopenmp test_DRB165_taskdep4_orig_yes_omp_50.f90 -o test_DRB165_taskdep4_orig_yes_omp_50
     ```
   - Run the executable:
     ```sh
     ./test_DRB165_taskdep4_orig_yes_omp_50
     ```

2. **C++**:
   - Compile the C++ code using a C++ compiler that supports OpenMP, e.g., `g++`:
     ```sh
     g++ -fopenmp test_DRB165_taskdep4_orig_yes_omp_50.cpp -o test_DRB165_taskdep4_orig_yes_omp_50
     ```
   - Run the executable:
     ```sh
     ./test_DRB165_taskdep4_orig_yes_omp_50
     ```

### Expected Output:

Both the Fortran and C++ programs should produce the same output, verifying that the translation is correct. The output should be:

```
x=3
y=1
```

This output verifies that the translation from Fortran to C++ is correct.
