Certainly! Here is the equivalent C++ code for the provided Fortran code. Note that OpenMP directives in Fortran and C++ are slightly different, and the syntax for parallel loops is also slightly different. I'll use OpenMP in C++ as well.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int x = 0;

    #pragma omp parallel for ordered
    for (int i = 1; i <= 100; ++i) {
        #pragma omp ordered
        {
            x = x + 1;
        }
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**: We include `<iostream>` for input/output operations and `<omp.h>` for OpenMP functionalities.
2. **Main function**: The main function initializes the variable `x` to 0 and then uses OpenMP to parallelize the loop.
3. **Parallel for loop**: The `#pragma omp parallel for ordered` directive is used to parallelize the loop. The `ordered` clause ensures that the operations within the loop are executed in order.
4. **Loop body**: Inside the loop, another `#pragma omp ordered` block ensures that the operation `x = x + 1` is executed in order.
5. **Output**: Finally, we print the value of `x` to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command like the following (assuming you have a C++ compiler that supports OpenMP, such as `g++`):

```sh
g++ -fopenmp -o DRB109_orderedmissing_orig_yes DRB109_orderedmissing_orig_yes.cpp
```

This command compiles the C++ code and enables OpenMP support, generating an executable named `DRB109_orderedmissing_orig_yes`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by checking the final value of `x`.

### Fortran Unit Test Code

```fortran
program test_DRB109_orderedmissing_orig_yes
    use omp_lib
    implicit none

    integer :: x, i

    x = 0
    !$omp parallel do ordered
    do i = 1, 100
        !$omp ordered
        x = x + 1
        !$omp end ordered
    end do
    !$omp end parallel do

    if (x == 100) then
        print *, 'Test passed: x =', x
    else
        print *, 'Test failed: x =', x
    end if

end program test_DRB109_orderedmissing_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int x = 0;

    #pragma omp parallel for ordered
    for (int i = 1; i <= 100; ++i) {
        #pragma omp ordered
        {
            x = x + 1;
        }
    }

    if (x == 100) {
        std::cout << "Test passed: x = " << x << std::endl;
    } else {
        std::cout << "Test failed: x = " << x << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**: This code initializes `x` to 0 and then uses OpenMP to parallelize the loop. It checks if `x` is equal to 100 after the loop completes, indicating that all iterations were executed.
2. **C++ Unit Test Code**: This code does the same as the Fortran code, checking if `x` is equal to 100 after the loop completes.

### Compilation and Execution:
- **Fortran**: Use a Fortran compiler that supports OpenMP, such as `gfortran`:
  ```sh
  gfortran -fopenmp -o test_DRB109_orderedmissing_orig_yes test_DRB109_orderedmissing_orig_yes.f90
  ./test_DRB109_orderedmissing_orig_yes
  ```
- **C++**: Use a C++ compiler that supports OpenMP, such as `g++`:
  ```sh
  g++ -fopenmp -o test_DRB109_orderedmissing_orig_yes test_DRB109_orderedmissing_orig_yes.cpp
  ./test_DRB109_orderedmissing_orig_yes
  ```

Both programs should output "Test passed: x = 100" if the translation is correct.
