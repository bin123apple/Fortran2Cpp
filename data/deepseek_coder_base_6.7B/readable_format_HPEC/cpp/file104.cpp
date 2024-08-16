Certainly! Below is the translated version of the provided Fortran code to C++ using OpenMP for parallel sections.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            i = 1;
        }
        #pragma omp section
        {
            i = 2;
        }
    }

    std::cout << "i=" << i << std::endl;

    return 0;
}
```

### Explanation:
1. **OpenMP Pragmas**: The `#pragma omp parallel sections` and `#pragma omp section` directives are used to define parallel sections, similar to the `!$omp parallel sections` and `!$omp section` in Fortran.

2. **Variable Initialization**: The variable `i` is initialized to 0.

3. **Parallel Sections**: Inside the parallel sections, two sections are defined using `#pragma omp section`. Each section modifies the value of `i` to 1 and 2, respectively. Since the sections are executed in parallel, the final value of `i` should be 2, demonstrating that the second section's code was executed.

4. **Output**: The value of `i` is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp your_program.cpp -o your_program
```

Replace `your_program.cpp` with the name of your C++ source file.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify that the variable `i` is correctly set to 2, demonstrating that the parallel sections work as intended.

### Fortran Unit Test Code

```fortran
program test_DRB023_sections1_orig_yes
    use omp_lib
    implicit none

    integer :: i
    i = 0

    !$omp parallel sections
    !$omp section
    i=1
    !$omp section
    i=2
    !$omp end parallel sections

    if (i == 2) then
        print *, "Test passed: i=", i
    else
        print *, "Test failed: i=", i
    end if
end program test_DRB023_sections1_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            i = 1;
        }
        #pragma omp section
        {
            i = 2;
        }
    }

    if (i == 2) {
        std::cout << "Test passed: i=" << i << std::endl;
    } else {
        std::cout << "Test failed: i=" << i << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The program initializes `i` to 0.
   - It uses OpenMP parallel sections to set `i` to 1 and 2, but since the second section is executed, `i` should end up as 2.
   - It checks if `i` is 2 and prints the result of the test.

2. **C++ Unit Test Code**:
   - The program does the same as the Fortran code, initializing `i` to 0.
   - It uses OpenMP parallel sections to set `i` to 1 and 2, but since the second section is executed, `i` should end up as 2.
   - It checks if `i` is 2 and prints the result of the test.

### Compilation and Execution:

- **Fortran**:
  - Compile the Fortran code with OpenMP support:
    ```sh
    gfortran -fopenmp test_DRB023_sections1_orig_yes.f90 -o test_DRB023_sections1_orig_yes
    ```
  - Run the executable:
    ```sh
    ./test_DRB023_sections1_orig_yes
    ```

- **C++**:
  - Compile the C++ code with OpenMP support:
    ```sh
    g++ -fopenmp test_DRB023_sections1_orig_yes.cpp -o test_DRB023_sections1_orig_yes
    ```
  - Run the executable:
    ```sh
    ./test_DRB023_sections1_orig_yes
    ```

Both programs should output "Test passed: i=2" if the parallel sections work correctly.
