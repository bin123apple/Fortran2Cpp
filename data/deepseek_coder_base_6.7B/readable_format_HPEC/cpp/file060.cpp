Certainly! Below is the translated Fortran code to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for reduction(+:var)
        for (int i = 1; i <= 200; ++i) {
            if (var < 101) {
                var = var + 1;
            }
        }
    }

    std::cout << "var: " << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Variable Declaration**: The variable `var` is declared as an integer and initialized to 0.
3. **Target Directive**: The `#pragma omp target` directive is used to specify that the following code should be offloaded to the device with ID 0.
4. **Teams Distribute Parallel for**: The `#pragma omp teams distribute parallel for` directive is used to parallelize the loop across teams of threads.
5. **Loop**: The loop runs from 1 to 200, inclusive.
6. **Conditional Statement**: If `var` is less than 101, `var` is incremented by 1.
7. **Output**: The final value of `var` is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o DRB145_atomiccritical_orig_gpu_no DRB145_atomiccritical_orig_gpu_no.cpp
```

This command enables OpenMP and compiles the C++ code into an executable named `DRB145_atomiccritical_orig_gpu_no`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB145_atomiccritical_orig_gpu_no
    use omp_lib
    implicit none

    integer :: var, expected_var
    var = 0
    expected_var = 101

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do reduction(+:var)
        do i = 1, 200
            if (var<101) then
                var = var+1
            end if
        end do
    !$omp end teams distribute parallel do
    !$omp end target

    if (var == expected_var) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if

end program test_DRB145_atomiccritical_orig_gpu_no
```

### C++ Unit Test Code

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int var = 0;
    int expected_var = 101;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for reduction(+:var)
        for (int i = 1; i <= 200; ++i) {
            if (var < 101) {
                var = var + 1;
            }
        }
    }

    if (var == expected_var) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
   - The variable `var` is initialized to 0.
   - The expected value of `var` after the loop is 101.
   - The loop increments `var` by 1 for each iteration if `var` is less than 101.
   - After the loop, it checks if `var` equals the expected value and prints "Test passed." if true, otherwise "Test failed.".

2. **C++ Unit Test Code**:
   - The variable `var` is initialized to 0.
   - The expected value of `var` after the loop is 101.
   - The loop increments `var` by 1 for each iteration if `var` is less than 101.
   - After the loop, it checks if `var` equals the expected value and prints "Test passed." if true, otherwise "Test failed.".

### Compilation and Execution:
1. **Fortran**:
   - Compile the Fortran code with OpenMP support:
     ```sh
     gfortran -fopenmp -o test_DRB145_atomiccritical_orig_gpu_no test_DRB145_atomiccritical_orig_gpu_no.f90
     ```
   - Execute the compiled program:
     ```sh
     ./test_DRB145_atomiccritical_orig_gpu_no
     ```

2. **C++**:
   - Compile the C++ code with OpenMP support:
     ```sh
     g++ -fopenmp -o test_DRB145_atomiccritical_orig_gpu_no test_DRB145_atomiccritical_orig_gpu_no.cpp
     ```
   - Execute the compiled program:
     ```sh
     ./test_DRB145_atomiccritical_orig_gpu_no
     ```

Both programs should output "Test passed." if the translation is correct.
