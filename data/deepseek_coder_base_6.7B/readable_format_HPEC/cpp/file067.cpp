To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code and then implement similar behavior using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for parallelism and locking to increment a variable across multiple threads. Here's how you can translate it to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    omp_lock_t lck;
    int var = 0;

    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute reduction(+:var)
    for (int i = 1; i <= 100; ++i) {
        omp_set_lock(&lck);
        var = var + 1;
        omp_unset_lock(&lck);
    }

    omp_destroy_lock(&lck);

    std::cout << var << std::endl;

    return 0;
}
```

### Key Points of Translation:

1. **Include OpenMP Header**: In C++, you include the OpenMP API by including the `omp.h` header.

2. **Variable Declarations**: The variable types and declarations are translated directly, with `int` for integer variables.

3. **Lock Initialization and Destruction**: `omp_init_lock` and `omp_destroy_lock` are used in a similar manner as in Fortran.

4. **Parallel Region**: The `#pragma omp teams distribute` directive is used in C++ to parallelize the loop across teams of threads. The reduction clause is also used similarly.

5. **Loop Construct**: The `for` loop in C++ is similar to the `do` loop in Fortran, with the loop variable, start, stop, and step values specified.

6. **Output**: The `std::cout` is used for output, similar to the `print*` statement in Fortran.

### Notes:
- **OpenMP Target Directives**: The `#pragma omp target` directive is used in C++ to specify that the parallel loop should be offloaded to a target device (in this case, GPU). The `device(0)` clause specifies the first available device.
- **Compilation**: To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, with GCC, you can use the `-fopenmp` flag.

This translation maintains the original program's structure and functionality, adapting it to C++ syntax and OpenMP conventions.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will check if the final value of the variable `var` is as expected after the parallel execution.

### Fortran Unit Test

For the Fortran code, we can create a simple test by modifying the program to include a check after the parallel execution. Fortran doesn't have a built-in unit testing framework, so we'll do a basic check.

```fortran
program DRB154_missinglock3_orig_gpu_no_test
    use omp_lib
    implicit none

    integer (kind=omp_lock_kind) :: lck
    integer :: var, i, expected_value
    var = 0
    expected_value = 100

    call omp_init_lock (lck)

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute reduction(+:var)
    do i = 1, 100
        call omp_set_lock(lck)
        var = var+1
        call omp_unset_lock(lck)
    end do
    !$omp end teams distribute
    !$omp end target

    call omp_destroy_lock(lck)

    if (var == expected_value) then
        print*, "Test Passed: var = ", var
    else
        print*, "Test Failed: var = ", var
    end if
end program
```

### C++ Unit Test

For the C++ code, we can use a simple assertion to check the final value of `var`. C++ has more sophisticated testing frameworks available (like Google Test), but for simplicity, we'll use a basic check.

```cpp
#include <omp.h>
#include <iostream>
#include <cassert>

int main() {
    omp_lock_t lck;
    int var = 0;
    int expected_value = 100;

    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute reduction(+:var)
    for (int i = 1; i <= 100; ++i) {
        omp_set_lock(&lck);
        var = var + 1;
        omp_unset_lock(&lck);
    }

    omp_destroy_lock(&lck);

    assert(var == expected_value);
    std::cout << "Test Passed: var = " << var << std::endl;

    return 0;
}
```

### Compilation and Execution

- **Fortran**: Compile the Fortran code with an OpenMP-enabled Fortran compiler, such as `gfortran`:
  ```sh
  gfortran -fopenmp DRB154_missinglock3_orig_gpu_no_test.f90 -o test_fortran
  ./test_fortran
  ```

- **C++**: Compile the C++ code with an OpenMP-enabled C++ compiler, such as `g++`:
  ```sh
  g++ -fopenmp DRB154_missinglock3_orig_gpu_no.cpp -o test_cpp
  ./test_cpp
  ```

These tests will verify that the final value of `var` is indeed `100`, as expected from the parallel execution of the increment operation. If the tests pass, it means the translation is correct.
