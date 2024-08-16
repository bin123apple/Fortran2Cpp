To translate the given Fortran code to C++, we need to understand the structure and the functionality of the original code. The Fortran code uses OpenMP directives for parallelism, specifically `target`, `teams distribute parallel do`, and `critical` sections. The `target` directive is used to specify that the parallel loop should be offloaded to a target device, in this case, GPU. The `teams distribute parallel do` directive is used to parallelize the loop across multiple teams of threads. The `critical` directive ensures that only one thread at a time can enter the critical section, which is used to update the shared variable `var`.

Here's how you can translate the given Fortran code to C++ using OpenMP:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute parallel for
    for (int i = 1; i <= 200; ++i) {
        #pragma omp critical
        {
            var = var + 1;
        }
    }

    std::cout << var << std::endl;

    return 0;
}
```

Key points in the translation:

1. **Include OpenMP**: The C++ code includes the OpenMP header `<omp.h>`.
2. **Main Function**: The `main` function serves as the entry point for the C++ program.
3. **Variable Declaration**: The variable `var` is declared and initialized similarly in C++.
4. **OpenMP Directives**:
   - `#pragma omp target`: Specifies that the following parallel loop should be offloaded to a target device.
   - `#pragma omp teams distribute parallel for`: Parallelizes the loop across multiple teams of threads.
   - `#pragma omp critical`: Ensures that only one thread at a time can enter the critical section.
5. **Loop**: The loop is translated to a `for` loop in C++. Note that the loop index `i` starts from 1 and goes to 200, inclusive, similar to the Fortran code.
6. **Output**: The final value of `var` is printed to the standard output using `std::cout`.

Make sure to compile the C++ code with an OpenMP-supporting compiler, such as `g++`, and enable OpenMP support using the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the final value of the variable `var` after the parallel execution. Since the parallel execution might result in different values due to the non-deterministic nature of parallel execution, we'll focus on testing the correctness of the final value rather than the exact execution order.

### Fortran Unit Test

For the Fortran code, we can modify the program to include a check for the expected final value of `var`. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a simple check and print a success message if the test passes.

```fortran
program DRB144_atomiccritical_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var, i, expected_var
    var = 0
    expected_var = 200

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
        do i = 1, 200
            !$omp critical
            var = var+1
            !$omp end critical
        end do
    !$omp end teams distribute parallel do
    !$omp end target

    if (var == expected_var) then
        print*, "Test Passed: var = ", var
    else
        print*, "Test Failed: var = ", var
    end if
end program
```

### C++ Unit Test

For the C++ code, we can use a simple assertion to check the final value of `var`. C++ has several unit testing frameworks available, but for simplicity, we'll use a basic approach without an external framework.

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    int var = 0;
    int expected_var = 200;

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute parallel for
    for (int i = 1; i <= 200; ++i) {
        #pragma omp critical
        {
            var = var + 1;
        }
    }

    assert(var == expected_var);
    std::cout << "Test Passed: var = " << var << std::endl;

    return 0;
}
```

### Compiling and Running the Tests

- **Fortran**: Use a Fortran compiler that supports OpenMP, such as `gfortran`. Compile and run the Fortran code as follows:

```sh
gfortran -fopenmp your_fortran_program.f90 -o fortran_test
./fortran_test
```

- **C++**: Use a C++ compiler that supports OpenMP, such as `g++`. Compile and run the C++ code as follows:

```sh
g++ -fopenmp your_cpp_program.cpp -o cpp_test
./cpp_test
```

These tests will verify that the final value of `var` is as expected, ensuring that the parallel execution behaves as intended. If the tests pass, you will see a message indicating that the test passed and the value of `var`.
