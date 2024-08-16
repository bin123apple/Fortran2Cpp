Certainly! Below is the translation of the provided Fortran code to C++ using OpenMP for parallelism. Note that in C++, OpenMP directives are used in a similar way as in Fortran, but the syntax is slightly different.

Fortran code:
```fortran
program DRB125_single_orig_no
    use omp_lib
    implicit none

    integer :: init, local

    !$omp parallel shared(init) private(local)
        !$omp single
        init = 10
        !$omp end single
        local = init
    !$omp end parallel
end program
```

C++ translation:
```cpp
#include <omp.h>
#include <iostream>

int main() {
    int init, local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp single
        {
            init = 10;
        }
        local = init;
    }

    return 0;
}
```

### Explanation:
1. **Include OpenMP header**: `#include <omp.h>` is used to include the OpenMP library functions.
2. **Main function**: The `main` function in C++ serves the same purpose as the `program` block in Fortran.
3. **Variable declarations**: The variable types are declared similarly in both languages.
4. **OpenMP directives**:
   - `#pragma omp parallel` is used to start a parallel region, similar to `!$omp parallel` in Fortran.
   - `#pragma omp single` is used to ensure that only one thread executes the enclosed code, similar to `!$omp single`.
   - `shared` and `private` clauses are used to specify shared and private variables, similar to the Fortran version.
5. **Assignments and operations**: The assignments and operations are translated directly from Fortran to C++.

Make sure you compile the C++ code with OpenMP support enabled. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify that the `init` variable is correctly set to 10 in both cases.

### Fortran Unit Test

Fortran code (`DRB125_single_orig_no_test.f90`):
```fortran
program DRB125_single_orig_no_test
    use omp_lib
    implicit none

    integer :: init, local

    !$omp parallel shared(init) private(local)
        !$omp single
        init = 10
        !$omp end single
        local = init
    !$omp end parallel

    ! Check the value of init
    if (init == 10) then
        print *, "Test passed: init is 10"
    else
        print *, "Test failed: init is not 10"
    end if
end program
```

### C++ Unit Test

C++ code (`DRB125_single_orig_no_test.cpp`):
```cpp
#include <omp.h>
#include <iostream>

int main() {
    int init, local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp single
        {
            init = 10;
        }
        local = init;
    }

    // Check the value of init
    if (init == 10) {
        std::cout << "Test passed: init is 10" << std::endl;
    } else {
        std::cout << "Test failed: init is not 10" << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

#### Fortran
To compile and run the Fortran unit test, use the following commands (assuming you have a Fortran compiler like `gfortran`):

```sh
gfortran -fopenmp DRB125_single_orig_no_test.f90 -o DRB125_single_orig_no_test
./DRB125_single_orig_no_test
```

#### C++
To compile and run the C++ unit test, use the following commands (assuming you have a C++ compiler like `g++`):

```sh
g++ -fopenmp DRB125_single_orig_no_test.cpp -o DRB125_single_orig_no_test
./DRB125_single_orig_no_test
```

### Expected Output

For both the Fortran and C++ unit tests, the expected output should be:

```
Test passed: init is 10
```

This output verifies that the `init` variable is correctly set to 10 in both the original Fortran code and the translated C++ code, demonstrating the correctness of the translation.
