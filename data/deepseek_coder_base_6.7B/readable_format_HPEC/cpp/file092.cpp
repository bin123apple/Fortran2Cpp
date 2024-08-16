Certainly! Below is the equivalent C++ code for the provided Fortran code. This C++ code uses OpenMP for parallelism and atomic operations. Note that C++ uses different syntax and conventions compared to Fortran, especially regarding the inclusion of the OpenMP library and the syntax for parallel and atomic blocks.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int a = 0;

    #pragma omp parallel
    {
        #pragma omp atomic
        a = a + 1;
    }

    std::cout << "a = " << a << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The main function initializes the variable `a` to 0.
3. **Parallel Block**: The `#pragma omp parallel` directive is used to start a parallel block.
4. **Atomic Block**: The `#pragma omp atomic` directive is used to ensure that the operation on `a` is atomic. This prevents race conditions from occurring.
5. **Increment Operation**: Inside the atomic block, `a` is incremented by 1.
6. **Output**: The final value of `a` is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp -o atomic_example atomic_example.cpp
```

This will compile the C++ code with OpenMP support and produce an executable named `atomic_example`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the atomic operation by running the code multiple times and checking if the value of `a` is always 1.

### Fortran Unit Test Code

```fortran
program DRB108_atomic_orig_no_test
    use omp_lib
    implicit none

    integer :: a, i, errors
    errors = 0

    !$omp parallel private(i)
    !$omp do
    do i = 1, 1000
        a = 0
        !$omp atomic
        a = a + 1
        !$omp end atomic
        if (a /= 1) then
            errors = errors + 1
        end if
    end do
    !$omp end do
    !$omp end parallel

    if (errors == 0) then
        print *, "Test Passed: a is always 1."
    else
        print *, "Test Failed: a is not always 1."
    end if
end program DRB108_atomic_orig_no_test
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int errors = 0;

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 1000; ++i) {
            int a = 0;
            #pragma omp atomic
            a = a + 1;
            if (a != 1) {
                #pragma omp atomic
                errors = errors + 1;
            }
        }
    }

    if (errors == 0) {
        std::cout << "Test Passed: a is always 1." << std::endl;
    } else {
        std::cout << "Test Failed: a is not always 1." << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
   - The `DRB108_atomic_orig_no_test` program initializes `a` to 0 and performs the atomic operation 1000 times.
   - If `a` is not equal to 1 after the atomic operation, it increments the `errors` variable.
   - After the parallel loop, it checks if `errors` is 0. If so, it prints that the test passed; otherwise, it prints that the test failed.

2. **C++ Unit Test**:
   - The main function initializes `errors` to 0.
   - It uses OpenMP to parallelize the loop and perform the atomic operation 1000 times.
   - If `a` is not equal to 1 after the atomic operation, it increments the `errors` variable.
   - After the parallel loop, it checks if `errors` is 0. If so, it prints that the test passed; otherwise, it prints that the test failed.

### Compilation and Execution:

- **Fortran**:
  ```sh
  gfortran -fopenmp -o DRB108_atomic_orig_no_test DRB108_atomic_orig_no_test.f90
  ./DRB108_atomic_orig_no_test
  ```

- **C++**:
  ```sh
  g++ -fopenmp -o atomic_example_test atomic_example_test.cpp
  ./atomic_example_test
  ```

These unit tests will help verify that the atomic operation in both the Fortran and C++ code behaves correctly by ensuring that `a` is always incremented by 1.
