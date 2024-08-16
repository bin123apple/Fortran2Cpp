To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as variable declaration, loop syntax, and OpenMP directives. The Fortran code uses OpenMP for parallelization, and it includes a critical section to ensure mutual exclusion. Here's how you can translate the given Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

// Assuming the existence of a global variable sum1 similar to the Fortran code
int sum1 = 0;

int main() {
    const int len = 1000;
    int sum = 0;

    // OpenMP parallel region with copyin of sum0
    #pragma omp parallel reduction(+:sum)
    {
        int sum0 = 0; // Thread private variable
        #pragma omp for
        for (int i = 1; i <= len; ++i) {
            sum0 += i;
        }
        // Critical section to ensure mutual exclusion
        #pragma omp critical
        {
            sum += sum0;
        }
    }

    // Serial loop to update sum1
    for (int i = 1; i <= len; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
```

Key Points in the Translation:

1. **Variable Declarations**: In C++, variables can be declared at the point of their first use. Global variables (`sum1`) are declared at the beginning of the file. Local variables (`sum0`) are declared within the parallel region.

2. **OpenMP Directives**: The OpenMP directives (`#pragma omp`) are used similarly in C++. The `reduction` clause is used to safely accumulate `sum` across threads.

3. **Loop Syntax**: The C++ `for` loop syntax is similar to the Fortran `do` loop, but the loop control variable `i` is declared and used within the loop.

4. **Printing**: The `std::cout` is used for output in C++, similar to the `print*` statement in Fortran.

5. **Functionality**: The parallel region in C++ uses OpenMP to parallelize the loop that computes `sum0`, and a critical section ensures mutual exclusion for updating `sum`. The serial loop (after the parallel region) updates `sum1` in a similar manner.

Remember to compile this C++ code with OpenMP support enabled. For example, if you're using g++, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the original Fortran code and the translated C++ code involves checking the correctness of the sum calculation. However, it's important to note that the original Fortran code and the translated C++ code are designed to perform different operations due to differences in how they handle parallelism and shared variables. For the purpose of these unit tests, we'll focus on testing the sum calculation logic, which is the core functionality of both programs.

### Fortran Unit Test

For the Fortran code, we'll create a simple test that checks if the sum calculated by the program matches the expected result. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic check and print a message based on the result.

```fortran
program test_DRB091_threadprivate2_orig_no
    use omp_lib
    use DRB091
    implicit none

    integer :: len, i, sum, expected_sum
    len = 1000
    sum = 0
    expected_sum = 500500 ! Expected sum for the first 1000 natural numbers

    !$omp parallel copyin(sum0)
        !$omp do
        do i = 1, len
            sum0 = sum0 + i
        end do
        !$omp end do
        !$omp critical
        sum = sum + sum0
        !$omp end critical
    !$omp end parallel

    do i = 1, len
        sum1 = sum1 + i
    end do

    if (sum == expected_sum) then
        print *, "Test Passed: sum =", sum
    else
        print *, "Test Failed: sum =", sum, "Expected:", expected_sum
    end if

end program test_DRB091_threadprivate2_orig_no
```

### C++ Unit Test

For the C++ code, we can use a simple assertion to check if the sum calculated by the program matches the expected result. C++ doesn't include a built-in unit testing framework, but for a simple case like this, we can use `assert` from the `<cassert>` header. For more complex testing, frameworks like Google Test are recommended.

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int sum1 = 0;

int main() {
    const int len = 1000;
    int sum = 0;
    const int expected_sum = 500500; // Expected sum for the first 1000 natural numbers

    #pragma omp parallel reduction(+:sum)
    {
        int sum0 = 0;
        #pragma omp for
        for (int i = 1; i <= len; ++i) {
            sum0 += i;
        }
        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (int i = 1; i <= len; ++i) {
        sum1 += i;
    }

    assert(sum == expected_sum);
    std::cout << "Test Passed: sum = " << sum << std::endl;

    return 0;
}
```

### Compilation and Execution

- **Fortran**: Compile the Fortran test program with OpenMP support. For example, using `gfortran`:
  ```sh
  gfortran -fopenmp test_DRB091_threadprivate2_orig_no.f90 -o test_DRB091_threadprivate2_orig_no
  ./test_DRB091_threadprivate2_orig_no
  ```

- **C++**: Compile the C++ test program with OpenMP support. For example, using `g++`:
  ```sh
  g++ -fopenmp test_DRB091_threadprivate2_orig_no.cpp -o test_DRB091_threadprivate2_orig_no
  ./test_DRB091_threadprivate2_orig_no
  ```

These tests will verify that the sum calculation logic in both the Fortran and C++ versions behaves as expected. If the sums match, the tests will pass, and a message will be printed indicating the sum value.
