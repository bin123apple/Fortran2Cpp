To translate the given Fortran code to C++, we need to understand the structure and the purpose of each Fortran statement and then find the equivalent or similar constructs in C++. The Fortran code uses OpenMP directives for parallelism, which has a direct counterpart in C++ with the OpenMP API. Here's how the Fortran code could be translated to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    // Equivalent to the Fortran !$omp target map(tofrom:var) device(0)
    // The 'target' directive in Fortran is used for offloading computations to accelerators,
    // but the exact translation to C++ would depend on the specific hardware and setup.
    // Here, we're focusing on the parallelism aspect, so we'll use the 'parallel' directive.
    #pragma omp target parallel
    {
        // Equivalent to the Fortran !$omp teams distribute parallel do
        #pragma omp teams distribute parallel for
        for (int i = 0; i <= 100; ++i) {
            // Equivalent to the Fortran !$omp atomic
            #pragma omp atomic
            {
                var += 1;
            }
            // Equivalent to the Fortran !$omp atomic
            #pragma omp atomic
            {
                var -= 2;
            }
        }
    }

    std::cout << var << std::endl;

    return 0;
}
```

### Key Points:

1. **OpenMP Directives**: The `#pragma omp` directives in C++ are used to parallelize the code similar to the `!$omp` directives in Fortran.

2. **Variable Declaration and Initialization**: The variable `var` is declared and initialized similarly in C++.

3. **Parallel Loop**: The `for` loop is parallelized using `#pragma omp teams distribute parallel for`, which is a combination of `teams` and `parallel for` directives.

4. **Atomic Operations**: The `#pragma omp atomic` directive is used to ensure that the operations on `var` are atomic, similar to the `!$omp atomic` directive in Fortran.

5. **Output**: The result is printed to the standard output using `std::cout`.

### Notes:
- The `#pragma omp target parallel` directive is used to parallelize the loop across threads or devices, but it's not a direct translation of the `!$omp target` directive due to differences in hardware and setup. In a real-world scenario, you might need to adjust this part based on your specific computing environment.
- Ensure that your compiler supports OpenMP and that it's enabled. For GCC and Clang, you can enable OpenMP with the `-fopenmp` flag.
- This translation assumes a basic understanding of OpenMP and its usage in Fortran, as well as a general familiarity with compiling and running C++ code with OpenMP support.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking if the final value of `var` is as expected after the parallel execution. For simplicity, we'll assume that the expected result after the parallel execution is `0`, as the operations on `var` are supposed to cancel each other out.

### Fortran Unit Test

For Fortran, we can write a simple test program that includes the original code and checks the final value of `var`.

```fortran
program test_DRB147_critical1_orig_gpu_no
    use omp_lib
    implicit none

    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
        do i = 0, 100
            !$omp atomic
            var = var+1
            !$omp atomic
            var = var-2
        end do
    !$omp end teams distribute parallel do
    !$omp end target

    if (var == 0) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if
end program test_DRB147_critical1_orig_gpu_no
```

### C++ Unit Test

For C++, we can use a simple test function that includes the translated code and checks the final value of `var`.

```cpp
#include <iostream>
#include <omp.h>

bool test_DRB147_critical1_orig_gpu_no() {
    int var = 0;

    #pragma omp target parallel
    {
        #pragma omp teams distribute parallel for
        for (int i = 0; i <= 100; ++i) {
            #pragma omp atomic
            {
                var += 1;
            }
            #pragma omp atomic
            {
                var -= 2;
            }
        }
    }

    return var == 0;
}

int main() {
    if (test_DRB147_critical1_orig_gpu_no()) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation

- **Fortran Test Program**: The test program includes the original code and checks if `var` equals `0` after the parallel execution. If `var` is `0`, it prints "Test Passed"; otherwise, it prints "Test Failed".

- **C++ Test Function**: The test function includes the translated code and returns `true` if `var` equals `0` after the parallel execution. The main function then prints "Test Passed" if the test function returns `true`, or "Test Failed" otherwise.

### Running the Tests

To run the Fortran test, you'll need a Fortran compiler that supports OpenMP, such as GCC or Clang. Compile and run the Fortran test program as follows:

```sh
gfortran -fopenmp test_DRB147_critical1_orig_gpu_no.f90 -o test_DRB147_critical1_orig_gpu_no
./test_DRB147_critical1_orig_gpu_no
```

To run the C++ test, you'll need a C++ compiler that supports OpenMP. Compile and run the C++ test program as follows:

```sh
g++ -fopenmp test_DRB147_critical1_orig_gpu_no.cpp -o test_DRB147_critical1_orig_gpu_no
./test_DRB147_critical1_orig_gpu_no
```

Both tests should print "Test Passed" if the translation is correct.
