Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

// Assuming the existence of a function f1 that takes an integer reference as an argument
void f1(int& i) {
    i = 1; // Example operation
}

int main() {
    int sum = 0;
    int i = 0;

    #pragma omp parallel reduction(+:sum) num_threads(10)
    {
        #pragma omp single
        {
            f1(i);
            sum += i;
        }
    }

    if (sum != 10) {
        std::cout << "sum = " << sum << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Function `f1` declaration**:
   - Assuming `f1` is a function that modifies the value of its integer argument.

3. **Main function**:
   - Initializes the variables `sum` and `i`.
   - Uses OpenMP to parallelize the computation.
   - Calls `f1` inside the parallel region and accumulates the result in `sum`.
   - Checks if `sum` is not equal to 10 and prints the value of `sum` if it is not.

### Notes:
- **OpenMP Pragmas**:
  - `#pragma omp parallel`: Starts a parallel region.
  - `#pragma omp reduction(+:sum)`: Specifies that `sum` should be reduced using the `+` operator.
  - `#pragma omp single`: Ensures that the enclosed block is executed by a single thread.

- **Function `f1`**:
  - It's assumed to modify the value of its argument.

- **Compilation**:
  - To compile this C++ code with OpenMP support, you might use a command like `g++ -fopenmp your_program.cpp -o your_program`.

This translation assumes that the Fortran code's functionality is equivalent to modifying the value of `i` inside the parallel region and accumulating this modification in `sum`. Adjustments might be necessary depending on the actual implementation of `f1` and the specific requirements of the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by ensuring that the sum is indeed 10.

### Fortran Unit Test Code

```fortran
program test_DRB074_flush_orig_yes
    use omp_lib
    implicit none

    integer :: i, sum
    i = 0
    sum =  0

    !$omp parallel reduction(+:sum) num_threads(10)
    call f1(i)
    sum = sum+i
    !$omp end parallel

    if (sum /= 10) then
        print*,'Test failed: sum =',sum
    else
        print*,'Test passed: sum =',sum
    end if
end program test_DRB074_flush_orig_yes

subroutine f1(i)
    integer, intent(inout) :: i
    i = 1
end subroutine f1
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

void f1(int& i) {
    i = 1; // Example operation
}

int main() {
    int sum = 0;
    int i = 0;

    #pragma omp parallel reduction(+:sum) num_threads(10)
    {
        #pragma omp single
        {
            f1(i);
            sum += i;
        }
    }

    if (sum != 10) {
        std::cout << "Test failed: sum = " << sum << std::endl;
    } else {
        std::cout << "Test passed: sum = " << sum << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `f1` subroutine is defined within the same program for simplicity.
   - The parallel region accumulates the value of `i` in `sum`.
   - The test checks if `sum` is equal to 10 and prints the result.

2. **C++ Unit Test Code**:
   - The `f1` function modifies the value of its integer argument.
   - The parallel region accumulates the value of `i` in `sum`.
   - The test checks if `sum` is equal to 10 and prints the result.

### Compilation and Execution:

- **Fortran**:
  - Compile the Fortran code with OpenMP support using a command like `gfortran -fopenmp test_DRB074_flush_orig_yes.f90 -o test_DRB074_flush_orig_yes`.
  - Run the executable: `./test_DRB074_flush_orig_yes`.

- **C++**:
  - Compile the C++ code with OpenMP support using a command like `g++ -fopenmp test_DRB074_flush_orig_yes.cpp -o test_DRB074_flush_orig_yes`.
  - Run the executable: `./test_DRB074_flush_orig_yes`.

These unit tests will verify that the sum is indeed 10, ensuring the correctness of the translation.
