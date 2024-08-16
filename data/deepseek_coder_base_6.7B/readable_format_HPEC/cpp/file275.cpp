Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for
        for (int i = 1; i <= 100; ++i) {
            #pragma omp critical(addlock)
            {
                var = var + 1;
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
   - `#include <omp.h>` for OpenMP functionalities.

2. **Main function**:
   - Declare and initialize the variable `var` to 0.

3. **OpenMP directives**:
   - `#pragma omp target map(tofrom:var) device(0)` specifies that the variable `var` should be mapped to and from the target device with ID 0.
   - `#pragma omp teams distribute parallel for` parallelizes the loop across teams, distributing the iterations among the threads.
   - `#pragma omp critical(addlock)` ensures mutual exclusion for the critical section.

4. **Loop**:
   - Iterate from 1 to 100, incrementing `var` in a critical section.

5. **Output**:
   - Print the value of `var` to the standard output.

This C++ code should behave similarly to the original Fortran code, executing the critical section in a thread-safe manner across multiple threads.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify that the translation is correct by ensuring that the final value of `var` is 100.

### Fortran Unit Test Code

```fortran
program test_DRB148_critical1_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
    do i = 1, 100
        !$omp critical(addlock)
        var = var + 1
        !$omp end critical(addlock)
    end do
    !$omp end teams distribute parallel do
    !$omp end target

    if (var == 100) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if
end program test_DRB148_critical1_orig_gpu_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for
        for (int i = 1; i <= 100; ++i) {
            #pragma omp critical(addlock)
            {
                var = var + 1;
            }
        }
    }

    if (var == 100) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The program initializes `var` to 0.
   - It then performs the same operations as the original program, incrementing `var` in a critical section.
   - Finally, it checks if `var` is equal to 100 and prints "Test Passed" if true, otherwise "Test Failed".

2. **C++ Unit Test Code**:
   - The program follows a similar structure to the Fortran code, initializing `var` to 0.
   - It parallelizes the loop using OpenMP, incrementing `var` in a critical section.
   - It checks if `var` is equal to 100 and prints "Test Passed" if true, otherwise "Test Failed".

### Running the Tests:

1. **Fortran**:
   - Compile the Fortran code with an OpenMP-supporting Fortran compiler, e.g., `gfortran`:
     ```sh
     gfortran -fopenmp test_DRB148_critical1_orig_gpu_yes.f90 -o test_DRB148_critical1_orig_gpu_yes
     ```
   - Run the executable:
     ```sh
     ./test_DRB148_critical1_orig_gpu_yes
     ```

2. **C++**:
   - Compile the C++ code with an OpenMP-supporting C++ compiler, e.g., `g++`:
     ```sh
     g++ -fopenmp test_DRB148_critical1_orig_gpu_yes.cpp -o test_DRB148_critical1_orig_gpu_yes
     ```
   - Run the executable:
     ```sh
     ./test_DRB148_critical1_orig_gpu_yes
     ```

Both tests should output "Test Passed" if the translation is correct.
