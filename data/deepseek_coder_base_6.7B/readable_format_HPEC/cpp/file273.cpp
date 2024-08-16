Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute
        {
            for (int i = 1; i <= 100; ++i) {
                #pragma omp atomic update
                {
                    var = var + 1;
                }
            }
        }
    }

    std::cout << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP support.

2. **Main function**:
   - Initializes the variable `var` to 0.

3. **OpenMP directives**:
   - `#pragma omp target map(tofrom:var) device(0)` specifies that the variable `var` should be mapped to the target device with ID 0.
   - `#pragma omp teams distribute` specifies that the loop should be distributed across teams of threads.
   - `#pragma omp atomic update` ensures that the update of `var` is atomic.

4. **Loop**:
   - Iterates from 1 to 100, updating `var` with an atomic operation.

5. **Output**:
   - Prints the value of `var` to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command like:
```sh
g++ -fopenmp your_program.cpp -o your_program
```

This command tells the compiler to enable OpenMP support (`-fopenmp`) and then compiles the source code into an executable named `your_program`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB146_atomicupdate_orig_gpu_no
    use omp_lib
    implicit none

    integer :: var, i, errors
    var = 0
    errors = 0

    !$omp target map(tofrom:var) device(0)
        !$omp teams distribute
        do i = 1, 100
            !$omp atomic update
            var = var + 1
            !$omp end atomic
        end do
        !$omp end teams distribute
    !$omp end target

    if (var /= 100) then
        print*, "Test failed: var = ", var
        errors = errors + 1
    end if

    if (errors == 0) then
        print*, "All tests passed."
    else
        print*, "Number of errors: ", errors
    end if
end program test_DRB146_atomicupdate_orig_gpu_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int errors = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute
        {
            for (int i = 1; i <= 100; ++i) {
                #pragma omp atomic update
                {
                    var = var + 1;
                }
            }
        }
    }

    if (var != 100) {
        std::cerr << "Test failed: var = " << var << std::endl;
        errors++;
    }

    if (errors == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Number of errors: " << errors << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - Initializes the variable `var` to 0.
   - Performs the atomic update operation as in the original code.
   - Checks if `var` equals 100 and prints the result of the test.

2. **C++ Unit Test Code**:
   - Initializes the variable `var` to 0.
   - Performs the atomic update operation as in the translated code.
   - Checks if `var` equals 100 and prints the result of the test.

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran unit test code, use:
```sh
gfortran -fopenmp test_DRB146_atomicupdate_orig_gpu_no.f90 -o test_DRB146_atomicupdate_orig_gpu_no
./test_DRB146_atomicupdate_orig_gpu_no
```

#### C++:
To compile and run the C++ unit test code, use:
```sh
g++ -fopenmp test_DRB146_atomicupdate_orig_gpu_no.cpp -o test_DRB146_atomicupdate_orig_gpu_no
./test_DRB146_atomicupdate_orig_gpu_no
```

These commands will compile the respective unit test codes with OpenMP support and then execute them, printing the results of the test to the console.
