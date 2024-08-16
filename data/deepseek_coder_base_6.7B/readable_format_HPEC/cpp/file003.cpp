To translate the provided Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the OpenMP directives, and the structure of the program. Here's a C++ version of the Fortran code:

```cpp
#include <iostream>
#include <omp.h>

// Function declaration
void foo();

int main() {
    // OpenMP parallel region
    #pragma omp parallel
    {
        // OpenMP single directive
        #pragma omp single
        {
            foo(); // Call the subroutine
        }
    }
    return 0;
}

// Subroutine definition
void foo() {
    int x, y;
    x = 0;
    y = 2;

    // OpenMP task with depend clause
    #pragma omp task depend(inout: x) shared(x)
    {
        x = x + 1; // 1st Child Task
    }

    // OpenMP task with depend clause
    #pragma omp task depend(in: x) depend(inout: y) shared(x, y)
    {
        y = y - x; // 2nd child task
    }

    // OpenMP task with depend clause and if condition
    #pragma omp task depend(in: x) if(.FALSE.)
    {
        // Empty task body as per the Fortran code
    }

    // Printing values of x and y
    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    // OpenMP taskwait
    #pragma omp taskwait
}
```

### Key Points:

1. **OpenMP Directives**: The OpenMP directives in C++ are similar to those in Fortran, but the syntax is slightly different. For example, `!$omp parallel` in Fortran translates to `#pragma omp parallel` in C++.

2. **Subroutine to Function**: Fortran's `subroutine` is translated to a C++ `void` function.

3. **Variable Declarations**: Variable declarations are straightforwardly translated from Fortran to C++.

4. **Printing**: The `print*,` statement in Fortran is replaced with `std::cout` in C++.

5. **Implicit None**: In Fortran, `implicit none` is used to avoid implicit type declarations. In C++, this is the default behavior, so there's no direct equivalent needed.

6. **OpenMP Task Dependency**: The `!$omp task depend` directive in Fortran is translated to `#pragma omp task depend` in C++. Note that the `shared` clause is also handled similarly in both languages.

7. **Taskwait**: `!$omp taskwait` in Fortran is translated to `#pragma omp taskwait` in C++.

8. **Program Structure**: The structure of the program (main function and subroutine) is preserved as is, with the main function acting as the entry point for the parallel region.

This translation assumes that the OpenMP environment is correctly set up in the C++ compiler, similar to how it is done in Fortran with the `use omp_lib` statement.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ versions of the code involves checking the correctness of the `foo` subroutine/function under various conditions. However, the original Fortran code does not include any explicit conditions or scenarios that would affect the values of `x` and `y`, making it challenging to create meaningful unit tests without introducing additional logic. Therefore, I will provide a basic framework for both languages that you can expand upon based on specific test cases or scenarios you wish to verify.

### Fortran Unit Test

For Fortran, we can create a simple test program that calls `foo` and checks the results manually since Fortran lacks a built-in unit testing framework similar to what's available in other languages.

```fortran
program test_foo
    use omp_lib
    implicit none
    call foo()
end program test_foo

subroutine foo()
    implicit none
    integer :: x, y
    x = 0
    y = 2

    !$omp task depend(inout: x) shared(x)
    x = x + 1
    !$omp end task

    !$omp task depend(in: x) depend(inout: y) shared(x, y)
    y = y - x
    !$omp end task

    !$omp task depend(in: x) if(.FALSE.)
    !$omp end task

    print*, "x=", x
    print*, "y=", y

    !$omp taskwait
end subroutine foo
```

### C++ Unit Test

For C++, we can use a testing framework like Google Test for more structured and automated testing. However, for simplicity, I'll provide a basic example without an external framework.

```cpp
#include <iostream>
#include <omp.h>

void foo();

int main() {
    foo(); // Call the function to test
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

    #pragma omp task depend(in: x) depend(inout: y) shared(x, y)
    {
        y = y - x; // 2nd child task
    }

    #pragma omp task depend(in: x) if(.FALSE.)
    {
        // Empty task body as per the Fortran code
    }

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    #pragma omp taskwait
}
```

### Testing Approach

For both examples, you would run the program and manually verify that the output matches your expectations based on the OpenMP task dependencies and the logic within `foo`. Since the original Fortran code does not specify any conditions or scenarios, the tests are limited to the output of `foo` without any input parameters.

To create more comprehensive tests, you would need to add parameters to `foo` or `foo`'s caller (`main` in the C++ case, `test_foo` in the Fortran case) and check for different scenarios, such as different initial values of `x` and `y`, different task dependency conditions (e.g., `.TRUE.` and `.FALSE.`), and so on.

Remember, the effectiveness of these tests depends on the specific conditions and outcomes you're looking for, which were not fully specified in the original code snippets.
