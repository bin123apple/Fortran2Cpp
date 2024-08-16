Certainly! Below is the equivalent C++ code for the provided Fortran code. Note that OpenMP directives in C++ are slightly different from Fortran, and the syntax for tasks and sections is also slightly different.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp parallel sections
    {
        for (int i = 1; i <= 10; ++i) {
            #pragma omp task shared(var) if(false)
            {
                var = var + 1;
            }
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Main Function**: The main function starts with initializing the variable `var` to 0.
3. **Parallel Sections**: The `#pragma omp parallel sections` directive is used to start a parallel section.
4. **Loop and Tasks**: A loop runs from 1 to 10. Inside the loop, a task is created with `#pragma omp task shared(var) if(false)`. The `if(false)` clause ensures that the task is not executed immediately but is deferred. Inside the task, `var` is incremented.
5. **Output**: The final value of `var` is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp -o DRB122_taskundeferred_orig_no DRB122_taskundeferred_orig_no.cpp
```

This command compiles the C++ code and generates an executable named `DRB122_taskundeferred_orig_no`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by ensuring that the variable `var` is incremented 10 times.

### Fortran Unit Test Code

```fortran
program test_DRB122_taskundeferred_orig_no
    use omp_lib
    implicit none

    integer :: var, i, expected_var
    var = 0
    expected_var = 10

    !$omp parallel sections
    do i = 1, 10
        !$omp task shared(var) if(.FALSE.)
        var = var+1
        !$omp end task
    end do
    !$omp end parallel sections

    if (var == expected_var) then
        print *, "Test passed: var = ", var
    else
        print *, "Test failed: var = ", var
    end if
end program test_DRB122_taskundeferred_orig_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int expected_var = 10;

    #pragma omp parallel sections
    {
        for (int i = 1; i <= 10; ++i) {
            #pragma omp task shared(var) if(false)
            {
                var = var + 1;
            }
        }
    }

    if (var == expected_var) {
        std::cout << "Test passed: var = " << var << std::endl;
    } else {
        std::cout << "Test failed: var = " << var << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
    - The `var` variable is initialized to 0.
    - The expected value of `var` after the loop is 10.
    - The parallel sections are used to execute the tasks.
    - Inside the loop, a task is created with `#pragma omp task shared(var) if(false)`.
    - After the loop, the value of `var` is checked against the expected value.
    - If `var` matches the expected value, the test passes; otherwise, it fails.

2. **C++ Unit Test Code**:
    - The `var` variable is initialized to 0.
    - The expected value of `var` after the loop is 10.
    - The parallel sections are used to execute the tasks.
    - Inside the loop, a task is created with `#pragma omp task shared(var) if(false)`.
    - After the loop, the value of `var` is checked against the expected value.
    - If `var` matches the expected value, the test passes; otherwise, it fails.

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran unit test code, use the following commands:

```sh
gfortran -fopenmp -o test_DRB122_taskundeferred_orig_no test_DRB122_taskundeferred_orig_no.f90
./test_DRB122_taskundeferred_orig_no
```

#### C++:
To compile and run the C++ unit test code, use the following commands:

```sh
g++ -fopenmp -o test_DRB122_taskundeferred_orig_no test_DRB122_taskundeferred_orig_no.cpp
./test_DRB122_taskundeferred_orig_no
```

These commands compile the respective codes with OpenMP support and then run the compiled executable. The output will indicate whether the test passed or failed.
