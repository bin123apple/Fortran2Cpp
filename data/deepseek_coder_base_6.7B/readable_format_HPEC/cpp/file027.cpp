Certainly! Below is the translated Fortran code to C++:

```cpp
#include <omp.h>
#include <iostream>

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
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The main function starts with initializing the variable `x` to 0.
3. **Parallel Loop**: The `#pragma omp parallel for ordered` directive is used to parallelize the loop with ordered execution.
4. **Loop Body**: The loop runs from 1 to 100, and within each iteration, the `#pragma omp ordered` block ensures that the operations within it are executed in order.
5. **Incrementing x**: Inside the ordered block, `x` is incremented by 1.
6. **Printing x**: After the parallel loop, `x` is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o DRB110_ordered_orig_no DRB110_ordered_orig_no.cpp
```

This command compiles the C++ code and enables OpenMP support, generating an executable named `DRB110_ordered_orig_no`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB110_ordered_orig_no
    use omp_lib
    implicit none

    integer :: x, i
    integer :: expected_value
    logical :: test_passed

    x = 0
    expected_value = 100

    !$omp parallel do ordered
    do i = 1, 100
        !$omp ordered
        x = x + 1
        !$omp end ordered
    end do
    !$omp end parallel do

    test_passed = (x == expected_value)
    if (test_passed) then
        print *, 'Test passed: x =', x
    else
        print *, 'Test failed: x =', x
    end if
end program test_DRB110_ordered_orig_no
```

### C++ Unit Test Code

```cpp
#include <omp.h>
#include <iostream>
#include <cassert>

int main() {
    int x = 0;
    int expected_value = 100;

    #pragma omp parallel for ordered
    for (int i = 1; i <= 100; ++i) {
        #pragma omp ordered
        {
            x = x + 1;
        }
    }

    assert(x == expected_value);
    std::cout << "Test passed: x = " << x << std::endl;

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
   - The program initializes `x` to 0.
   - It then performs the parallel loop with ordered execution, incrementing `x` by 1 in each iteration.
   - After the loop, it checks if `x` equals the expected value (100) and prints the result of the test.

2. **C++ Unit Test Code**:
   - The program initializes `x` to 0.
   - It then performs the parallel loop with ordered execution, incrementing `x` by 1 in each iteration.
   - After the loop, it uses the `assert` function to ensure that `x` equals the expected value (100).
   - If the assertion passes, it prints the result of the test.

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran unit test code, use the following commands:

```sh
gfortran -fopenmp -o test_DRB110_ordered_orig_no test_DRB110_ordered_orig_no.f90
./test_DRB110_ordered_orig_no
```

#### C++:
To compile and run the C++ unit test code, use the following commands:

```sh
g++ -fopenmp -o test_DRB110_ordered_orig_no test_DRB110_ordered_orig_no.cpp
./test_DRB110_ordered_orig_no
```

These commands will compile and execute the respective unit tests, verifying that the translation from Fortran to C++ is correct.
