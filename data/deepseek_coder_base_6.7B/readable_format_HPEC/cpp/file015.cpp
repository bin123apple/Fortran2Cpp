Certainly! Below is the translated version of the provided Fortran code to C++ using OpenMP for parallelism. Note that C++ uses different syntax and directives compared to Fortran, but the logic and parallel constructs remain similar.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int x = 2;

    #pragma omp task shared(x) mergeable
    {
        x = x + 1;
    }

    #pragma omp taskwait

    std::cout << "x = " << x << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library functions.
2. **Main Function**: The main function in C++ is equivalent to the `program` block in Fortran.
3. **Variable Declaration**: The variable `x` is declared and initialized as in the Fortran code.
4. **Parallel Task**: The `#pragma omp task` directive is used to create a task that shares the variable `x` with other tasks. The `mergeable` clause is used to allow the task to be merged with other tasks if possible. The task body increments `x`.
5. **Task Wait**: The `#pragma omp taskwait` directive is used to wait for all tasks to complete. This ensures that the value of `x` is correctly updated before it is printed.
6. **Printing**: The value of `x` is printed to the standard output using `std::cout`.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp your_program.cpp -o your_program
```

This command enables OpenMP (`-fopenmp`) and compiles the C++ code into an executable named `your_program`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

This Fortran code includes a simple test to verify the correctness of the original code.

```fortran
program test_DRB130_mergeable_taskwait_orig_no
    use omp_lib
    implicit none

    integer :: x
    integer :: expected_x
    logical :: test_passed

    x = 2
    expected_x = 3

    !$omp task shared(x) mergeable
    x = x + 1
    !$omp end task

    !$omp taskwait

    test_passed = (x == expected_x)

    if (test_passed) then
        print *, "Test Passed: x = ", x
    else
        print *, "Test Failed: x = ", x, ", expected: ", expected_x
    end if
end program test_DRB130_mergeable_taskwait_orig_no
```

### C++ Unit Test Code

This C++ code includes a simple test to verify the correctness of the translated code.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int x = 2;
    int expected_x = 3;
    bool test_passed = false;

    #pragma omp task shared(x) mergeable
    {
        x = x + 1;
    }

    #pragma omp taskwait

    test_passed = (x == expected_x);

    if (test_passed) {
        std::cout << "Test Passed: x = " << x << std::endl;
    } else {
        std::cout << "Test Failed: x = " << x << ", expected: " << expected_x << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
   - The variable `x` is initialized to 2.
   - The expected value of `x` after the operation is 3.
   - A task is created to increment `x`.
   - The taskwait directive is used to ensure the task completes.
   - The test checks if the final value of `x` matches the expected value and prints the result.

2. **C++ Unit Test**:
   - The variable `x` is initialized to 2.
   - The expected value of `x` after the operation is 3.
   - A task is created to increment `x`.
   - The taskwait directive is used to ensure the task completes.
   - The test checks if the final value of `x` matches the expected value and prints the result.

### Compilation and Execution:

- **Fortran**:
  - Compile the Fortran code with OpenMP support:
    ```sh
    gfortran -fopenmp test_DRB130_mergeable_taskwait_orig_no.f90 -o test_DRB130_mergeable_taskwait_orig_no
    ```
  - Run the executable:
    ```sh
    ./test_DRB130_mergeable_taskwait_orig_no
    ```

- **C++**:
  - Compile the C++ code with OpenMP support:
    ```sh
    g++ -fopenmp test_DRB130_mergeable_taskwait_orig_no.cpp -o test_DRB130_mergeable_taskwait_orig_no
    ```
  - Run the executable:
    ```sh
    ./test_DRB130_mergeable_taskwait_orig_no
    ```

Both tests should output that the test passed, indicating that the translation is correct.
