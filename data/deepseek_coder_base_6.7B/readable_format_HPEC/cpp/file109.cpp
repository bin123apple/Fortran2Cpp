Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams num_teams(1)
        {
            #pragma omp distribute parallel for
            for (int i = 1; i <= 100; ++i) {
                #pragma omp atomic
                var += 1;
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
   - `#include <omp.h>` for OpenMP directives.

2. **Main function**:
   - Declare and initialize the variable `var` to 0.

3. **OpenMP directives**:
   - `#pragma omp target map(tofrom:var) device(0)` specifies that the variable `var` should be mapped to the target device with ID 0.
   - `#pragma omp teams num_teams(1)` specifies that only one team should be created.
   - `#pragma omp distribute parallel for` specifies that the loop should be distributed across threads and parallelized.
   - `#pragma omp atomic` ensures that the operation on `var` is atomic, preventing race conditions.

4. **Loop**:
   - The loop runs from 1 to 100, incrementing `var` by 1 in each iteration.

5. **Output**:
   - Use `std::cout` to print the value of `var`.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o DRB153_missinglock2_orig_gpu_yes DRB153_missinglock2_orig_gpu_yes.cpp
```

This command tells the compiler to enable OpenMP support (`-fopenmp`) and outputs an executable named `DRB153_missinglock2_orig_gpu_yes`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by checking the final value of the variable `var`.

### Fortran Unit Test Code

```fortran
program test_DRB153_missinglock2_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams num_teams(1)
        !$omp distribute parallel do
        do i = 1, 100
            var = var + 1
        end do
        !$omp end distribute parallel do
    !$omp end teams
    !$omp end target

    if (var == 100) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if
end program test_DRB153_missinglock2_orig_gpu_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams num_teams(1)
        {
            #pragma omp distribute parallel for
            for (int i = 1; i <= 100; ++i) {
                #pragma omp atomic
                var += 1;
            }
        }
    }

    assert(var == 100);
    std::cout << "Test Passed" << std::endl;

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The program initializes `var` to 0.
   - It then performs the same operations as the original program.
   - After the parallel loop, it checks if `var` is equal to 100 and prints "Test Passed" if true, otherwise "Test Failed".

2. **C++ Unit Test Code**:
   - The program initializes `var` to 0.
   - It then performs the same operations as the translated C++ code.
   - After the parallel loop, it uses `assert(var == 100)` to ensure `var` is equal to 100. If the assertion fails, the program will terminate with an error.
   - If the assertion passes, it prints "Test Passed".

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran unit test code, use the following commands:

```sh
gfortran -fopenmp -o test_DRB153_missinglock2_orig_gpu_yes test_DRB153_missinglock2_orig_gpu_yes.f90
./test_DRB153_missinglock2_orig_gpu_yes
```

#### C++:
To compile and run the C++ unit test code, use the following commands:

```sh
g++ -fopenmp -o test_DRB153_missinglock2_orig_gpu_yes test_DRB153_missinglock2_orig_gpu_yes.cpp
./test_DRB153_missinglock2_orig_gpu_yes
```

These commands will compile the respective test codes with OpenMP support and then execute them, verifying the correctness of the translation.
